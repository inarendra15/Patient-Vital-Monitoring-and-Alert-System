#include "../include/ReportManager.h"

#include <fstream>
#include <iomanip>
#include <iostream>



// ======================================================
// CONSTRUCTOR
// ======================================================

ReportManager::ReportManager(

    const PatientManager& pm,

    const VitalManager& vm,

    const AnalyticsManager& am,

    const EmergencyManager& em

)

    :

    patientManager(pm),

    vitalManager(vm),

    analyticsManager(am),

    emergencyManager(em)

{

}
// ======================================================
// GENERATE PATIENT REPORT
// ======================================================

bool ReportManager::generatePatientReport(

    int patientId

) const {

    // -----------------------------------------
    // Find patient
    // -----------------------------------------

    const Patient* patient =
        patientManager.searchPatient(patientId);

    if (patient == nullptr) {

        std::cout
            << "\nPatient not found.\n";

        return false;
    }

    // -----------------------------------------
    // Latest vital
    // -----------------------------------------

    const VitalSigns* vital =
        vitalManager.getLatestReadingForPatient(
            patientId
        );

    if (vital == nullptr) {

        std::cout
            << "\nNo vital records available.\n";

        return false;
    }

    // -----------------------------------------
    // Create filename
    // -----------------------------------------

    std::string filename =
        "reports/Patient_" +
        std::to_string(patientId) +
        "_Report.txt";

    std::ofstream report(filename);

    if (!report.is_open()) {

        std::cout
            << "\nUnable to create report.\n";

        return false;
    }

    int score =
        analyticsManager.calculateHealthScore(
            *vital
        );

    std::string status =
        analyticsManager.calculateStatus(
            score
        );

    report
        << "====================================================\n";

    report
        << "      PATIENT VITAL MONITORING REPORT\n";

    report
        << "====================================================\n\n";

    report
        << "Patient Information\n";

    report
        << "--------------------\n";

    report
        << "ID      : "
        << patient->getPatientId()
        << "\n";

    report
        << "Name    : "
        << patient->getName()
        << "\n";

    report
        << "Age     : "
        << patient->getAge()
        << "\n";

    report
        << "Gender  : "
        << patient->getGender()
        << "\n\n";

    report
        << "--------------------------------------------\n";

    report
        << "LATEST VITALS\n";

    report
        << "--------------------------------------------\n";

    report
        << "Heart Rate         : "
        << vital->getHeartRate()
        << " bpm\n";

    report
        << "SpO2               : "
        << vital->getSpO2()
        << " %\n";

    report
        << "Temperature        : "
        << vital->getTemperature()
        << " C\n";

    report
        << "Blood Pressure     : "
        << vital->getSystolicBP()
        << "/"
        << vital->getDiastolicBP()
        << " mmHg\n";

    report
        << "Respiratory Rate   : "
        << vital->getRespiratoryRate()
        << " breaths/min\n";

    report
        << "Timestamp          : "
        << vital->getTimestamp()
        << "\n\n";

    report
        << "--------------------------------------------\n";

    report
        << "HEALTH ANALYSIS\n";

    report
        << "--------------------------------------------\n";

    report
        << "Health Score : "
        << score
        << "\n";

    report
        << "Status       : "
        << status
        << "\n\n";

    report
        << "Report Generated Successfully\n";

    report
        << "====================================================\n";

    report.close();

    std::cout
        << "\nReport generated successfully.\n";

    std::cout
        << filename
        << "\n";

    return true;
}
#include "../include/AnalyticsManager.h"

#include <iostream>
#include <iomanip>



// ============================================================
// CONSTRUCTOR
// ============================================================

AnalyticsManager::AnalyticsManager(
    const VitalManager& vm,
    const PatientManager& pm
)
    : vitalManager(vm),
      patientManager(pm)
{

}



// ============================================================
// PHASE 6.1
// OVERALL HOSPITAL ANALYTICS
// ============================================================

void AnalyticsManager::displayDashboard() const {

    const auto& history =
        vitalManager.getAllVitalHistory();

    std::cout
        << "\n=========================================\n"
        << "      PATIENT ANALYTICS DASHBOARD\n"
        << "=========================================\n";

    if (history.empty()) {

        std::cout
            << "No vital readings available.\n";

        return;
    }

    double totalHeartRate = 0;
    double totalSpo2 = 0;
    double totalTemperature = 0;
    double totalSystolic = 0;
    double totalDiastolic = 0;
    double totalRespRate = 0;

    int highestHeartRate =
        history.front().getHeartRate();

    int lowestSpo2 =
        history.front().getSpO2();

    for (const VitalSigns& vital : history) {

        totalHeartRate += vital.getHeartRate();

        totalSpo2 += vital.getSpO2();

        totalTemperature +=
            vital.getTemperature();

        totalSystolic +=
            vital.getSystolicBP();

        totalDiastolic +=
            vital.getDiastolicBP();

        totalRespRate +=
            vital.getRespiratoryRate();

        if (vital.getHeartRate() >
            highestHeartRate)
            highestHeartRate =
                vital.getHeartRate();

        if (vital.getSpO2() <
            lowestSpo2)
            lowestSpo2 =
                vital.getSpO2();
    }

    int total =
        static_cast<int>(history.size());

    std::cout
        << std::fixed
        << std::setprecision(2);

    std::cout
        << "Total Vital Readings      : "
        << total

        << "\nAverage Heart Rate       : "
        << totalHeartRate / total
        << " bpm"

        << "\nAverage SpO2             : "
        << totalSpo2 / total
        << " %"

        << "\nAverage Temperature      : "
        << totalTemperature / total
        << " C"

        << "\nAverage Systolic BP      : "
        << totalSystolic / total
        << " mmHg"

        << "\nAverage Diastolic BP     : "
        << totalDiastolic / total
        << " mmHg"

        << "\nAverage Respiratory Rate : "
        << totalRespRate / total
        << " breaths/min"

        << "\nHighest Heart Rate       : "
        << highestHeartRate
        << " bpm"

        << "\nLowest SpO2              : "
        << lowestSpo2
        << " %"

        << "\n=========================================\n";
}



// ============================================================
// HEALTH SCORE
// ============================================================

int AnalyticsManager::calculateHealthScore(
    const VitalSigns& vital
) const {

    int score = 100;

    if (vital.getHeartRate() < 60 ||
        vital.getHeartRate() > 100)
        score -= 15;

    if (vital.getSpO2() < 90)
        score -= 30;

    if (vital.getTemperature() < 36 ||
        vital.getTemperature() > 38)
        score -= 15;

    if (vital.getSystolicBP() < 90 ||
        vital.getSystolicBP() > 140)
        score -= 20;

    if (vital.getDiastolicBP() < 60 ||
        vital.getDiastolicBP() > 90)
        score -= 10;

    if (vital.getRespiratoryRate() < 12 ||
        vital.getRespiratoryRate() > 20)
        score -= 10;

    if (score < 0)
        score = 0;

    return score;
}



// ============================================================
// HEALTH STATUS
// ============================================================

std::string AnalyticsManager::calculateStatus(
    int score
) const {

    if (score >= 90)
        return "HEALTHY";

    if (score >= 70)
        return "STABLE";

    if (score >= 50)
        return "OBSERVATION";

    if (score >= 30)
        return "HIGH RISK";

    return "CRITICAL";
}



// ============================================================
// PHASE 6.2
// PATIENT-WISE DASHBOARD
// ============================================================

void AnalyticsManager::displayPatientDashboard() const {

    std::cout
        << "\n=========================================\n"
        << "      PATIENT HEALTH DASHBOARD\n"
        << "=========================================\n";

    const auto& patients =
        patientManager.getPatients();

    if (patients.empty()) {

        std::cout
            << "No registered patients.\n";

        return;
    }

    for (const Patient& patient : patients) {

        const VitalSigns* vital =
            vitalManager.getLatestReadingForPatient(
                patient.getPatientId()
            );

        std::cout
            << "\nPatient ID : "
            << patient.getPatientId()

            << "\nName       : "
            << patient.getName();

        if (vital == nullptr) {

            std::cout
                << "\nNo vital readings available.\n"
                << "-----------------------------------------\n";

            continue;
        }

        int score =
            calculateHealthScore(
                *vital
            );

        std::cout
            << "\nHealth Score : "
            << score

            << "\nStatus       : "
            << calculateStatus(score)

            << "\n\nLatest Vital Reading"

            << "\n----------------------------"

            << "\nHeart Rate       : "
            << vital->getHeartRate()
            << " bpm"

            << "\nSpO2             : "
            << vital->getSpO2()
            << " %"

            << "\nTemperature      : "
            << vital->getTemperature()
            << " C"

            << "\nBlood Pressure   : "
            << vital->getSystolicBP()
            << "/"
            << vital->getDiastolicBP()
            << " mmHg"

            << "\nRespiratory Rate : "
            << vital->getRespiratoryRate()
            << " breaths/min"

            << "\nTimestamp        : "
            << vital->getTimestamp()

            << "\n-----------------------------------------\n";
    }
}
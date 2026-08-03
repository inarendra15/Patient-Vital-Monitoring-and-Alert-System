#include "../include/PatientManager.h"
#include "../include/VitalManager.h"
#include "../include/AlertEngine.h"
#include "../include/FileManager.h"
#include "../include/AnalyticsManager.h"
#include "../include/PriorityManager.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>


// ============================================================
// CLEAR INVALID INPUT
// ============================================================

void clearInputBuffer() {

    std::cin.clear();

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );
}


// ============================================================
// DISPLAY MAIN MENU
// ============================================================

void displayMenu() {

    std::cout
        << "\n=========================================\n"
        << "   PATIENT VITAL MONITORING SYSTEM\n"
        << "=========================================\n"
        << "1. Register Patient\n"
        << "2. Search Patient\n"
        << "3. Display All Patients\n"
        << "4. Record Vital Signs\n"
        << "5. View Patient Vital History\n"
        << "6. View Threshold Configuration\n"
        << "7. View Latest Patient Vitals\n"
        << "8. Patient Analytics Dashboard\n"
        << "9. Critical Patient Queue\n"
        << "10. Exit\n"
        << "=========================================\n"
        << "Enter choice: ";
}


// ============================================================
// PHASE 5.5
// VALIDATE PHYSICALLY POSSIBLE VITAL-SIGN INPUTS
//
// Important:
// This does NOT decide whether a reading is medically normal.
// AlertEngine handles normal/warning/critical thresholds.
//
// This function only rejects impossible or invalid input.
// ============================================================

bool validateVitalInput(
    int heartRate,
    int spo2,
    double temperature,
    int systolicBP,
    int diastolicBP,
    int respiratoryRate
) {

    bool valid = true;


    if (heartRate <= 0 || heartRate > 300) {

        std::cout
            << "\nInvalid Heart Rate."
            << " Expected range: 1-300 bpm.\n";

        valid = false;
    }


    if (spo2 < 0 || spo2 > 100) {

        std::cout
            << "\nInvalid SpO2."
            << " Expected range: 0-100%.\n";

        valid = false;
    }


    if (temperature < 20.0 ||
        temperature > 50.0) {

        std::cout
            << "\nInvalid Temperature."
            << " Expected range: 20-50 C.\n";

        valid = false;
    }


    if (systolicBP <= 0 ||
        systolicBP > 300) {

        std::cout
            << "\nInvalid Systolic BP."
            << " Expected range: 1-300 mmHg.\n";

        valid = false;
    }


    if (diastolicBP <= 0 ||
        diastolicBP > 200) {

        std::cout
            << "\nInvalid Diastolic BP."
            << " Expected range: 1-200 mmHg.\n";

        valid = false;
    }


    if (diastolicBP >= systolicBP) {

        std::cout
            << "\nInvalid Blood Pressure."
            << " Diastolic BP must be lower"
            << " than Systolic BP.\n";

        valid = false;
    }


    if (respiratoryRate <= 0 ||
        respiratoryRate > 100) {

        std::cout
            << "\nInvalid Respiratory Rate."
            << " Expected range: 1-100 breaths/min.\n";

        valid = false;
    }


    return valid;
}

// ============================================================
// MAIN
// ============================================================

int main() {

    // ========================================================
    // CREATE SYSTEM COMPONENTS
    // ========================================================

    PatientManager patientManager;

    VitalManager vitalManager;

    AnalyticsManager analyticsManager(
    vitalManager,
    patientManager);

    PriorityManager priorityManager(
    patientManager,
    vitalManager);

    AlertEngine alertEngine;

    FileManager fileManager;


    // ========================================================
    // PHASE 4.2
    // RESTORE PERSISTENT DATA
    // ========================================================

    std::cout
        << "\nLoading persistent data...\n";


    // --------------------------------------------------------
    // Load patients
    // --------------------------------------------------------

    std::vector<Patient> savedPatients =
        fileManager.loadPatients();


    for (const Patient& patient : savedPatients) {

        patientManager.loadPatient(
            patient
        );
    }


    // --------------------------------------------------------
    // Load previous vital readings
    // --------------------------------------------------------

    std::vector<VitalSigns> savedVitals =
        fileManager.loadVitalSigns();


    for (const VitalSigns& vital : savedVitals) {

        vitalManager.loadVitalSigns(
            vital
        );
    }


    std::cout
        << "Loaded "
        << savedPatients.size()
        << " patient(s) and "
        << savedVitals.size()
        << " vital reading(s).\n";


    // ========================================================
    // MAIN APPLICATION LOOP
    // ========================================================

    while (true) {

        displayMenu();


        int choice;


        if (!(std::cin >> choice)) {

            std::cout
                << "\nInvalid input. Please enter a number.\n";

            clearInputBuffer();

            continue;
        }


        // ====================================================
        // PROCESS MENU
        // ====================================================

        switch (choice) {


        // ====================================================
        // OPTION 1
        // REGISTER PATIENT
        // ====================================================

        case 1: {

            std::string name;
            std::string gender;

            int age;


            std::cout
                << "\n=========================================\n"
                << "          REGISTER PATIENT\n"
                << "=========================================\n";


            // Remove newline left by menu input
            clearInputBuffer();


            // ------------------------------------------------
            // Name
            // ------------------------------------------------

            std::cout
                << "Enter Patient Name: ";

            std::getline(
                std::cin,
                name
            );


            if (name.empty()) {

                std::cout
                    << "\nError: Patient name cannot be empty.\n";

                break;
            }


            // ------------------------------------------------
            // Age
            // ------------------------------------------------

            std::cout
                << "Enter Age: ";


            if (!(std::cin >> age)) {

                std::cout
                    << "\nError: Age must be numeric.\n";

                clearInputBuffer();

                break;
            }


            if (age <= 0 || age > 120) {

                std::cout
                    << "\nError: Age must be between "
                    << "1 and 120.\n";

                break;
            }


            clearInputBuffer();


            // ------------------------------------------------
            // Gender
            // ------------------------------------------------

            std::cout
                << "Enter Gender: ";

            std::getline(
                std::cin,
                gender
            );


            if (gender.empty()) {

                std::cout
                    << "\nError: Gender cannot be empty.\n";

                break;
            }


            // =================================================
            // ADD PATIENT TO MEMORY
            // =================================================

            patientManager.addPatient(
                name,
                age,
                gender
            );


            // =================================================
            // GET NEWLY CREATED PATIENT
            // =================================================

            const Patient* newPatient =
                patientManager.getLatestPatient();


            if (newPatient == nullptr) {

                std::cout
                    << "\nError: Unable to retrieve "
                    << "registered patient.\n";

                break;
            }


            // =================================================
            // SAVE PATIENT TO FILE
            // =================================================

            if (
                fileManager.savePatient(
                    *newPatient
                )
            ) {

                std::cout
                    << "Patient data saved to file.\n";

            }

            else {

                std::cout
                    << "\nWarning: Patient was registered "
                    << "in memory but could not be saved "
                    << "to file.\n";
            }


            break;
        }


        // ====================================================
        // OPTION 2
        // SEARCH PATIENT
        // ====================================================

        case 2: {

            int patientId;


            std::cout
                << "\n=========================================\n"
                << "           SEARCH PATIENT\n"
                << "=========================================\n"
                << "Enter Patient ID: ";


            if (!(std::cin >> patientId)) {

                std::cout
                    << "\nError: Patient ID must be numeric.\n";

                clearInputBuffer();

                break;
            }


            Patient* patient =
                patientManager.searchPatient(
                    patientId
                );


            if (patient != nullptr) {

                std::cout
                    << "\nPatient Found\n"
                    << "-----------------------------------------\n";

                patient->display();

            }

            else {

                std::cout
                    << "\nPatient not found.\n";
            }


            break;
        }


        // ====================================================
        // OPTION 3
        // DISPLAY ALL PATIENTS
        // ====================================================

        case 3: {

            patientManager.displayAllPatients();

            break;
        }


        // ====================================================
        // OPTION 4
        // RECORD VITAL SIGNS
        // ====================================================

        case 4: {

            int patientId;

            int heartRate;
            int spo2;

            double temperature;

            int systolicBP;
            int diastolicBP;

            int respiratoryRate;


            std::cout
                << "\n=========================================\n"
                << "          RECORD VITAL SIGNS\n"
                << "=========================================\n";


            // ------------------------------------------------
            // Patient ID
            // ------------------------------------------------

            std::cout
                << "Enter Patient ID: ";


            if (!(std::cin >> patientId)) {

                std::cout
                    << "\nError: Invalid Patient ID.\n";

                clearInputBuffer();

                break;
            }


            // ------------------------------------------------
            // Verify patient exists
            // ------------------------------------------------

            Patient* patient =
                patientManager.searchPatient(
                    patientId
                );


            if (patient == nullptr) {

                std::cout
                    << "\nError: Patient ID does not exist.\n"
                    << "Register the patient first.\n";

                break;
            }


            std::cout
                << "\nRecording vitals for: "
                << patient->getName()
                << "\n\n";


            // ------------------------------------------------
            // Heart Rate
            // ------------------------------------------------

            std::cout
                << "Enter Heart Rate (bpm): ";


            if (!(std::cin >> heartRate)) {

                std::cout
                    << "\nError: Invalid heart rate.\n";

                clearInputBuffer();

                break;
            }


            // ------------------------------------------------
            // SpO2
            // ------------------------------------------------

            std::cout
                << "Enter SpO2 (%): ";


            if (!(std::cin >> spo2)) {

                std::cout
                    << "\nError: Invalid SpO2.\n";

                clearInputBuffer();

                break;
            }


            // ------------------------------------------------
            // Temperature
            // ------------------------------------------------

            std::cout
                << "Enter Temperature (C): ";


            if (!(std::cin >> temperature)) {

                std::cout
                    << "\nError: Invalid temperature.\n";

                clearInputBuffer();

                break;
            }


            // ------------------------------------------------
            // Systolic BP
            // ------------------------------------------------

            std::cout
                << "Enter Systolic BP (mmHg): ";


            if (!(std::cin >> systolicBP)) {

                std::cout
                    << "\nError: Invalid systolic BP.\n";

                clearInputBuffer();

                break;
            }


            // ------------------------------------------------
            // Diastolic BP
            // ------------------------------------------------

            std::cout
                << "Enter Diastolic BP (mmHg): ";


            if (!(std::cin >> diastolicBP)) {

                std::cout
                    << "\nError: Invalid diastolic BP.\n";

                clearInputBuffer();

                break;
            }


            // ------------------------------------------------
            // Respiratory Rate
            // ------------------------------------------------

            std::cout
                << "Enter Respiratory Rate (breaths/min): ";


            if (!(std::cin >> respiratoryRate)) {

                std::cout
                    << "\nError: Invalid respiratory rate.\n";

                clearInputBuffer();

                break;
            }

            
            // --------------------------------------------------------
            // PHASE 5.5
            // Validate input before storing or evaluating it
            // --------------------------------------------------------

            if (!validateVitalInput(
                    heartRate,
                    spo2,
                    temperature,
                    systolicBP,
                    diastolicBP,
                    respiratoryRate
                )) {

                std::cout
                    << "\nVital reading rejected."
                    << " Nothing was stored.\n";

                break;
            }

            // =================================================
            // STORE NEW READING IN MEMORY
            //
            // IMPORTANT:
            // recordVitalSigns() returns void.
            // Therefore we DO NOT assign it to a bool.
            // =================================================

            vitalManager.recordVitalSigns(
                patientId,
                heartRate,
                spo2,
                temperature,
                systolicBP,
                diastolicBP,
                respiratoryRate
            );


            // =================================================
            // RETRIEVE NEW READING
            // =================================================

            const VitalSigns* latestReading =
                vitalManager.getLatestReading();


            if (latestReading == nullptr) {

                std::cout
                    << "\nError: Unable to retrieve "
                    << "the recorded vital reading.\n";

                break;
            }


            // =================================================
            // PERSIST VITAL READING
            // =================================================

            if (
                fileManager.saveVitalSigns(
                    *latestReading
                )
            ) {

                std::cout
                    << "Vital reading saved to file.\n";

            }

            else {

                std::cout
                    << "\nWarning: Vital reading exists "
                    << "in memory but could not be "
                    << "saved to file.\n";
            }


            // =================================================
            // RUN RULE-BASED ALERT ENGINE
            // =================================================

            std::vector<Alert> alerts =
                alertEngine.evaluate(
                    *latestReading
                );


            // =================================================
            // NORMAL READING
            // =================================================

            if (alerts.empty()) {

                std::cout
                    << "\n=========================================\n"
                    << "              STATUS: NORMAL\n"
                    << "=========================================\n"
                    << "All monitored vital signs are within "
                    << "configured thresholds.\n";
            }


            // =================================================
            // ABNORMAL READING
            // =================================================

            else {

                std::cout
                    << "\n=========================================\n"
                    << "             ALERTS GENERATED\n"
                    << "=========================================\n";


                for (const Alert& alert : alerts) {

                    // Display alert on console
                    alert.display();


                    // -----------------------------------------
                    // Persist abnormal event
                    // -----------------------------------------

                    if (
                        !fileManager.saveAlert(
                            alert
                        )
                    ) {

                        std::cout
                            << "\nWarning: Alert could not "
                            << "be written to the alert log.\n";
                    }
                }


                std::cout
                    << "\nAbnormal event(s) logged to file.\n";
            }


            break;
        }


        // ====================================================
        // OPTION 5
        // VIEW PATIENT VITAL HISTORY
        // ====================================================

        case 5: {

            int patientId;


            std::cout
                << "\n=========================================\n"
                << "       PATIENT VITAL HISTORY\n"
                << "=========================================\n"
                << "Enter Patient ID: ";


            if (!(std::cin >> patientId)) {

                std::cout
                    << "\nError: Invalid Patient ID.\n";

                clearInputBuffer();

                break;
            }


            Patient* patient =
                patientManager.searchPatient(
                    patientId
                );


            if (patient == nullptr) {

                std::cout
                    << "\nPatient not found.\n";

                break;
            }


            std::cout
                << "\nPatient: "
                << patient->getName()
                << "\n";


            vitalManager.displayPatientHistory(
                patientId
            );


            break;
        }


        // ====================================================
        // OPTION 6
        // DISPLAY THRESHOLD CONFIGURATION
        // ====================================================

        case 6: {

            alertEngine.displayThresholds();

            break;
        }

        // ========================================================
        // CASE 7
        // VIEW LATEST VITAL READING FOR A PATIENT
        //
        // Phase 5.4:
        // Uses hash-based patient-specific latest-reading lookup.
        // ========================================================

        case 7: {

            int patientId;


            std::cout
                << "\n=========================================\n"
                << "       LATEST PATIENT VITALS\n"
                << "=========================================\n"
                << "Enter Patient ID: ";


            std::cin >> patientId;


            // ----------------------------------------------------
            // Validate that patient exists
            // ----------------------------------------------------

            Patient* patient =
                patientManager.searchPatient(patientId);


            if (patient == nullptr) {

                std::cout
                    << "\nPatient not found.\n";

                break;
            }


            std::cout
                << "\nPatient: "
                << patient->getName()
                << "\n";


            // ----------------------------------------------------
            // PHASE 5.4
            // Average O(1) latest-reading lookup
            // ----------------------------------------------------

            const VitalSigns* latest =
                vitalManager.getLatestReadingForPatient(
                    patientId
                );


            if (latest == nullptr) {

                std::cout
                    << "\nNo vital readings found for Patient ID: "
                    << patientId
                    << "\n";

                break;
            }


            std::cout
                << "\nLatest vital reading:\n";


            latest->display();


            break;
        }

        // ========================================================
        // OPTION 8
        // PATIENT HEALTH DASHBOARD
        // ========================================================

        case 8:
        {
            analyticsManager.displayPatientDashboard();

            break;
        }

        // =====================================================
        // PHASE 7
        // CRITICAL PATIENT QUEUE
        // =====================================================

        case 9:

            priorityManager.displayCriticalPatients();

            break;

        // ====================================================
        // OPTION 9
        // EXIT
        // ====================================================

        case 10: {

            std::cout
                << "\n=========================================\n"
                << "   PATIENT VITAL MONITORING SYSTEM\n"
                << "=========================================\n"
                << "Exiting application...\n"
                << "Persistent data has been saved.\n"
                << "=========================================\n";


            return 0;
        }


        // ====================================================
        // INVALID OPTION
        // ====================================================

        default: {

            std::cout
                << "\nInvalid choice. "
                << "Please select between 1 and 10.\n";

            break;
        }

        } // switch

    } // while


    return 0;
}
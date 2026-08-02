#include "../include/PatientManager.h"
#include "../include/VitalManager.h"

#include <iostream>
#include <limits>
#include <string>


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
        << "6. Exit\n"
        << "=========================================\n"
        << "Enter choice: ";
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main() {

    // --------------------------------------------------------
    // Managers
    // --------------------------------------------------------

    PatientManager patientManager;

    VitalManager vitalManager;


    int choice;


    // ========================================================
    // MAIN APPLICATION LOOP
    // ========================================================

    while (true) {

        displayMenu();

        std::cin >> choice;


        // ----------------------------------------------------
        // Handle non-numeric menu input
        // ----------------------------------------------------

        if (std::cin.fail()) {

            std::cin.clear();

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout
                << "\nInvalid input. Please enter a number.\n";

            continue;
        }


        // ====================================================
        // MENU SELECTION
        // ====================================================

        switch (choice) {


        // ====================================================
        // 1. REGISTER PATIENT
        // ====================================================

        case 1: {

            std::string name;
            std::string gender;

            int age;


            // Remove leftover newline from input buffer
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );


            std::cout
                << "\nEnter patient name: ";

            std::getline(
                std::cin,
                name
            );


            std::cout
                << "Enter age: ";

            std::cin >> age;


            // Validate numeric age input
            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Age must be a number.\n";

                break;
            }


            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );


            std::cout
                << "Enter gender: ";

            std::getline(
                std::cin,
                gender
            );


            patientManager.addPatient(
                name,
                age,
                gender
            );


            break;
        }


        // ====================================================
        // 2. SEARCH PATIENT
        // ====================================================

        case 2: {

            int patientId;


            std::cout
                << "\nEnter Patient ID: ";

            std::cin >> patientId;


            // Validate input
            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Patient ID must be numeric.\n";

                break;
            }


            // Search patient
            Patient* patient =
                patientManager.searchPatient(patientId);


            if (patient != nullptr) {

                std::cout
                    << "\nPatient Found\n"
                    << "----------------------------------------------------------\n";


                patient->display();

            } else {

                std::cout
                    << "\nPatient not found.\n";
            }


            break;
        }


        // ====================================================
        // 3. DISPLAY ALL PATIENTS
        // ====================================================

        case 3: {

            patientManager.displayAllPatients();

            break;
        }


        // ====================================================
        // 4. RECORD VITAL SIGNS
        // ====================================================

        case 4: {

            int patientId;

            int heartRate;
            int spo2;

            double temperature;

            int systolicBP;
            int diastolicBP;

            int respiratoryRate;


            // ------------------------------------------------
            // Get Patient ID
            // ------------------------------------------------

            std::cout
                << "\nEnter Patient ID: ";

            std::cin >> patientId;


            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid Patient ID.\n";

                break;
            }


            // ------------------------------------------------
            // Verify patient exists
            // ------------------------------------------------

            Patient* patient =
                patientManager.searchPatient(patientId);


            if (patient == nullptr) {

                std::cout
                    << "\nError: Patient ID does not exist.\n";

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

            std::cin >> heartRate;


            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid heart rate input.\n";

                break;
            }


            // ------------------------------------------------
            // SpO2
            // ------------------------------------------------

            std::cout
                << "Enter SpO2 (%): ";

            std::cin >> spo2;


            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid SpO2 input.\n";

                break;
            }


            // ------------------------------------------------
            // Temperature
            // ------------------------------------------------

            std::cout
                << "Enter Temperature (C): ";

            std::cin >> temperature;


            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid temperature input.\n";

                break;
            }


            // ------------------------------------------------
            // Systolic Blood Pressure
            // ------------------------------------------------

            std::cout
                << "Enter Systolic BP (mmHg): ";

            std::cin >> systolicBP;


            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid systolic BP input.\n";

                break;
            }


            // ------------------------------------------------
            // Diastolic Blood Pressure
            // ------------------------------------------------

            std::cout
                << "Enter Diastolic BP (mmHg): ";

            std::cin >> diastolicBP;


            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid diastolic BP input.\n";

                break;
            }


            // ------------------------------------------------
            // Respiratory Rate
            // ------------------------------------------------

            std::cout
                << "Enter Respiratory Rate (breaths/min): ";

            std::cin >> respiratoryRate;


            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid respiratory rate input.\n";

                break;
            }


            // ------------------------------------------------
            // Store Vital Reading
            // ------------------------------------------------

            vitalManager.recordVitals(
                patientId,
                heartRate,
                spo2,
                temperature,
                systolicBP,
                diastolicBP,
                respiratoryRate
            );


            break;
        }


        // ====================================================
        // 5. VIEW PATIENT VITAL HISTORY
        // ====================================================

        case 5: {

            int patientId;


            std::cout
                << "\nEnter Patient ID: ";

            std::cin >> patientId;


            // Validate input
            if (std::cin.fail()) {

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "\nError: Invalid Patient ID.\n";

                break;
            }


            // ------------------------------------------------
            // Check whether patient exists
            // ------------------------------------------------

            Patient* patient =
                patientManager.searchPatient(patientId);


            if (patient == nullptr) {

                std::cout
                    << "\nError: Patient ID does not exist.\n";

                break;
            }


            std::cout
                << "\nPatient: "
                << patient->getName()
                << "\n";


            // ------------------------------------------------
            // Display patient's historical vital records
            // ------------------------------------------------

            vitalManager.displayPatientHistory(
                patientId
            );


            break;
        }


        // ====================================================
        // 6. EXIT
        // ====================================================

        case 6: {

            std::cout
                << "\nExiting Patient Monitoring System...\n";

            return 0;
        }


        // ====================================================
        // INVALID MENU OPTION
        // ====================================================

        default: {

            std::cout
                << "\nInvalid choice. Please select between 1 and 6.\n";

            break;
        }

        } // end switch

    } // end while


    return 0;
}
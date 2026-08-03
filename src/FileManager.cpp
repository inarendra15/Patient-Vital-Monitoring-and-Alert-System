#include "../include/FileManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


// ============================================================
// CONSTRUCTOR
// ============================================================

FileManager::FileManager()
    : patientFile("data/patients.txt"),
      vitalFile("data/vitals.txt"),
      alertFile("data/alerts.txt") {

}


// ============================================================
// SAVE PATIENT
// ============================================================

bool FileManager::savePatient(
    const Patient& patient
) const {

    std::ofstream file(
        patientFile,
        std::ios::app
    );


    if (!file.is_open()) {

        std::cerr
            << "\nError: Unable to open patient file.\n";

        return false;
    }


    file
        << patient.getPatientId()
        << "|"
        << patient.getName()
        << "|"
        << patient.getAge()
        << "|"
        << patient.getGender()
        << "\n";


    return true;
}


// ============================================================
// SAVE VITAL SIGNS
// ============================================================

bool FileManager::saveVitalSigns(
    const VitalSigns& vital
) const {

    std::ofstream file(
        vitalFile,
        std::ios::app
    );


    if (!file.is_open()) {

        std::cerr
            << "\nError: Unable to open vital file.\n";

        return false;
    }


    file
        << vital.getPatientId()
        << "|"
        << vital.getHeartRate()
        << "|"
        << vital.getSpO2()
        << "|"
        << vital.getTemperature()
        << "|"
        << vital.getSystolicBP()
        << "|"
        << vital.getDiastolicBP()
        << "|"
        << vital.getRespiratoryRate()
        << "|"
        << vital.getTimestamp()
        << "\n";


    return true;
}


// ============================================================
// SAVE ALERT
// ============================================================

bool FileManager::saveAlert(
    const Alert& alert
) const {

    std::ofstream file(
        alertFile,
        std::ios::app
    );


    if (!file.is_open()) {

        std::cerr
            << "\nError: Unable to open alert file.\n";

        return false;
    }


    file
        << alert.getPatientId()
        << "|"
        << alert.getTimestamp()
        << "|";


    // --------------------------------------------------------
    // Convert AlertSeverity enum into readable text
    // --------------------------------------------------------

    AlertSeverity severity =
        alert.getSeverity();


    if (severity == AlertSeverity::CRITICAL) {

        file << "CRITICAL";
    }

    else if (severity == AlertSeverity::WARNING) {

        file << "WARNING";
    }

    else {

        file << "NORMAL";
    }


    file
        << "|"
        << alert.getVitalName()
        << "|"
        << alert.getValue()
        << "|"
        << alert.getMessage()
        << "\n";


    return true;
}


// ============================================================
// LOAD PATIENTS FROM FILE
// ============================================================

std::vector<Patient>
FileManager::loadPatients() const {

    std::vector<Patient> patients;


    std::ifstream file(patientFile);


    // File may not exist on first execution.
    if (!file.is_open()) {

        return patients;
    }


    std::string line;


    while (std::getline(file, line)) {

        if (line.empty()) {

            continue;
        }


        std::stringstream ss(line);


        std::string patientIdString;
        std::string name;
        std::string ageString;
        std::string gender;


        bool validRecord =

            std::getline(
                ss,
                patientIdString,
                '|'
            ) &&

            std::getline(
                ss,
                name,
                '|'
            ) &&

            std::getline(
                ss,
                ageString,
                '|'
            ) &&

            std::getline(
                ss,
                gender
            );


        if (!validRecord) {

            std::cerr
                << "\nWarning: Invalid patient record skipped:\n"
                << line
                << "\n";

            continue;
        }


        try {

            int patientId =
                std::stoi(
                    patientIdString
                );


            int age =
                std::stoi(
                    ageString
                );


            Patient patient(
                patientId,
                name,
                age,
                gender
            );


            patients.push_back(
                patient
            );

        }

        catch (...) {

            std::cerr
                << "\nWarning: Corrupted patient record skipped:\n"
                << line
                << "\n";
        }
    }


    file.close();


    return patients;
}


// ============================================================
// LOAD VITAL SIGNS FROM FILE
// ============================================================

std::vector<VitalSigns>
FileManager::loadVitalSigns() const {

    std::vector<VitalSigns> vitals;


    std::ifstream file(vitalFile);


    if (!file.is_open()) {

        return vitals;
    }


    std::string line;


    while (std::getline(file, line)) {

        if (line.empty()) {

            continue;
        }


        std::stringstream ss(line);


        std::string patientIdString;
        std::string heartRateString;
        std::string spo2String;
        std::string temperatureString;

        std::string systolicBPString;
        std::string diastolicBPString;
        std::string respiratoryRateString;

        std::string timestamp;


        bool validRecord =

            std::getline(
                ss,
                patientIdString,
                '|'
            ) &&

            std::getline(
                ss,
                heartRateString,
                '|'
            ) &&

            std::getline(
                ss,
                spo2String,
                '|'
            ) &&

            std::getline(
                ss,
                temperatureString,
                '|'
            ) &&

            std::getline(
                ss,
                systolicBPString,
                '|'
            ) &&

            std::getline(
                ss,
                diastolicBPString,
                '|'
            ) &&

            std::getline(
                ss,
                respiratoryRateString,
                '|'
            ) &&

            std::getline(
                ss,
                timestamp
            );


        if (!validRecord) {

            std::cerr
                << "\nWarning: Invalid vital record skipped:\n"
                << line
                << "\n";

            continue;
        }


        try {

            int patientId =
                std::stoi(
                    patientIdString
                );


            int heartRate =
                std::stoi(
                    heartRateString
                );


            int spo2 =
                std::stoi(
                    spo2String
                );


            double temperature =
                std::stod(
                    temperatureString
                );


            int systolicBP =
                std::stoi(
                    systolicBPString
                );


            int diastolicBP =
                std::stoi(
                    diastolicBPString
                );


            int respiratoryRate =
                std::stoi(
                    respiratoryRateString
                );


            // Restore the original timestamp using the
            // overloaded VitalSigns constructor.

            VitalSigns vital(
                patientId,
                heartRate,
                spo2,
                temperature,
                systolicBP,
                diastolicBP,
                respiratoryRate,
                timestamp
            );


            vitals.push_back(
                vital
            );

        }

        catch (...) {

            std::cerr
                << "\nWarning: Corrupted vital record skipped:\n"
                << line
                << "\n";
        }
    }


    file.close();


    return vitals;
}
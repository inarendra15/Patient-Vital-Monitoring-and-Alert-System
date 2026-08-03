#include "../include/VitalManager.h"

#include <iostream>


// -------------------------------------------------
// Validate Vital Signs
// -------------------------------------------------

bool VitalManager::validateVitals(
    int heartRate,
    int spo2,
    double temperature,
    int systolicBP,
    int diastolicBP,
    int respiratoryRate
) const {

    /*
        These checks validate whether the entered
        values are plausible input values.

        They DO NOT determine whether the patient
        is medically normal or abnormal.

        Alert thresholds will be implemented
        separately in Phase 3.
    */


    if (heartRate <= 0 || heartRate > 250) {

        std::cout
            << "Error: Invalid heart rate.\n";

        return false;
    }


    if (spo2 <= 0 || spo2 > 100) {

        std::cout
            << "Error: Invalid SpO2 value.\n";

        return false;
    }


    if (temperature < 25.0 || temperature > 45.0) {

        std::cout
            << "Error: Invalid temperature.\n";

        return false;
    }


    if (systolicBP <= 0 || systolicBP > 300) {

        std::cout
            << "Error: Invalid systolic blood pressure.\n";

        return false;
    }


    if (diastolicBP <= 0 || diastolicBP > 200) {

        std::cout
            << "Error: Invalid diastolic blood pressure.\n";

        return false;
    }


    if (respiratoryRate <= 0 || respiratoryRate > 100) {

        std::cout
            << "Error: Invalid respiratory rate.\n";

        return false;
    }


    return true;
}


// -------------------------------------------------
// Record Vital Signs
// -------------------------------------------------

bool VitalManager::recordVitals(
    int patientId,
    int heartRate,
    int spo2,
    double temperature,
    int systolicBP,
    int diastolicBP,
    int respiratoryRate
) {

    // Validate before storing
    if (!validateVitals(
            heartRate,
            spo2,
            temperature,
            systolicBP,
            diastolicBP,
            respiratoryRate
        )) {

        return false;
    }


    // Create new reading
    VitalSigns reading(
        patientId,
        heartRate,
        spo2,
        temperature,
        systolicBP,
        diastolicBP,
        respiratoryRate
    );


    // Store in vector
    vitalRecords.push_back(reading);


    std::cout
        << "\nVital signs recorded successfully.\n";


    return true;
}


// -------------------------------------------------
// Display Patient Vital History
// -------------------------------------------------

void VitalManager::displayPatientHistory(
    int patientId
) const {

    bool found = false;


    std::cout
        << "\n=========================================\n"
        << "        PATIENT VITAL HISTORY\n"
        << "=========================================\n";


    for (const VitalSigns& reading : vitalRecords) {

        if (reading.getPatientId() == patientId) {

            reading.display();

            std::cout
                << "-----------------------------------------\n";

            found = true;
        }
    }


    if (!found) {

        std::cout
            << "No vital records found for Patient ID "
            << patientId
            << ".\n";
    }
}


// -------------------------------------------------
// Total Readings
// -------------------------------------------------

int VitalManager::getTotalReadings() const {

    return static_cast<int>(
        vitalRecords.size()
    );
}

// ============================================================
// GET LATEST VITAL READING
// ============================================================

const VitalSigns* VitalManager::getLatestReading() const {

    if (vitalRecords.empty()) {

        return nullptr;
    }


    return &vitalRecords.back();
}
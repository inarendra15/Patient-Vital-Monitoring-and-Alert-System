#include "../include/VitalManager.h"

#include <iostream>


// ============================================================
// CONSTRUCTOR
// ============================================================

VitalManager::VitalManager() {

}


// ============================================================
// RECORD NEW VITAL SIGNS
// ============================================================

void VitalManager::recordVitalSigns(
    int patientId,
    int heartRate,
    int spo2,
    double temperature,
    int systolicBP,
    int diastolicBP,
    int respiratoryRate
) {

    VitalSigns vital(
        patientId,
        heartRate,
        spo2,
        temperature,
        systolicBP,
        diastolicBP,
        respiratoryRate
    );


    vitalHistory.push_back(vital);


    std::cout
        << "\nVital signs recorded successfully.\n";
}


// ============================================================
// DISPLAY PATIENT VITAL HISTORY
// ============================================================

void VitalManager::displayPatientHistory(
    int patientId
) const {

    bool found = false;


    std::cout
        << "\n========================================\n"
        << "          PATIENT VITAL HISTORY\n"
        << "========================================\n";


    for (const VitalSigns& vital : vitalHistory) {

        if (vital.getPatientId() == patientId) {

            vital.display();

            found = true;
        }
    }


    if (!found) {

        std::cout
            << "\nNo vital history found for Patient ID: "
            << patientId
            << "\n";
    }
}


// ============================================================
// GET LATEST VITAL READING
// ============================================================

const VitalSigns*
VitalManager::getLatestReading() const {

    if (vitalHistory.empty()) {

        return nullptr;
    }


    return &vitalHistory.back();
}


// ============================================================
// PHASE 4.2
// LOAD EXISTING VITAL READING FROM PERSISTENT STORAGE
// ============================================================

void VitalManager::loadVitalSigns(
    const VitalSigns& vital
) {

    vitalHistory.push_back(vital);
}
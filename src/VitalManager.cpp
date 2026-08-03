#include "../include/VitalManager.h"

#include <iostream>


// ============================================================
// CONSTRUCTOR
// ============================================================

VitalManager::VitalManager() {

}


// ============================================================
// RECORD NEW VITAL SIGNS
//
// Phase 5.2:
// 1. Create vital reading
// 2. Store it in primary vector
// 3. Update patient -> vital indices hash table
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

    // --------------------------------------------------------
    // Create new vital reading
    // --------------------------------------------------------

    VitalSigns vital(
        patientId,
        heartRate,
        spo2,
        temperature,
        systolicBP,
        diastolicBP,
        respiratoryRate
    );


    // --------------------------------------------------------
    // Store reading in primary storage
    // --------------------------------------------------------

    vitalHistory.push_back(vital);


    // --------------------------------------------------------
    // PHASE 5.2
    // Update secondary hash index
    //
    // Since push_back() inserted the element at the end:
    //
    // index = size - 1
    // --------------------------------------------------------

    std::size_t index =
        vitalHistory.size() - 1;


    patientVitalIndex[patientId]
        .push_back(index);


    std::cout
        << "\nVital signs recorded successfully.\n";
}


// ============================================================
// DISPLAY PATIENT VITAL HISTORY
//
// Phase 5.2:
// Uses patientVitalIndex instead of scanning every vital record.
//
// Average complexity:
//
// Hash lookup : O(1)
// Display      : O(k)
//
// where k = number of readings belonging to the patient.
// ============================================================

void VitalManager::displayPatientHistory(
    int patientId
) const {

    std::cout
        << "\n========================================\n"
        << "          PATIENT VITAL HISTORY\n"
        << "========================================\n";


    // --------------------------------------------------------
    // Find patient's history bucket
    // --------------------------------------------------------

    auto it =
        patientVitalIndex.find(patientId);


    // --------------------------------------------------------
    // No history found
    // --------------------------------------------------------

    if (it == patientVitalIndex.end() ||
        it->second.empty()) {

        std::cout
            << "\nNo vital history found for Patient ID: "
            << patientId
            << "\n";

        return;
    }


    // --------------------------------------------------------
    // Retrieve only this patient's records
    //
    // it->second contains indices into vitalHistory.
    //
    // Example:
    //
    // Patient 1001 -> [0, 2, 5]
    // --------------------------------------------------------

    for (std::size_t index : it->second) {

        // Defensive bounds check
        if (index < vitalHistory.size()) {

            vitalHistory[index].display();
        }
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
// LOAD EXISTING VITAL READING FROM PERSISTENT STORAGE
//
// Called during application startup.
//
// Phase 4:
// Restore vital reading.
//
// Phase 5.2:
// Reconstruct patient -> vital indices hash table.
// ============================================================


// ============================================================
// PHASE 5.3
// GET LATEST VITAL READING FOR A SPECIFIC PATIENT
//
// Uses the hash-based secondary index.
//
// Average complexity:
//     Hash lookup       -> O(1)
//     Latest index read -> O(1)
//
// Therefore average lookup complexity -> O(1)
// ============================================================

const VitalSigns*
VitalManager::getLatestReadingForPatient(
    int patientId
) const {

    // --------------------------------------------------------
    // Locate patient's vital-history bucket
    // --------------------------------------------------------

    auto it =
        patientVitalIndex.find(patientId);


    // --------------------------------------------------------
    // Patient has no vital history
    // --------------------------------------------------------

    if (it == patientVitalIndex.end() ||
        it->second.empty()) {

        return nullptr;
    }


    // --------------------------------------------------------
    // The last stored index corresponds to the patient's
    // most recently recorded vital reading.
    //
    // Example:
    //
    // 1001 -> [0, 3, 7]
    //
    // Latest reading is vitalHistory[7].
    // --------------------------------------------------------

    std::size_t latestIndex =
        it->second.back();


    // Defensive bounds validation
    if (latestIndex >= vitalHistory.size()) {

        return nullptr;
    }


    return &vitalHistory[latestIndex];
}


void VitalManager::loadVitalSigns(
    const VitalSigns& vital
) {

    // --------------------------------------------------------
    // Restore reading into primary storage
    // --------------------------------------------------------

    vitalHistory.push_back(vital);


    // --------------------------------------------------------
    // Determine restored reading's position
    // --------------------------------------------------------

    std::size_t index =
        vitalHistory.size() - 1;


    // --------------------------------------------------------
    // PHASE 5.2
    // Reconstruct secondary index
    //
    // Patient ID -> vitalHistory positions
    // --------------------------------------------------------

    patientVitalIndex[
        vital.getPatientId()
    ].push_back(index);
}
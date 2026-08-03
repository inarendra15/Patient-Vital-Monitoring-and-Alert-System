#ifndef VITAL_MANAGER_H
#define VITAL_MANAGER_H

#include "VitalSigns.h"

#include <vector>
#include <unordered_map>
#include <cstddef>


class VitalManager {

private:

    // ========================================================
    // PRIMARY STORAGE
    // Stores every vital-sign reading
    // ========================================================

    std::vector<VitalSigns> vitalHistory;


    // ========================================================
    // PHASE 5.2
    // HASH-BASED SECONDARY INDEX
    //
    // Patient ID -> positions inside vitalHistory
    //
    // Example:
    //
    // 1001 -> [0, 2, 5]
    // 1002 -> [1, 4]
    //
    // This avoids scanning the complete vitalHistory vector
    // when retrieving one patient's records.
    // ========================================================

    std::unordered_map<
        int,
        std::vector<std::size_t>
    > patientVitalIndex;


public:

    // ========================================================
    // CONSTRUCTOR
    // ========================================================

    VitalManager();


    // ========================================================
    // RECORD NEW VITAL SIGNS
    // ========================================================

    void recordVitalSigns(
        int patientId,
        int heartRate,
        int spo2,
        double temperature,
        int systolicBP,
        int diastolicBP,
        int respiratoryRate
    );


    // ========================================================
    // DISPLAY VITAL HISTORY OF A PATIENT
    //
    // Phase 5.2:
    // Uses hash-based patient index
    // ========================================================

    void displayPatientHistory(
        int patientId
    ) const;


    // ========================================================
    // RETURN MOST RECENT VITAL READING
    // ========================================================

    const VitalSigns*
    getLatestReading() const;


    // ========================================================
    // LOAD EXISTING VITAL READING
    //
    // Used when restoring persistent data during startup.
    // Also reconstructs the patient-vital index.
    // ========================================================

    // ========================================================
    // PHASE 5.3
    // Return most recent reading belonging to one patient
    // ========================================================

    const VitalSigns*
    getLatestReadingForPatient(
        int patientId
    ) const;

    void loadVitalSigns(
        const VitalSigns& vital
    );
};


#endif
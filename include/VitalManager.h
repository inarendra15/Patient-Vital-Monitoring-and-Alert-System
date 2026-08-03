#ifndef VITAL_MANAGER_H
#define VITAL_MANAGER_H

#include "VitalSigns.h"

#include <vector>

class VitalManager {

private:
    // Stores all vital-sign readings in memory
    std::vector<VitalSigns> vitalHistory;

public:
    // Constructor
    VitalManager();

    // Record a new vital-sign reading
    void recordVitalSigns(
        int patientId,
        int heartRate,
        int spo2,
        double temperature,
        int systolicBP,
        int diastolicBP,
        int respiratoryRate
    );

    // Display all vital readings belonging to a patient
    void displayPatientHistory(int patientId) const;

    // Return the most recently stored vital reading
    const VitalSigns* getLatestReading() const;

    // Load a previously saved vital reading from file
    // Used during application startup
    void loadVitalSigns(const VitalSigns& vital);
};

#endif
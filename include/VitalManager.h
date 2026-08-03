#ifndef VITAL_MANAGER_H
#define VITAL_MANAGER_H

#include "VitalSigns.h"

#include <vector>


class VitalManager {

private:

    std::vector<VitalSigns> vitalRecords;


public:

    // Record new vital signs
    bool recordVitals(
        int patientId,
        int heartRate,
        int spo2,
        double temperature,
        int systolicBP,
        int diastolicBP,
        int respiratoryRate
    );


    // Display complete history for a patient
    void displayPatientHistory(int patientId) const;


    // Number of readings in the system
    int getTotalReadings() const;

    const VitalSigns* getLatestReading() const;

private:

    // Validate physically plausible input ranges
    bool validateVitals(
        int heartRate,
        int spo2,
        double temperature,
        int systolicBP,
        int diastolicBP,
        int respiratoryRate
    ) const;
};


#endif
#ifndef VITAL_SIGNS_H
#define VITAL_SIGNS_H

#include <string>


class VitalSigns {

private:

    int patientId;
    int heartRate;
    int spo2;

    double temperature;

    int systolicBP;
    int diastolicBP;
    int respiratoryRate;

    std::string timestamp;


public:

    // ========================================================
    // NEW VITAL READING
    // Timestamp generated automatically
    // ========================================================

    VitalSigns(
        int patientId,
        int heartRate,
        int spo2,
        double temperature,
        int systolicBP,
        int diastolicBP,
        int respiratoryRate
    );


    // ========================================================
    // LOADED VITAL READING
    // Existing timestamp restored from file
    // ========================================================

    VitalSigns(
        int patientId,
        int heartRate,
        int spo2,
        double temperature,
        int systolicBP,
        int diastolicBP,
        int respiratoryRate,
        const std::string& timestamp
    );


    int getPatientId() const;

    int getHeartRate() const;

    int getSpO2() const;

    double getTemperature() const;

    int getSystolicBP() const;

    int getDiastolicBP() const;

    int getRespiratoryRate() const;

    std::string getTimestamp() const;


    void display() const;


private:

    std::string generateTimestamp() const;
};


#endif
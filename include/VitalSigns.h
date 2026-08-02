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

    // Constructor
    VitalSigns(
        int patientId,
        int heartRate,
        int spo2,
        double temperature,
        int systolicBP,
        int diastolicBP,
        int respiratoryRate
    );


    // Getter functions
    int getPatientId() const;

    int getHeartRate() const;

    int getSpO2() const;

    double getTemperature() const;

    int getSystolicBP() const;

    int getDiastolicBP() const;

    int getRespiratoryRate() const;

    std::string getTimestamp() const;


    // Display complete vital reading
    void display() const;


private:

    // Generate current date and time
    std::string generateTimestamp() const;
};


#endif
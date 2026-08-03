#ifndef THRESHOLD_CONFIG_H
#define THRESHOLD_CONFIG_H


class ThresholdConfig {

public:

    // ========================================================
    // HEART RATE
    // ========================================================

    int heartRateCriticalLow;
    int heartRateWarningLow;

    int heartRateWarningHigh;
    int heartRateCriticalHigh;


    // ========================================================
    // SPO2
    // ========================================================

    int spo2CriticalLow;
    int spo2WarningLow;


    // ========================================================
    // TEMPERATURE
    // ========================================================

    double temperatureCriticalLow;
    double temperatureWarningLow;

    double temperatureWarningHigh;
    double temperatureCriticalHigh;


    // ========================================================
    // SYSTOLIC BLOOD PRESSURE
    // ========================================================

    int systolicCriticalLow;
    int systolicWarningLow;

    int systolicWarningHigh;
    int systolicCriticalHigh;


    // ========================================================
    // DIASTOLIC BLOOD PRESSURE
    // ========================================================

    int diastolicCriticalLow;
    int diastolicWarningLow;

    int diastolicWarningHigh;
    int diastolicCriticalHigh;


    // ========================================================
    // RESPIRATORY RATE
    // ========================================================

    int respiratoryCriticalLow;
    int respiratoryWarningLow;

    int respiratoryWarningHigh;
    int respiratoryCriticalHigh;


    // Constructor loads default configuration
    ThresholdConfig();


    // Display current threshold configuration
    void display() const;
};


#endif
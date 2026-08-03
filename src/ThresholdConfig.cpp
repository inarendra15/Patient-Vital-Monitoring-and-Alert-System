#include "../include/ThresholdConfig.h"

#include <iostream>


// ============================================================
// DEFAULT THRESHOLD CONFIGURATION
// ============================================================

ThresholdConfig::ThresholdConfig() {

    // --------------------------------------------------------
    // Heart Rate (bpm)
    // --------------------------------------------------------

    heartRateCriticalLow  = 40;
    heartRateWarningLow   = 60;

    heartRateWarningHigh  = 100;
    heartRateCriticalHigh = 130;


    // --------------------------------------------------------
    // SpO2 (%)
    // --------------------------------------------------------

    spo2CriticalLow = 90;
    spo2WarningLow  = 95;


    // --------------------------------------------------------
    // Temperature (C)
    // --------------------------------------------------------

    temperatureCriticalLow  = 35.0;
    temperatureWarningLow   = 36.0;

    temperatureWarningHigh  = 37.5;
    temperatureCriticalHigh = 39.0;


    // --------------------------------------------------------
    // Systolic BP
    // --------------------------------------------------------

    systolicCriticalLow  = 80;
    systolicWarningLow   = 90;

    systolicWarningHigh  = 140;
    systolicCriticalHigh = 180;


    // --------------------------------------------------------
    // Diastolic BP
    // --------------------------------------------------------

    diastolicCriticalLow  = 50;
    diastolicWarningLow   = 60;

    diastolicWarningHigh  = 90;
    diastolicCriticalHigh = 120;


    // --------------------------------------------------------
    // Respiratory Rate
    // --------------------------------------------------------

    respiratoryCriticalLow  = 8;
    respiratoryWarningLow   = 12;

    respiratoryWarningHigh  = 20;
    respiratoryCriticalHigh = 30;
}


// ============================================================
// DISPLAY CONFIGURATION
// ============================================================

void ThresholdConfig::display() const {

    std::cout
        << "\n=========================================\n"
        << "       CURRENT THRESHOLD CONFIGURATION\n"
        << "=========================================\n"

        << "Heart Rate\n"
        << "  Critical Low  : < " << heartRateCriticalLow << "\n"
        << "  Warning Low   : < " << heartRateWarningLow << "\n"
        << "  Warning High  : > " << heartRateWarningHigh << "\n"
        << "  Critical High : > " << heartRateCriticalHigh << "\n\n"

        << "SpO2\n"
        << "  Warning       : < " << spo2WarningLow << "\n"
        << "  Critical      : < " << spo2CriticalLow << "\n\n"

        << "Temperature\n"
        << "  Critical Low  : < " << temperatureCriticalLow << "\n"
        << "  Warning Low   : < " << temperatureWarningLow << "\n"
        << "  Warning High  : > " << temperatureWarningHigh << "\n"
        << "  Critical High : > " << temperatureCriticalHigh << "\n\n"

        << "Systolic BP\n"
        << "  Critical Low  : < " << systolicCriticalLow << "\n"
        << "  Warning Low   : < " << systolicWarningLow << "\n"
        << "  Warning High  : > " << systolicWarningHigh << "\n"
        << "  Critical High : > " << systolicCriticalHigh << "\n\n"

        << "Diastolic BP\n"
        << "  Critical Low  : < " << diastolicCriticalLow << "\n"
        << "  Warning Low   : < " << diastolicWarningLow << "\n"
        << "  Warning High  : > " << diastolicWarningHigh << "\n"
        << "  Critical High : > " << diastolicCriticalHigh << "\n\n"

        << "Respiratory Rate\n"
        << "  Critical Low  : < " << respiratoryCriticalLow << "\n"
        << "  Warning Low   : < " << respiratoryWarningLow << "\n"
        << "  Warning High  : > " << respiratoryWarningHigh << "\n"
        << "  Critical High : > " << respiratoryCriticalHigh << "\n";
}
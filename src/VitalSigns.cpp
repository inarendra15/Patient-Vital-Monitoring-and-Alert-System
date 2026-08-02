#include "../include/VitalSigns.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>


// ============================================================
// CONSTRUCTOR
// ============================================================

VitalSigns::VitalSigns(
    int patientId,
    int heartRate,
    int spo2,
    double temperature,
    int systolicBP,
    int diastolicBP,
    int respiratoryRate
)
    : patientId(patientId),
      heartRate(heartRate),
      spo2(spo2),
      temperature(temperature),
      systolicBP(systolicBP),
      diastolicBP(diastolicBP),
      respiratoryRate(respiratoryRate),
      timestamp(generateTimestamp()) {
}


// ============================================================
// GET PATIENT ID
// ============================================================

int VitalSigns::getPatientId() const {

    return patientId;
}


// ============================================================
// GET HEART RATE
// ============================================================

int VitalSigns::getHeartRate() const {

    return heartRate;
}


// ============================================================
// GET SPO2
// ============================================================

int VitalSigns::getSpO2() const {

    return spo2;
}


// ============================================================
// GET TEMPERATURE
// ============================================================

double VitalSigns::getTemperature() const {

    return temperature;
}


// ============================================================
// GET SYSTOLIC BLOOD PRESSURE
// ============================================================

int VitalSigns::getSystolicBP() const {

    return systolicBP;
}


// ============================================================
// GET DIASTOLIC BLOOD PRESSURE
// ============================================================

int VitalSigns::getDiastolicBP() const {

    return diastolicBP;
}


// ============================================================
// GET RESPIRATORY RATE
// ============================================================

int VitalSigns::getRespiratoryRate() const {

    return respiratoryRate;
}


// ============================================================
// GET TIMESTAMP
// ============================================================

std::string VitalSigns::getTimestamp() const {

    return timestamp;
}


// ============================================================
// GENERATE CURRENT TIMESTAMP
// ============================================================

std::string VitalSigns::generateTimestamp() const {

    // --------------------------------------------------------
    // Get current system time
    // --------------------------------------------------------

    std::time_t currentTime =
        std::time(nullptr);


    // --------------------------------------------------------
    // Convert system time to local time
    // --------------------------------------------------------

    std::tm* localTime =
        std::localtime(&currentTime);


    // --------------------------------------------------------
    // Check if conversion failed
    // --------------------------------------------------------

    if (localTime == nullptr) {

        return "Unknown Time";
    }


    // --------------------------------------------------------
    // Create string stream for formatting
    // --------------------------------------------------------

    std::ostringstream stream;


    // --------------------------------------------------------
    // Format:
    //
    // YYYY-MM-DD HH:MM:SS
    //
    // Example:
    // 2026-08-03 04:15:32
    // --------------------------------------------------------

    stream << std::put_time(
        localTime,
        "%Y-%m-%d %H:%M:%S"
    );


    // Return formatted timestamp
    return stream.str();
}


// ============================================================
// DISPLAY VITAL SIGNS
// ============================================================

void VitalSigns::display() const {

    std::cout
        << "\nTimestamp        : "
        << timestamp

        << "\nHeart Rate       : "
        << heartRate
        << " bpm"

        << "\nSpO2             : "
        << spo2
        << " %"

        << "\nTemperature      : "
        << std::fixed
        << std::setprecision(1)
        << temperature
        << " C"

        << "\nBlood Pressure   : "
        << systolicBP
        << "/"
        << diastolicBP
        << " mmHg"

        << "\nRespiratory Rate : "
        << respiratoryRate
        << " breaths/min"

        << "\n";
}
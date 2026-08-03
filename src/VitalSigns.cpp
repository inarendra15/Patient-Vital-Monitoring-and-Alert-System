#include "../include/VitalSigns.h"

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>


// ============================================================
// CONSTRUCTOR FOR NEW VITAL READING
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
// PHASE 4.2
// CONSTRUCTOR FOR LOADING SAVED VITAL READING
//
// Unlike the constructor above, this constructor does NOT
// generate a new timestamp. It restores the timestamp that
// was previously saved in vitals.txt.
// ============================================================

VitalSigns::VitalSigns(
    int patientId,
    int heartRate,
    int spo2,
    double temperature,
    int systolicBP,
    int diastolicBP,
    int respiratoryRate,
    const std::string& timestamp
)
    : patientId(patientId),
      heartRate(heartRate),
      spo2(spo2),
      temperature(temperature),
      systolicBP(systolicBP),
      diastolicBP(diastolicBP),
      respiratoryRate(respiratoryRate),
      timestamp(timestamp) {

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
// GET SYSTOLIC BP
// ============================================================

int VitalSigns::getSystolicBP() const {

    return systolicBP;
}


// ============================================================
// GET DIASTOLIC BP
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

    std::time_t currentTime =
        std::time(nullptr);


    std::tm* localTime =
        std::localtime(
            &currentTime
        );


    std::ostringstream oss;


    oss << std::put_time(
        localTime,
        "%Y-%m-%d %H:%M:%S"
    );


    return oss.str();
}


// ============================================================
// DISPLAY VITAL READING
// ============================================================

void VitalSigns::display() const {

    std::cout
        << "\n-----------------------------------------\n"
        << "Patient ID       : "
        << patientId
        << "\n"

        << "Heart Rate       : "
        << heartRate
        << " bpm\n"

        << "SpO2             : "
        << spo2
        << " %\n"

        << "Temperature      : "
        << temperature
        << " C\n"

        << "Blood Pressure   : "
        << systolicBP
        << "/"
        << diastolicBP
        << " mmHg\n"

        << "Respiratory Rate : "
        << respiratoryRate
        << " breaths/min\n"

        << "Timestamp        : "
        << timestamp
        << "\n"

        << "-----------------------------------------\n";
}
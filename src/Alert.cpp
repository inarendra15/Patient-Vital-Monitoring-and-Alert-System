#include "../include/Alert.h"

#include <iostream>


// ============================================================
// CONSTRUCTOR
// ============================================================

Alert::Alert(
    int patientId,
    const std::string& vitalName,
    double value,
    AlertSeverity severity,
    const std::string& message,
    const std::string& timestamp
)
    : patientId(patientId),
      vitalName(vitalName),
      value(value),
      severity(severity),
      message(message),
      timestamp(timestamp) {
}


// ============================================================
// GETTERS
// ============================================================

int Alert::getPatientId() const {

    return patientId;
}


std::string Alert::getVitalName() const {

    return vitalName;
}


double Alert::getValue() const {

    return value;
}


AlertSeverity Alert::getSeverity() const {

    return severity;
}


std::string Alert::getMessage() const {

    return message;
}


std::string Alert::getTimestamp() const {

    return timestamp;
}


// ============================================================
// CONVERT ENUM TO STRING
// ============================================================

std::string Alert::severityToString(
    AlertSeverity severity
) {

    switch (severity) {

        case AlertSeverity::NORMAL:
            return "NORMAL";

        case AlertSeverity::WARNING:
            return "WARNING";

        case AlertSeverity::CRITICAL:
            return "CRITICAL";
    }

    return "UNKNOWN";
}


// ============================================================
// DISPLAY ALERT
// ============================================================

void Alert::display() const {

    std::cout
        << "[" << severityToString(severity) << "] "
        << vitalName
        << " = "
        << value
        << " | "
        << message
        << "\n";
}
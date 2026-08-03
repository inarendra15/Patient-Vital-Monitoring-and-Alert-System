#ifndef ALERT_H
#define ALERT_H

#include <string>


// ============================================================
// ALERT SEVERITY
// ============================================================

enum class AlertSeverity {

    NORMAL,
    WARNING,
    CRITICAL

};


// ============================================================
// ALERT CLASS
// ============================================================

class Alert {

private:

    int patientId;

    std::string vitalName;

    double value;

    AlertSeverity severity;

    std::string message;

    std::string timestamp;


public:

    Alert(
        int patientId,
        const std::string& vitalName,
        double value,
        AlertSeverity severity,
        const std::string& message,
        const std::string& timestamp
    );


    int getPatientId() const;

    std::string getVitalName() const;

    double getValue() const;

    AlertSeverity getSeverity() const;

    std::string getMessage() const;

    std::string getTimestamp() const;


    void display() const;


    static std::string severityToString(
        AlertSeverity severity
    );
};


#endif
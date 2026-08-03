#include "../include/AlertEngine.h"


// ============================================================
// CONSTRUCTOR
// ============================================================

AlertEngine::AlertEngine() {
}


// ============================================================
// HEART RATE
// ============================================================

Alert AlertEngine::evaluateHeartRate(
    const VitalSigns& reading
) const {

    int value = reading.getHeartRate();

    AlertSeverity severity = AlertSeverity::NORMAL;

    std::string message = "Heart rate within configured range.";


    if (
        value < config.heartRateCriticalLow ||
        value > config.heartRateCriticalHigh
    ) {

        severity = AlertSeverity::CRITICAL;

        message =
            "Heart rate crossed critical threshold.";
    }

    else if (
        value < config.heartRateWarningLow ||
        value > config.heartRateWarningHigh
    ) {

        severity = AlertSeverity::WARNING;

        message =
            "Heart rate crossed warning threshold.";
    }


    return Alert(
        reading.getPatientId(),
        "Heart Rate",
        value,
        severity,
        message,
        reading.getTimestamp()
    );
}


// ============================================================
// SPO2
// ============================================================

Alert AlertEngine::evaluateSpO2(
    const VitalSigns& reading
) const {

    int value = reading.getSpO2();

    AlertSeverity severity = AlertSeverity::NORMAL;

    std::string message =
        "SpO2 within configured range.";


    if (value < config.spo2CriticalLow) {

        severity = AlertSeverity::CRITICAL;

        message =
            "SpO2 crossed critical threshold.";
    }

    else if (value < config.spo2WarningLow) {

        severity = AlertSeverity::WARNING;

        message =
            "SpO2 crossed warning threshold.";
    }


    return Alert(
        reading.getPatientId(),
        "SpO2",
        value,
        severity,
        message,
        reading.getTimestamp()
    );
}


// ============================================================
// TEMPERATURE
// ============================================================

Alert AlertEngine::evaluateTemperature(
    const VitalSigns& reading
) const {

    double value =
        reading.getTemperature();


    AlertSeverity severity =
        AlertSeverity::NORMAL;


    std::string message =
        "Temperature within configured range.";


    if (
        value < config.temperatureCriticalLow ||
        value > config.temperatureCriticalHigh
    ) {

        severity = AlertSeverity::CRITICAL;

        message =
            "Temperature crossed critical threshold.";
    }

    else if (
        value < config.temperatureWarningLow ||
        value > config.temperatureWarningHigh
    ) {

        severity = AlertSeverity::WARNING;

        message =
            "Temperature crossed warning threshold.";
    }


    return Alert(
        reading.getPatientId(),
        "Temperature",
        value,
        severity,
        message,
        reading.getTimestamp()
    );
}


// ============================================================
// SYSTOLIC BP
// ============================================================

Alert AlertEngine::evaluateSystolicBP(
    const VitalSigns& reading
) const {

    int value =
        reading.getSystolicBP();


    AlertSeverity severity =
        AlertSeverity::NORMAL;


    std::string message =
        "Systolic BP within configured range.";


    if (
        value < config.systolicCriticalLow ||
        value > config.systolicCriticalHigh
    ) {

        severity = AlertSeverity::CRITICAL;

        message =
            "Systolic BP crossed critical threshold.";
    }

    else if (
        value < config.systolicWarningLow ||
        value > config.systolicWarningHigh
    ) {

        severity = AlertSeverity::WARNING;

        message =
            "Systolic BP crossed warning threshold.";
    }


    return Alert(
        reading.getPatientId(),
        "Systolic BP",
        value,
        severity,
        message,
        reading.getTimestamp()
    );
}


// ============================================================
// DIASTOLIC BP
// ============================================================

Alert AlertEngine::evaluateDiastolicBP(
    const VitalSigns& reading
) const {

    int value =
        reading.getDiastolicBP();


    AlertSeverity severity =
        AlertSeverity::NORMAL;


    std::string message =
        "Diastolic BP within configured range.";


    if (
        value < config.diastolicCriticalLow ||
        value > config.diastolicCriticalHigh
    ) {

        severity = AlertSeverity::CRITICAL;

        message =
            "Diastolic BP crossed critical threshold.";
    }

    else if (
        value < config.diastolicWarningLow ||
        value > config.diastolicWarningHigh
    ) {

        severity = AlertSeverity::WARNING;

        message =
            "Diastolic BP crossed warning threshold.";
    }


    return Alert(
        reading.getPatientId(),
        "Diastolic BP",
        value,
        severity,
        message,
        reading.getTimestamp()
    );
}


// ============================================================
// RESPIRATORY RATE
// ============================================================

Alert AlertEngine::evaluateRespiratoryRate(
    const VitalSigns& reading
) const {

    int value =
        reading.getRespiratoryRate();


    AlertSeverity severity =
        AlertSeverity::NORMAL;


    std::string message =
        "Respiratory rate within configured range.";


    if (
        value < config.respiratoryCriticalLow ||
        value > config.respiratoryCriticalHigh
    ) {

        severity = AlertSeverity::CRITICAL;

        message =
            "Respiratory rate crossed critical threshold.";
    }

    else if (
        value < config.respiratoryWarningLow ||
        value > config.respiratoryWarningHigh
    ) {

        severity = AlertSeverity::WARNING;

        message =
            "Respiratory rate crossed warning threshold.";
    }


    return Alert(
        reading.getPatientId(),
        "Respiratory Rate",
        value,
        severity,
        message,
        reading.getTimestamp()
    );
}


// ============================================================
// EVALUATE COMPLETE READING
// ============================================================

std::vector<Alert> AlertEngine::evaluate(
    const VitalSigns& reading
) const {

    std::vector<Alert> alerts;


    Alert heartRateAlert =
        evaluateHeartRate(reading);

    Alert spo2Alert =
        evaluateSpO2(reading);

    Alert temperatureAlert =
        evaluateTemperature(reading);

    Alert systolicAlert =
        evaluateSystolicBP(reading);

    Alert diastolicAlert =
        evaluateDiastolicBP(reading);

    Alert respiratoryAlert =
        evaluateRespiratoryRate(reading);


    // --------------------------------------------------------
    // Store only abnormal alerts
    // --------------------------------------------------------

    if (
        heartRateAlert.getSeverity()
        != AlertSeverity::NORMAL
    ) {

        alerts.push_back(
            heartRateAlert
        );
    }


    if (
        spo2Alert.getSeverity()
        != AlertSeverity::NORMAL
    ) {

        alerts.push_back(
            spo2Alert
        );
    }


    if (
        temperatureAlert.getSeverity()
        != AlertSeverity::NORMAL
    ) {

        alerts.push_back(
            temperatureAlert
        );
    }


    if (
        systolicAlert.getSeverity()
        != AlertSeverity::NORMAL
    ) {

        alerts.push_back(
            systolicAlert
        );
    }


    if (
        diastolicAlert.getSeverity()
        != AlertSeverity::NORMAL
    ) {

        alerts.push_back(
            diastolicAlert
        );
    }


    if (
        respiratoryAlert.getSeverity()
        != AlertSeverity::NORMAL
    ) {

        alerts.push_back(
            respiratoryAlert
        );
    }


    return alerts;
}


// ============================================================
// DISPLAY THRESHOLDS
// ============================================================

void AlertEngine::displayThresholds() const {

    config.display();
}
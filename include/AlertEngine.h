#ifndef ALERT_ENGINE_H
#define ALERT_ENGINE_H

#include "Alert.h"
#include "ThresholdConfig.h"
#include "VitalSigns.h"

#include <vector>


class AlertEngine {

private:

    ThresholdConfig config;


public:

    AlertEngine();


    // Evaluate complete vital reading
    std::vector<Alert> evaluate(
        const VitalSigns& reading
    ) const;


    // Display threshold configuration
    void displayThresholds() const;


private:

    Alert evaluateHeartRate(
        const VitalSigns& reading
    ) const;


    Alert evaluateSpO2(
        const VitalSigns& reading
    ) const;


    Alert evaluateTemperature(
        const VitalSigns& reading
    ) const;


    Alert evaluateSystolicBP(
        const VitalSigns& reading
    ) const;


    Alert evaluateDiastolicBP(
        const VitalSigns& reading
    ) const;


    Alert evaluateRespiratoryRate(
        const VitalSigns& reading
    ) const;
};


#endif
#ifndef ANALYTICS_MANAGER_H
#define ANALYTICS_MANAGER_H

#include "VitalManager.h"
#include "PatientManager.h"

#include <string>

class AnalyticsManager {

private:

    const VitalManager& vitalManager;
    const PatientManager& patientManager;

public:

    AnalyticsManager(
        const VitalManager& vm,
        const PatientManager& pm
    );

    // Overall hospital analytics
    void displayDashboard() const;

    // Patient dashboard
    void displayPatientDashboard() const;

    // ===============================
    // ReportManager helper functions
    // ===============================
    int calculateHealthScore(
        const VitalSigns& vital
    ) const;

    std::string calculateStatus(
        int score
    ) const;

};

#endif
#ifndef REPORT_MANAGER_H
#define REPORT_MANAGER_H

#include "PatientManager.h"
#include "VitalManager.h"
#include "AnalyticsManager.h"
#include "EmergencyManager.h"

#include <string>

class ReportManager {

private:

    const PatientManager& patientManager;

    const VitalManager& vitalManager;

    const AnalyticsManager& analyticsManager;

    const EmergencyManager& emergencyManager;

public:

    ReportManager(

        const PatientManager& pm,

        const VitalManager& vm,

        const AnalyticsManager& am,

        const EmergencyManager& em
    );

    bool generatePatientReport(

        int patientId

    ) const;
};

#endif
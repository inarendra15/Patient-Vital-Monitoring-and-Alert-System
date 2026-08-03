#ifndef EMERGENCY_MANAGER_H
#define EMERGENCY_MANAGER_H

#include "Patient.h"
#include "VitalSigns.h"

#include <string>
#include <vector>



// ============================================================
// EMERGENCY LEVEL
// ============================================================

enum class EmergencyLevel
{
    GREEN,
    YELLOW,
    ORANGE,
    RED
};



// ============================================================
// EMERGENCY MANAGER
// ============================================================

class EmergencyManager
{

public:

    EmergencyManager();

    EmergencyLevel determineLevel(
        const VitalSigns& vital
    ) const;

    std::string levelToString(
        EmergencyLevel level
    ) const;

    // NEW
    std::vector<std::string> recommendActions(
        EmergencyLevel level
    ) const;

    // NEW
    void displayEmergencyReport(
        const Patient& patient,
        const VitalSigns& vital
    ) const;

    // ====================================================
    // NEW
    // Save emergency report into file
    // ====================================================

    void saveEmergencyReport(
        const Patient& patient,
        const VitalSigns& vital
    ) const;
};

#endif
#include "../include/EmergencyManager.h"
#include <iostream>
#include <fstream>

// ============================================================
// CONSTRUCTOR
// ============================================================

EmergencyManager::EmergencyManager()
{

}



// ============================================================
// DETERMINE EMERGENCY LEVEL
// ============================================================

EmergencyLevel EmergencyManager::determineLevel(
    const VitalSigns& vital
) const
{

    // -------------------------------
    // RED (Critical)
    // -------------------------------

    if (

        vital.getSpO2() < 85 ||

        vital.getHeartRate() > 140 ||

        vital.getTemperature() > 39.5 ||

        vital.getSystolicBP() > 180 ||

        vital.getRespiratoryRate() > 30

    )
    {
        return EmergencyLevel::RED;
    }


    // -------------------------------
    // ORANGE
    // -------------------------------

    if (

        vital.getSpO2() < 90 ||

        vital.getHeartRate() > 120 ||

        vital.getTemperature() > 38.5 ||

        vital.getSystolicBP() > 160 ||

        vital.getRespiratoryRate() > 24

    )
    {
        return EmergencyLevel::ORANGE;
    }


    // -------------------------------
    // YELLOW
    // -------------------------------

    if (

        vital.getHeartRate() > 100 ||

        vital.getTemperature() > 37.5 ||

        vital.getRespiratoryRate() > 20

    )
    {
        return EmergencyLevel::YELLOW;
    }


    return EmergencyLevel::GREEN;
}



// ============================================================
// CONVERT LEVEL TO STRING
// ============================================================

std::string EmergencyManager::levelToString(
    EmergencyLevel level
) const
{

    switch(level)
    {

        case EmergencyLevel::GREEN:
            return "GREEN";

        case EmergencyLevel::YELLOW:
            return "YELLOW";

        case EmergencyLevel::ORANGE:
            return "ORANGE";

        case EmergencyLevel::RED:
            return "RED";
    }

    return "UNKNOWN";
}

// ============================================================
// RECOMMENDED ACTIONS
// ============================================================

std::vector<std::string>
EmergencyManager::recommendActions(
    EmergencyLevel level
) const
{

    std::vector<std::string> actions;

    switch(level)
    {

        case EmergencyLevel::GREEN:

            actions.push_back(
                "Continue routine monitoring."
            );

            break;



        case EmergencyLevel::YELLOW:

            actions.push_back(
                "Increase observation frequency."
            );

            actions.push_back(
                "Inform nursing staff."
            );

            break;



        case EmergencyLevel::ORANGE:

            actions.push_back(
                "Notify attending doctor."
            );

            actions.push_back(
                "Administer oxygen if required."
            );

            actions.push_back(
                "Prepare emergency medication."
            );

            break;



        case EmergencyLevel::RED:

            actions.push_back(
                "Notify ICU immediately."
            );

            actions.push_back(
                "Call emergency response team."
            );

            actions.push_back(
                "Prepare ventilator support."
            );

            actions.push_back(
                "Continuous cardiac monitoring."
            );

            actions.push_back(
                "Prepare emergency medication."
            );

            break;
    }

    return actions;
}
// ============================================================
// DISPLAY EMERGENCY REPORT
// ============================================================

void EmergencyManager::displayEmergencyReport(

    const Patient& patient,

    const VitalSigns& vital

) const
{

    EmergencyLevel level =
        determineLevel(vital);

    std::vector<std::string> actions =
        recommendActions(level);

    std::cout
        << "\n=========================================\n"
        << "        EMERGENCY RESPONSE REPORT\n"
        << "=========================================\n";

    std::cout

        << "Patient ID      : "
        << patient.getPatientId()

        << "\nPatient Name    : "
        << patient.getName()

        << "\nEmergency Level : "
        << levelToString(level)

        << "\n\nRecommended Actions\n"
        << "----------------------------\n";

    for (const std::string& action : actions)
    {
        std::cout
            << "* "
            << action
            << '\n';
    }

    std::cout
        << "=========================================\n";
}

// ============================================================
// SAVE EMERGENCY REPORT
// ============================================================

void EmergencyManager::saveEmergencyReport(

    const Patient& patient,

    const VitalSigns& vital

) const
{

    std::ofstream file(

        "data/emergency.txt",

        std::ios::app
    );

    if (!file)
    {
        return;
    }

    EmergencyLevel level =
        determineLevel(vital);

    std::vector<std::string> actions =
        recommendActions(level);

    file
        << "=========================================\n"

        << "Timestamp : "
        << vital.getTimestamp()

        << "\nPatient ID : "
        << patient.getPatientId()

        << "\nPatient Name : "
        << patient.getName()

        << "\nEmergency Level : "
        << levelToString(level)

        << "\n\nRecommended Actions\n"
        << "----------------------------\n";

    for (const std::string& action : actions)
    {
        file
            << "- "
            << action
            << '\n';
    }

    file
        << "=========================================\n\n";

    file.close();
}
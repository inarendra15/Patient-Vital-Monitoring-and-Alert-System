#include "../include/EmergencyStatistics.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// ==========================================================
// DISPLAY EMERGENCY STATISTICS
// ==========================================================

void EmergencyStatistics::displayStatistics() const {

    std::ifstream file("data/emergency.txt");

    std::cout
        << "\n=========================================\n"
        << "        EMERGENCY STATISTICS\n"
        << "=========================================\n";

    if (!file.is_open()) {

        std::cout
            << "No emergency records found.\n";

        return;
    }

    std::string line;

    int green = 0;
    int yellow = 0;
    int orange = 0;
    int red = 0;

    while (std::getline(file, line)) {

        if (line.find("Emergency Level") != std::string::npos) {

            if (line.find("GREEN") != std::string::npos)
                green++;

            else if (line.find("YELLOW") != std::string::npos)
                yellow++;

            else if (line.find("ORANGE") != std::string::npos)
                orange++;

            else if (line.find("RED") != std::string::npos)
                red++;
        }
    }

    file.close();

    int total =
        green +
        yellow +
        orange +
        red;

    if (total == 0) {

        std::cout
            << "No emergency records available.\n";

        return;
    }

    double criticalPercentage =
        (static_cast<double>(red) / total) * 100.0;

    std::string mostFrequent = "GREEN";
    int maxCount = green;

    if (yellow > maxCount) {

        maxCount = yellow;
        mostFrequent = "YELLOW";
    }

    if (orange > maxCount) {

        maxCount = orange;
        mostFrequent = "ORANGE";
    }

    if (red > maxCount) {

        maxCount = red;
        mostFrequent = "RED";
    }

    std::cout
        << std::fixed
        << std::setprecision(2);

    std::cout
        << "\nTotal Emergency Reports : "
        << total

        << "\n\nGREEN  : "
        << green

        << "\nYELLOW : "
        << yellow

        << "\nORANGE : "
        << orange

        << "\nRED    : "
        << red

        << "\n\nCritical Percentage : "
        << criticalPercentage
        << " %"

        << "\nMost Frequent Level : "
        << mostFrequent

        << "\n=========================================\n";
}
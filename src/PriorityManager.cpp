#include "../include/PriorityManager.h"

#include <iostream>
#include <iomanip>



// ==========================================================
// Constructor
// ==========================================================

PriorityManager::PriorityManager(

    const PatientManager& pm,

    const VitalManager& vm

)

    : patientManager(pm),

      vitalManager(vm)

{

}



// ==========================================================
// Calculate Health Score
//
// Same logic used in AnalyticsManager
// ==========================================================

static int calculateHealthScore(

    const VitalSigns& vital

)

{

    int score = 100;

    if (vital.getHeartRate() < 60 ||
        vital.getHeartRate() > 100)

        score -= 15;

    if (vital.getSpO2() < 90)

        score -= 30;

    if (vital.getTemperature() < 36 ||
        vital.getTemperature() > 38)

        score -= 15;

    if (vital.getSystolicBP() < 90 ||
        vital.getSystolicBP() > 140)

        score -= 20;

    if (vital.getDiastolicBP() < 60 ||
        vital.getDiastolicBP() > 90)

        score -= 10;

    if (vital.getRespiratoryRate() < 12 ||
        vital.getRespiratoryRate() > 20)

        score -= 10;

    if (score < 0)

        score = 0;

    return score;
}



// ==========================================================
// Convert score into health status
// ==========================================================

static std::string calculateStatus(

    int score

)

{

    if (score >= 90)

        return "HEALTHY";

    if (score >= 70)

        return "STABLE";

    if (score >= 50)

        return "OBSERVATION";

    if (score >= 30)

        return "HIGH RISK";

    return "CRITICAL";
}



// ==========================================================
// Display Critical Patients
// ==========================================================

void PriorityManager::displayCriticalPatients() const

{

    std::priority_queue<
        PatientPriority,
        std::vector<PatientPriority>,
        ComparePriority
    > pq;



    // ---------------------------------------------
    // Build Priority Queue
    // ---------------------------------------------

    for (const Patient& patient : patientManager.getPatients()) {

        const VitalSigns* vital =
            vitalManager.getLatestReadingForPatient(
                patient.getPatientId()
            );

        if (vital == nullptr)
            continue;

        int score =
            calculateHealthScore(*vital);

        PatientPriority node;

        node.patientId =
            patient.getPatientId();

        node.patientName =
            patient.getName();

        node.healthScore =
            score;

        node.status =
            calculateStatus(score);

        pq.push(node);
    }



    std::cout
        << "\n=============================================\n"
        << "     CRITICAL PATIENT PRIORITY QUEUE\n"
        << "=============================================\n";



    if (pq.empty()) {

        std::cout
            << "No patient vitals available.\n";

        return;
    }



    std::cout

        << std::left

        << std::setw(10) << "Rank"

        << std::setw(12) << "PatientID"

        << std::setw(20) << "Name"

        << std::setw(10) << "Score"

        << "Status\n";



    std::cout

        << "-------------------------------------------------------------\n";



    int rank = 1;



    while (!pq.empty()) {

        PatientPriority p = pq.top();

        pq.pop();

        std::cout

            << std::left

            << std::setw(10) << rank

            << std::setw(12) << p.patientId

            << std::setw(20) << p.patientName

            << std::setw(10) << p.healthScore

            << p.status

            << '\n';

        rank++;
    }

    std::cout

        << "=============================================================\n";
}
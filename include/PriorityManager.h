#ifndef PRIORITY_MANAGER_H
#define PRIORITY_MANAGER_H

#include "PatientManager.h"
#include "VitalManager.h"

#include <queue>
#include <vector>
#include <string>

// =======================================================
// Information stored inside the priority queue
// =======================================================

struct PatientPriority {

    int patientId;

    std::string patientName;

    int healthScore;

    std::string status;
};

// =======================================================
// Comparator
//
// Lower health score means higher priority.
//
// Example:
//
// Score 0   -> highest priority
// Score 20  -> second
// Score 80  -> later
// =======================================================

struct ComparePriority {

    bool operator()(

        const PatientPriority& a,
        const PatientPriority& b

    ) const {

        return a.healthScore > b.healthScore;
    }
};

// =======================================================
// Priority Manager
// =======================================================

class PriorityManager {

private:

    const PatientManager& patientManager;

    const VitalManager& vitalManager;

public:

    PriorityManager(

        const PatientManager& pm,

        const VitalManager& vm
    );

    void displayCriticalPatients() const;
};

#endif
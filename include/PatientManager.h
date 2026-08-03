#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "Patient.h"
#include <unordered_map>
#include <cstddef>
#include <string>
#include <vector>

class PatientManager {

private:

    std::vector<Patient> patients;
    std::unordered_map<int, std::size_t> patientIndex;
    int nextPatientId;

public:

    // Constructor
    PatientManager();

    // Register a new patient
    void addPatient(
        const std::string& name,
        int age,
        const std::string& gender
    );

    // Search patient by ID
    Patient* searchPatient(
        int patientId
    );

    // Display all registered patients
    void displayAllPatients() const;

    // Total patient count
    int getPatientCount() const;

    // Return latest registered patient
    const Patient* getLatestPatient() const;

    // Load patient from persistent storage
    void loadPatient(
        const Patient& patient
    );

    // =====================================================
    // PHASE 6.2
    // Return all patients (Read-only)
    // Used by AnalyticsManager
    // =====================================================
    const std::vector<Patient>& getPatients() const;
};

#endif
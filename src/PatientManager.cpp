#include "../include/PatientManager.h"

#include <iostream>
#include <iomanip>


// --------------------------------------------
// Constructor
// --------------------------------------------

PatientManager::PatientManager()
    : nextPatientId(1001) {
}


// --------------------------------------------
// Add a new patient
// --------------------------------------------

void PatientManager::addPatient(
    const std::string& name,
    int age,
    const std::string& gender
) {

    // Validate name
    if (name.empty()) {
        std::cout << "Error: Patient name cannot be empty.\n";
        return;
    }

    // Validate age
    if (age <= 0 || age > 120) {
        std::cout << "Error: Invalid patient age.\n";
        return;
    }

    // Validate gender
    if (gender.empty()) {
        std::cout << "Error: Gender cannot be empty.\n";
        return;
    }


    // Create a new Patient object
    Patient newPatient(
        nextPatientId,
        name,
        age,
        gender
    );


    // Store patient inside vector
    patients.push_back(newPatient);


    std::cout
        << "\nPatient registered successfully.\n"
        << "Patient ID: "
        << nextPatientId
        << "\n";


    // Generate next unique ID
    nextPatientId++;
}


// --------------------------------------------
// Search patient by ID
// --------------------------------------------

Patient* PatientManager::searchPatient(int patientId) {

    // Traverse all patients
    for (Patient& patient : patients) {

        // Check whether ID matches
        if (patient.getPatientId() == patientId) {

            // Return address of matching patient
            return &patient;
        }
    }

    // Patient not found
    return nullptr;
}


// --------------------------------------------
// Display all registered patients
// --------------------------------------------

void PatientManager::displayAllPatients() const {

    // Check whether vector is empty
    if (patients.empty()) {

        std::cout
            << "\nNo patients registered.\n";

        return;
    }


    // Table heading
    std::cout << "\n";

    std::cout
        << std::left
        << std::setw(12) << "ID"
        << std::setw(25) << "Name"
        << std::setw(10) << "Age"
        << std::setw(15) << "Gender"
        << '\n';


    std::cout
        << "----------------------------------------------------------\n";


    // Display each patient
    for (const Patient& patient : patients) {

        patient.display();
    }
}


// --------------------------------------------
// Return total number of patients
// --------------------------------------------

int PatientManager::getPatientCount() const {

    return static_cast<int>(patients.size());
}
// ============================================================
// GET LATEST REGISTERED PATIENT
// ============================================================

const Patient* PatientManager::getLatestPatient() const {

    if (patients.empty()) {

        return nullptr;
    }

    return &patients.back();
}

// ============================================================
// LOAD PATIENT FROM PERSISTENT STORAGE
// ============================================================

void PatientManager::loadPatient(
    const Patient& patient
) {

    patients.push_back(patient);


    // --------------------------------------------------------
    // Maintain ID continuity
    //
    // Example:
    //
    // Saved patients:
    // 1001
    // 1002
    // 1003
    //
    // nextPatientId must become 1004
    // --------------------------------------------------------

    if (patient.getPatientId() >= nextPatientId) {

        nextPatientId =
            patient.getPatientId() + 1;
    }
}
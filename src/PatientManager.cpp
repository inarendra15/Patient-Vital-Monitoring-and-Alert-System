#include "../include/PatientManager.h"

#include <iostream>
#include <iomanip>


// ============================================================
// CONSTRUCTOR
// ============================================================

PatientManager::PatientManager()
    : nextPatientId(1001) {

}


// ============================================================
// ADD / REGISTER NEW PATIENT
// ============================================================

void PatientManager::addPatient(
    const std::string& name,
    int age,
    const std::string& gender
) {

    Patient patient(
        nextPatientId,
        name,
        age,
        gender
    );


    // Add patient to primary storage
    patients.push_back(patient);


    // ========================================================
    // PHASE 5
    // Build hash index:
    //
    // Patient ID -> vector position
    // ========================================================

    patientIndex[nextPatientId] =
        patients.size() - 1;


    std::cout
        << "\nPatient registered successfully.\n"
        << "Patient ID: "
        << nextPatientId
        << "\n";


    nextPatientId++;
}


// ============================================================
// SEARCH PATIENT
// PHASE 5: Average O(1) hash-table lookup
// ============================================================

Patient* PatientManager::searchPatient(
    int patientId
) {

    auto it =
        patientIndex.find(patientId);


    // Patient ID does not exist
    if (it == patientIndex.end()) {

        return nullptr;
    }


    // Retrieve vector position from hash table
    std::size_t index =
        it->second;


    return &patients[index];
}


// ============================================================
// DISPLAY ALL PATIENTS
// ============================================================

void PatientManager::displayAllPatients() const {

    if (patients.empty()) {

        std::cout
            << "\nNo patients registered.\n";

        return;
    }


    std::cout
        << "\n"
        << std::left
        << std::setw(12) << "ID"
        << std::setw(25) << "Name"
        << std::setw(10) << "Age"
        << std::setw(15) << "Gender"
        << "\n";


    std::cout
        << "----------------------------------------------------------\n";


    for (const Patient& patient : patients) {

        patient.display();
    }
}


// ============================================================
// GET NUMBER OF PATIENTS
// ============================================================

int PatientManager::getPatientCount() const {

    return static_cast<int>(
        patients.size()
    );
}


// ============================================================
// GET MOST RECENTLY ADDED PATIENT
// ============================================================

const Patient*
PatientManager::getLatestPatient() const {

    if (patients.empty()) {

        return nullptr;
    }


    return &patients.back();
}


// ============================================================
// LOAD PATIENT FROM PERSISTENT STORAGE
//
// PHASE 4: Restore patient from file
// PHASE 5: Rebuild hash index
// ============================================================

void PatientManager::loadPatient(
    const Patient& patient
) {

    // Add restored patient to vector
    patients.push_back(patient);


    // ========================================================
    // PHASE 5
    // Reconstruct hash index
    //
    // Patient ID -> vector position
    // ========================================================

    patientIndex[patient.getPatientId()] =
        patients.size() - 1;


    // ========================================================
    // Restore correct next patient ID
    //
    // Example:
    //
    // File contains:
    // 1001
    // 1002
    //
    // nextPatientId becomes 1003
    // ========================================================

    if (patient.getPatientId() >= nextPatientId) {

        nextPatientId =
            patient.getPatientId() + 1;
    }    
}

// ============================================================
// PHASE 6.2
// RETURN ALL REGISTERED PATIENTS
// ============================================================

const std::vector<Patient>&
PatientManager::getPatients() const
{
    return patients;
}
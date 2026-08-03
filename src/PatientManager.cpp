#include "../include/PatientManager.h"

#include <iostream>
#include <iomanip>

// ============================================================
// CONSTRUCTOR
// ============================================================

PatientManager::PatientManager()
    : nextPatientId(1001)
{

}

// ============================================================
// ADD PATIENT
// ============================================================

void PatientManager::addPatient(
    const std::string& name,
    int age,
    const std::string& gender
)
{
    Patient patient(
        nextPatientId,
        name,
        age,
        gender
    );

    patients.push_back(patient);

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
// ============================================================

Patient* PatientManager::searchPatient(
    int patientId
)
{
    auto it =
        patientIndex.find(patientId);

    if (it == patientIndex.end()) {

        return nullptr;
    }

    return &patients[it->second];
}

// ============================================================
// CONST SEARCH PATIENT
// ============================================================

const Patient* PatientManager::searchPatient(
    int patientId
) const
{
    auto it =
        patientIndex.find(patientId);

    if (it == patientIndex.end()) {

        return nullptr;
    }

    return &patients[it->second];
}

// ============================================================
// DISPLAY ALL PATIENTS
// ============================================================

void PatientManager::displayAllPatients() const
{
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
// GET PATIENT COUNT
// ============================================================

int PatientManager::getPatientCount() const
{
    return static_cast<int>(
        patients.size()
    );
}

// ============================================================
// GET LATEST REGISTERED PATIENT
// ============================================================

const Patient*
PatientManager::getLatestPatient() const
{
    if (patients.empty()) {

        return nullptr;
    }

    return &patients.back();
}

// ============================================================
// LOAD PATIENT
// ============================================================

void PatientManager::loadPatient(
    const Patient& patient
)
{
    patients.push_back(patient);

    patientIndex[
        patient.getPatientId()
    ] = patients.size() - 1;

    if (patient.getPatientId() >= nextPatientId) {

        nextPatientId =
            patient.getPatientId() + 1;
    }
}

// ============================================================
// RETURN ALL PATIENTS
// ============================================================

const std::vector<Patient>&
PatientManager::getPatients() const
{
    return patients;
}
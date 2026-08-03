#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "Patient.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <cstddef>

class PatientManager {

private:

    // ========================================================
    // PRIMARY STORAGE
    // ========================================================

    std::vector<Patient> patients;

    // ========================================================
    // HASH TABLE
    // Patient ID -> index in patients vector
    // ========================================================

    std::unordered_map<
        int,
        std::size_t
    > patientIndex;

    // ========================================================
    // AUTO PATIENT ID GENERATOR
    // ========================================================

    int nextPatientId;

public:

    // ========================================================
    // CONSTRUCTOR
    // ========================================================

    PatientManager();

    // ========================================================
    // REGISTER PATIENT
    // ========================================================

    void addPatient(
        const std::string& name,
        int age,
        const std::string& gender
    );

    // ========================================================
    // SEARCH PATIENT
    // ========================================================

    Patient* searchPatient(
        int patientId
    );

    // Read-only overload
    const Patient* searchPatient(
        int patientId
    ) const;

    // ========================================================
    // DISPLAY ALL PATIENTS
    // ========================================================

    void displayAllPatients() const;

    // ========================================================
    // GET PATIENT COUNT
    // ========================================================

    int getPatientCount() const;

    // ========================================================
    // GET LATEST REGISTERED PATIENT
    // ========================================================

    const Patient* getLatestPatient() const;

    // ========================================================
    // LOAD PATIENT FROM FILE
    // ========================================================

    void loadPatient(
        const Patient& patient
    );

    // ========================================================
    // RETURN ALL REGISTERED PATIENTS
    // ========================================================

    const std::vector<Patient>&
    getPatients() const;
};

#endif
#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "Patient.h"

#include <string>
#include <vector>
#include <unordered_map>


class PatientManager {

private:

    // Primary patient storage
    std::vector<Patient> patients;


    // ========================================================
    // PHASE 5
    // HASH-BASED PATIENT INDEX
    //
    // patientId -> position inside patients vector
    // ========================================================

    std::unordered_map<int, std::size_t> patientIndex;


    int nextPatientId;


public:

    PatientManager();


    void addPatient(
        const std::string& name,
        int age,
        const std::string& gender
    );


    // Average O(1) lookup using unordered_map
    Patient* searchPatient(
        int patientId
    );


    void displayAllPatients() const;


    int getPatientCount() const;


    const Patient* getLatestPatient() const;


    // Load patient from persistent storage
    void loadPatient(
        const Patient& patient
    );
};


#endif
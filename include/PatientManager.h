#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "Patient.h"

#include <string>
#include <vector>


class PatientManager {

private:

    std::vector<Patient> patients;

    int nextPatientId;


public:

    PatientManager();


    void addPatient(
        const std::string& name,
        int age,
        const std::string& gender
    );


    Patient* searchPatient(
        int patientId
    );


    void displayAllPatients() const;


    int getPatientCount() const;


    const Patient* getLatestPatient() const;


    // Phase 4.2
    void loadPatient(
        const Patient& patient
    );
};


#endif
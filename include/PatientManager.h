#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include "Patient.h"

#include <vector>
#include <string>


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


    Patient* searchPatient(int patientId);


    void displayAllPatients() const;


    int getPatientCount() const;
};


#endif
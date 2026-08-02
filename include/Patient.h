#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
private:
    int patientId;
    std::string name;
    int age;
    std::string gender;

public:
    // Default constructor
    Patient();

    // Parameterized constructor
    Patient(int id,
            const std::string& name,
            int age,
            const std::string& gender);

    // Getter functions
    int getPatientId() const;
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;

    // Display patient information
    void display() const;
};

#endif
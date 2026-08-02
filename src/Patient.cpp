#include "../include/Patient.h"
#include <iostream>
#include <iomanip>

// Default constructor
Patient::Patient()
    : patientId(0), name(""), age(0), gender("") {
}


// Parameterized constructor
Patient::Patient(
    int id,
    const std::string& name,
    int age,
    const std::string& gender
)
    : patientId(id),
      name(name),
      age(age),
      gender(gender) {
}


// Getter for Patient ID
int Patient::getPatientId() const {
    return patientId;
}


// Getter for name
std::string Patient::getName() const {
    return name;
}


// Getter for age
int Patient::getAge() const {
    return age;
}


// Getter for gender
std::string Patient::getGender() const {
    return gender;
}


// Display patient information
void Patient::display() const {

    std::cout
        << std::left
        << std::setw(12) << patientId
        << std::setw(25) << name
        << std::setw(10) << age
        << std::setw(15) << gender
        << '\n';
}
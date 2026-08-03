#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Patient.h"
#include "VitalSigns.h"
#include "Alert.h"

#include <string>
#include <vector>


class FileManager {

private:

    std::string patientFile;
    std::string vitalFile;
    std::string alertFile;


public:

    // Constructor
    FileManager();


    // ========================================================
    // SAVE OPERATIONS
    // ========================================================

    bool savePatient(
        const Patient& patient
    ) const;


    bool saveVitalSigns(
        const VitalSigns& vital
    ) const;


    bool saveAlert(
        const Alert& alert
    ) const;


    // ========================================================
    // LOAD OPERATIONS
    // ========================================================

    std::vector<Patient>
    loadPatients() const;


    std::vector<VitalSigns>
    loadVitalSigns() const;
};


#endif
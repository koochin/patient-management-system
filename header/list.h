#pragma once

#include "patient.h"
#include <string>
#include <vector>

class List {
private:
    std::vector<Patient> patients;
    int patientCount = 0;
    int capacity;

public:
    List(int size);
    int getPatientCount() const;
    bool insertPatient(const Patient& newPatient);
    bool removePatient(const Patient& removedPatient);
    void removeAll();
    Patient* searchPatient(Patient& target);
    void printPatients();
};

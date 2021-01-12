#include "../header/list.h"
#include <iostream>

List::List(int size) : patientCount(0), capacity(size) {patients.resize(size);}

int List::getPatientCount() const {
    return patientCount;
}

bool List::insertPatient(const Patient& newPatient) {
    if (patientCount < capacity) {
        for (int index = 0; index < getPatientCount(); index++) {
            if (patients[index].getCareCard() < newPatient.getCareCard()) {
                for (int shift = getPatientCount(); shift > index; shift--) {
                    patients[shift] = patients[shift - 1];
                }
                patients[index] = newPatient;
                patientCount++;
                return true;
            }
            if (patients[index] == newPatient) {
                return false;
            }
        }
        patients[getPatientCount()] = newPatient;
        patientCount++;
        return true;
    }
    return false;
}

bool List::removePatient(const Patient& removedPatient) {
    for (int index = 0; index < getPatientCount(); index++) {
        if (patients[index] == removedPatient) {
            for (int shift = index + 1; shift < patientCount; shift++) {
                patients[shift - 1] = patients[shift];
            }
            patientCount--;
            return true;
        }
    }
    return false;
}

void List::removeAll() {
    patientCount = 0;
}

Patient* List::searchPatient(Patient& target) {
    for (int index = 0; index < getPatientCount(); index++) {
        if (patients[index] == target) {
            return &patients[index];
        }
    }
    return nullptr;
}

void List::printPatients() {
    for (int index = 0; index < getPatientCount(); index++) {
        patients[index].printPatient();
    }
}

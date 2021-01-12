#include "../header/patient.h"
#include "../header/list.h"
#include <iostream>


bool add(List& patients) {
    std::cout << "Enter care card number (10 digits): " << std::endl;
    std::string careCard = "";
    std::cin >> careCard;
    if (careCard == "") {
        std::cout << "Failed processing care card" << std::endl;
        return false;
    }
    Patient patient = Patient(careCard);
    if (patients.insertPatient(patient)) {
        std::cout << "Registered successfully" << std::endl;
        patients.searchPatient(patient)->printPatient();
        return true;
    }
    else {
        std::cout << "Failed registering patient" << std::endl;
        return false;
    }
}


bool remove(List& patients) {
    std::cout << "Enter patient's care card number: " << std::endl;
    std::string careCard = "";
    std::cin >> careCard;
    if (careCard == "") {
        std::cout << "Error reading care card" << std::endl;
        return false;
    }
    Patient patient = Patient(careCard);
    if (patients.removePatient(patient)) {
        std::cout << "Patient successfully removed" << std::endl;
        patients.printPatients();
        return true;

    }
    else {
        std::cout << "Failed removing patient" << std::endl;
        return false;
    }
}


bool update(List& patients) {
    std::cout << "Enter care card number (10 digits): " << std::endl;
    std::string careCard = "";
    std::cin >> careCard;
    if (careCard == "") {
        std::cout << "Failed processing care card" << std::endl;
        return false;
    }
    Patient p = Patient(careCard);
    Patient* patient = patients.searchPatient(p);
    if (patient != nullptr) {
        std::cout << "Found patient" << std::endl;
        bool active = true;
        while (active) {
			std::string value = "";
			std::cout << std::endl << "Select a field to edit:"
                      << std::endl
			          << "(N) Name" << std::endl
			          << "(A) Address" << std::endl
			          << "(P) Phone Number" << std::endl
			          << "(E) E-mail" << std::endl
                      << "(X) Exit" << std::endl << std::endl
                      << "Enter choice: ";
			char choice;
            std::cin >> choice;
            if (!std::isalpha(choice)) {
                continue;
            }
			// Process user's input and request patient's updated information
			std::cin.ignore();
			switch(choice) {
	            case 'n': 
	            	std::cout << std::endl << "Enter name: " << std::endl;
	            	std::getline(std::cin, value);
	            	patient->setName(value);
	            	break;

	            case 'a': 
	            	std::cout << std::endl << "Enter address: " << std::endl;
	            	std::getline(std::cin, value);
	            	patient->setAddress(value); 
	            	break;

	            case 'p': 
	            	std::cout << std::endl << "Enter phone number: " << std::endl;
	            	std::getline(std::cin, value);
	            	patient->setPhoneNumber(value); 
	            	break;

	            case 'e': 
	            	std::cout << std::endl << "Enter email: " << std::endl;
	            	std::getline(std::cin, value);
	            	patient->setEmail(value); 
	            	break;

	            case 'x': 
                    std::cout << std::endl << "Exiting..." << std::endl; 
	            	active = false;
	            	break;

	            default: std::cout << std::endl 
                                   << "Error: please enter the corresponding character" 
                                   << std::endl;
            }
        }
        patient->printPatient();
        return true;
    }
    std::cout << "Failed to find patient" << std::endl;
    return false;
}


bool search(List& patients) {
    std::cout << "Enter care card number (10 digits): " << std::endl;
    std::string careCard = "";
    std::cin >> careCard;
    if (careCard == "") {
        std::cout << "Failed processing care card" << std::endl;
        return false;
    }
    Patient p = Patient(careCard);
    Patient* patient = patients.searchPatient(p);
    if (patient == nullptr) {
        std::cout << "Failed finding patient" << std::endl;
        return false;
    }
    std::cout << "Patient found" << std::endl;
    patient->printPatient();
    return true;
}

void print(List& patients) {
    if (patients.getPatientCount()) {
        std::cout << "Printing all patients" << std::endl;
        patients.printPatients();
    }
    else {
        std::cout << std::endl << "The system is empty" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    // the maximum size of the underlying list
    int numberOfPatients = 5;
    // initialize our List ADT of Patient data type
    List patients = List(numberOfPatients);
    
    bool menu = true;
    while (menu) {
        std::cout << std::endl 
                  << "Patient Management System:" << std::endl
		          << "(A) Add patient" << std::endl
                  << "(R) Remove patient" << std::endl
                  << "(U) Update patient" << std::endl
                  << "(S) Search for patient" << std::endl
                  << "(D) Display all patients" << std::endl
                  << "(X) Exit" << std::endl << std::endl
                  << "Enter choice: ";
        char input;
		std::cin >> input;
        if (!std::isalpha(input)) {
            continue;
        }
		// Process user's input
		switch(tolower(input)) {
            case 'a': 
                add(patients); 
            	break;

            case 'r': 
                remove(patients); 
            	break;

            case 'u': 
                update(patients); 
            	break;

            case 's': 
                search(patients); 
            	break;

            case 'd': 
                print(patients); 
            	break;

            case 'x': 
                std::cout << std::endl << "Exiting..." << std::endl;
            	menu = false;
                system("clear");
            	break;

            default: 
                std::cout << std::endl << "Error: please enter the corresponding character" 
                          << std::endl << std::endl;
        }
    }
}

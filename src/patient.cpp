#include "../header/patient.h"
#include <iostream>
#include <string>
#include <locale>

Patient::Patient() {
    careCard = "";
    name = "";
    address = "";
    phoneNumber = "";
    email = "";
}

Patient::Patient(std::string careCard) {
    this->careCard = careCard;
    name = "";
    address = "";
    phoneNumber = "";
    email = "";
}

std::string Patient::getCareCard() const {
    return careCard;
}

std::string Patient::getName() const {
    return name;
}

std::string Patient::getAddress() const {
    return address;
}

std::string Patient::getPhoneNumber() const {
    return phoneNumber;
}

std::string Patient::getEmail() const {
    return email;
}

void Patient::setCareCard(const std::string careCard) {
    this->careCard = careCard;
}

void Patient::setName(const std::string name) {
    this->name = name;
}

void Patient::setAddress(const std::string address) {
    this->address = address;
}

void Patient::setPhoneNumber(const std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Patient::setEmail(const std::string email) {
    this->email = email;
}

void Patient::printPatient() {
    std::cout << std::endl 
              << "Patient " << std::endl
              << "Care Card: "      << getCareCard()    << std::endl
              << "Name: "           << getName()        << std::endl
              << "Address: "        << getAddress()     << std::endl
              << "Phone Number: "   << getPhoneNumber() << std::endl
              << "Email: "          << getEmail()       << std::endl
              << std::endl;
}

bool Patient::operator == (const Patient& rhs) {
    return this->getCareCard() == rhs.getCareCard();
}

bool Patient::operator > (const Patient& rhs) {
    return this->getCareCard() > rhs.getCareCard();
}

std::ostream &operator << (std::ostream &os, const Patient& p) {
    os << p.getCareCard()    << std::endl
       << p.getName()        << std::endl
       << p.getAddress()     << std::endl
       << p.getPhoneNumber() << std::endl
       << p.getEmail()       << std::endl
       << std::endl;
    return os;
}

#pragma once

#include <string>

class Patient {
private:
    std::string careCard = "";
    std::string name = "";
    std::string address = "";
    std::string phoneNumber = "";
    std::string email = "";

public:
    Patient();
    Patient(std::string careCard);

    std::string getCareCard() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;

    void setCareCard(const std::string careCard);
    void setName(const std::string name);
    void setAddress(const std::string address);
    void setPhoneNumber(const std::string phoneNumber);
    void setEmail(const std::string email);

    bool operator == (const Patient& rhs);
    bool operator > (const Patient& rhs);

    void printPatient();

    friend std::ostream & operator << (std::string &os, const Patient& p);
};

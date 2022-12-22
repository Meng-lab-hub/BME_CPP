//
//  nurse.cpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "nurse.hpp"


// a default construction
Nurse::Nurse() : Person() {
    setSalary("");
    setEmail("");
}


// -----------------------   all functions to set a value to each private attributes --------------------------
void Nurse::setSalary(std::string salary) {
    this->salary = salary;
}

void Nurse::setEmail(std::string email) {
    this->email = email;
}


// -----------------------   all functions to get a value of each private attributes --------------------------
std::string Nurse::getSalary(void) const {
    return salary;
}
std::string Nurse::getEmail(void) const {
    return email;
}


// --------------- a function to print an additional attributes of this class, that a base class Person does not have -------------
std::ostream& Nurse::print(std::ostream& os) const {
    os << "    Salary: " << getSalary() << std::endl;
    os << "    Email: " << getEmail() << std::endl << std::endl;
    
    os << "    -------------------------------------------------    " << std::endl;
    return os;
}

// --------------- a function to set an infomation to a attributes of this class, that a base class Person does not have ---------------
void Nurse::getInfo(std::istream& is) {
    std::string tempSalary;
    std::cout << "    Salary: ";
    std::getline(is >> std::ws, tempSalary);
    this->setSalary(tempSalary);
    
    std::string tempEmail;
    std::cout << "    Email: ";
    std::getline(is >> std::ws, tempEmail);
    this->setEmail(tempEmail);
}

// --------------- a function to save all infomation of this class (including a infomation of base class) into a file ---------------
void Nurse::save(std::ostream& os) {
    os << getName() << std::endl << getAge() << std::endl << getID() << std::endl << getAddress() << std::endl << getGender()
       << std::endl << getContact() << std::endl << getDateOfBirth() << std::endl << getDateOfMoveIn() << std::endl << getSalary()
       << std::endl << getEmail() << std::endl;
}


// --------------- a function to load all infomation of this class (including a infomation of base class) from a file ---------------
void Nurse::load(std::istream& is) {

    std::string tempName;
    std::getline(is >> std::ws, tempName);
    
    int tempAge;
    is >> tempAge;
    
    std::string tempID;
    std::getline(is >> std::ws, tempID);
    
    std::string tempAddress;
    std::getline(is >> std::ws, tempAddress);
    
    std::string tempGender;
    std::getline(is >> std::ws, tempGender);
    
    std::string tempContact;
    std::getline(is >> std::ws, tempContact);
    
    std::string tempDOB;
    std::getline(is >> std::ws, tempDOB);
    
    std::string tempDOM;
    std::getline(is >> std::ws, tempDOM);
    
    std::string tempSalary;
    std::getline(is >> std::ws, tempSalary);
    
    std::string tempEmail;
    std::getline(is >> std::ws, tempEmail);
    
    
    // if an opened file is read properly (with a correct format) then set its attributes as the informations that it read from a file
    if (is) {
        this->setName(tempName);
        this->setAge(tempAge);
        this->setID(tempID);
        this->setAddress(tempAddress);
        this->setGender(tempGender);
        this->setContact(tempContact);
        this->setDateOfBirth(tempDOB);
        this->setDateOfMoveIn(tempDOM);
        
        this->setSalary(tempSalary);
        this->setEmail(tempEmail);
    } else {
        // else print an errors
        std::cerr << "Error in input format." << std::endl;
    }
}


// ---------------- an operator overloading to compare 2 instances of this class ---------------
bool Nurse::operator==(const Person* other) {
    if (this->getName() != other->getName()) {
        return false;
    }
    if (this->getAge() != other->getAge()) {
        return false;
    }
    if (this->getID() != other->getID()) {
        return false;
    }
    if (this->getAddress() != other->getAddress()) {
        return false;
    }
    if (this->getGender() != other->getGender()) {
        return false;
    }
    if (this->getContact() != other->getContact()) {
        return false;
    }
    if (this->getDateOfBirth() != other->getDateOfBirth()) {
        return false;
    }
    if (this->getDateOfMoveIn() != other->getDateOfMoveIn()) {
        return false;
    }
    
    
    if (this->getSalary() != other->getSalary()) {
        return false;
    }
    if (this->getEmail() != other->getEmail()) {
        return false;
    }
    return true;
}

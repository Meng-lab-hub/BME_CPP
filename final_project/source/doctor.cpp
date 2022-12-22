//
//  doctor.cpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "doctor.hpp"

// a default construction
Doctor::Doctor() : Person() {
    setSalary("");
    setSpecialized("");
    setOffice("");
    setEmail("");
}


// -----------------------   all functions to set a value to each private attributes --------------------------
void Doctor::setSalary(std::string salary) {
    this->salary = salary;
}

void Doctor::setSpecialized(std::string specialized) {
    this->specialized = specialized;
}

void Doctor::setOffice(std::string office) {
    this->office = office;
}

void Doctor::setEmail(std::string email) {
    this->email = email;
}


// -----------------------   all functions to get a value of each private attributes --------------------------
std::string Doctor::getSalary(void) const {
    return salary;
}

std::string Doctor::getSpecialized(void) const {
    return specialized;
}
std::string Doctor::getOffice(void) const {
    return office;
}

std::string Doctor::getEmail(void) const {
    return email;
}



// --------------- a function to print an additional attributes of this class, that a base class Person does not have -------------
std::ostream& Doctor::print(std::ostream& os) const {
    os << "    Salary: " << getSalary() << std::endl;
    os << "    Specialized: " << getSpecialized() << std::endl;
    os << "    Office room: " << getOffice() << std::endl;
    os << "    Email: " << getEmail() << std::endl << std::endl;
    
    os << "    -------------------------------------------------    " << std::endl;
    return os;
}



// --------------- a function to set an infomation to a attributes of this class, that a base class Person does not have ---------------
void Doctor::getInfo(std::istream& is) {
    
    std::string tempSalary;
    std::cout << "    Salary: ";
    std::getline(is >> std::ws, tempSalary);
    this->setSalary(tempSalary);
    
    std::string tempSpecialized;
    std::cout << "    Specialized: ";
    std::getline(is >> std::ws, tempSpecialized);
    this->setSpecialized(tempSpecialized);
    
    std::string tempOffice;
    std::cout << "    Office: ";
    std::getline(is >> std::ws, tempOffice);
    this->setOffice(tempOffice);
    
    std::string tempEmail;
    std::cout << "    Email: ";
    std::getline(is >> std::ws, tempEmail);
    this->setEmail(tempEmail);
}


// --------------- a function to save all infomation of this class (including a infomation of base class) into a file ---------------
void Doctor::save(std::ostream& os) {
    os << getName() << std::endl << getAge() << std::endl << getID() << std::endl << getAddress() << std::endl << getGender()
       << std::endl << getContact() << std::endl << getDateOfBirth() << std::endl << getDateOfMoveIn() << std::endl << getSalary()
       << std::endl << getSpecialized() << std::endl << getOffice() << std::endl << getEmail() << std::endl;
}


// --------------- a function to load all infomation of this class (including a infomation of base class) from a file ---------------
void Doctor::load(std::istream& is) {
    
    std::string tempName;
    std::getline(is >> std::ws, tempName);
    
    int tempAge = 0;
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
    
    std::string tempSpecialized;
    std::getline(is >> std::ws, tempSpecialized);
    
    std::string tempOffice;
    std::getline(is >> std::ws, tempOffice);
    
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
        this->setSpecialized(tempSpecialized);
        this->setOffice(tempOffice);
        this->setEmail(tempEmail);
    } else {
         // else print an error
        std::cerr << "Error in input format." << std::endl;
    }
}


// ---------------- an operator overloading to compare 2 instances of this class ---------------
bool Doctor::operator==(const Person* other) {
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
    if (this->getSpecialized() != other->getSpecialized()) {
        return false;
    }
    if (this->getOffice() != other->getOffice()) {
        return false;
    }
    if (this->getEmail() != other->getEmail()) {
        return false;
    }
    return true;
}

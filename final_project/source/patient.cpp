//
//  patient.cpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "patient.hpp"


// a default construction
Patient::Patient(void) : Person() {
    setSymptoms("");
    setRoom("");
}


// -----------------------   all functions to set a value to each private attributes --------------------------
void Patient::setSymptoms(std::string symptoms) {
    this->symptoms = symptoms;
}
void Patient::setRoom(std::string room) {
    this->room = room;
}


// -----------------------   all functions to get a value of each private attributes --------------------------
std::string Patient::getSymtoms(void) const {
    return symptoms;
}
std::string Patient::getRoom(void) const {
    return room;
}


// --------------- a function to print an additional attributes of this class, that a base class Person does not have -------------
std::ostream& Patient::print(std::ostream& os) const {
    os << "    Symptoms: " << getSymtoms() << std::endl;
    os << "    Room: " << getRoom() << std::endl;
    os << std::endl;
    os << std::endl;
    
    os << "    -------------------------------------------------    " << std::endl;
    return os;
}


// --------------- a function to set an infomation to a attributes of this class, that a base class Person does not have ---------------
void Patient::getInfo(std::istream& is) {
    std::string tempSymptoms;
    std::cout << "    Symptoms: ";
    std::getline(is >> std::ws, tempSymptoms);
    this->setSymptoms(tempSymptoms);
    
    std::string tempRoom;
    std::cout << "    Room: ";
    std::getline(is >> std::ws, tempRoom);
    this->setRoom(tempRoom);
}


// --------------- a function to save all infomation of this class (including a infomation of base class) into a file ---------------
void Patient::save(std::ostream& os) {
    os << getName() << std::endl << getAge() << std::endl << getID() << std::endl << getAddress() << std::endl << getGender()
       << std::endl << getContact() << std::endl << getDateOfBirth() << std::endl << getDateOfMoveIn() << std::endl << getSymtoms() << std::endl << getRoom() << std::endl;
}


// --------------- a function to load all infomation of this class (including a infomation of base class) from a file ---------------
void Patient::load(std::istream& is) {
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
    
    std::string tempSymptoms;
    std::getline(is >> std::ws, tempSymptoms);
    
    std::string tempRoom;
    std::getline(is >> std::ws, tempRoom);
    
    
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
        
        this->setSymptoms(tempSymptoms);
        this->setRoom(tempRoom);
    } else {
        std::cerr << "Error in input format." << std::endl;
    }
}


// ---------------- an operator overloading to compare 2 instances of this class ---------------
bool Patient::operator==(const Person* other) {
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
    
    
    if (this->getSymtoms() != other->getSymtoms()) {
        return false;
    }
    if (this->getRoom() != other->getRoom()) {
        return false;
    }
    return true;
}

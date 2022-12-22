//
//  person.cpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "person.hpp"


// --------------------- a default constructon -----------------------
Person::Person(void) {
    setName("");
    setAge(0);
    setID("");
    setAddress("");
    setGender("");
    setContact("");
    setDateOfBirth("00/00/0000");
    setDateOfMoveIn("00/00/0000");
}

// -----------------------   all functions to set a value to each private attributes --------------------------

void Person::setName(std::string name) {
    this->name = name;
}
void Person::setAge(int age) {
    this->age = age;
}
void Person::setID(std::string ID) {
    this->ID = ID;
}
void Person::setAddress(std::string address) {
    this->address = address;
}
void Person::setGender(std::string gender) {
    this->gender = gender;
}
void Person::setContact(std::string contact) {
    this->contactNumber = contact;
}

void Person::setDateOfBirth(std::string DOB) {
    this->dateOfBirth = DOB;
}

void Person::setDateOfMoveIn(std::string DOM) {
    this->dateOfMoveIn = DOM;
}


// -----------------------   all functions to get a value of each private attributes --------------------------

std::string Person::getName(void) const {
    return name;
}
int Person::getAge(void) const {
    return age;
}
std::string Person::getID(void) const {
    return ID;
}
std::string Person::getAddress(void) const {
    return address;
}
std::string Person::getGender(void) const {
    return gender;
}
std::string Person::getContact(void) const {
    return contactNumber;
}

std::string Person::getDateOfBirth(void) const {
    return dateOfBirth;
}
std::string Person::getDateOfMoveIn(void) const {
    return dateOfMoveIn;
}



/*
    --------------------- a definition of virtual function from derived class ------------------------
        they don't do any important things, just to get access to a function of derive class
 */


void Person::setSalary(std::string salary) {}
void Person::setSpecialized(std::string specialized) {}
void Person::setOffice(std::string office) {}
void Person::setEmail(std::string email) {}

std::string Person::getSalary(void) const {
    return "";
}
std::string Person::getSpecialized(void) const {
    return "";
}
std::string Person::getOffice(void) const {
    return "";
}
std::string Person::getEmail(void) const {
    return "";
}

std::ostream& Person::print(std::ostream& os) const {
    return os;
}

void Person::getInfo(std::istream& is) {}

bool Person::operator==(const Person* other) {
    return false;
}

void Person::save(std::ostream& os) {}
void Person::load(std::istream& is) {}


void Person::setSymptoms(std::string symtomps) {}
void Person::setRoom(std::string room) {}

std::string Person::getSymtoms(void) const {
    return "";
}
std::string Person::getRoom(void) const {
    return "";
}

// ------------------------------------------ operator overloading -------------------------------------------


// --------------------- operator overloading to print all information of a Person ---------------------
std::ostream& operator<<(std::ostream& os, const Person* other) {
    os << "    -------------------------------------------------    " << std::endl << std::endl;
    
    os << "    Name: " << other->getName() << std::endl;
    os << "    Age: " << other->getAge() << std::endl;
    os << "    ID: " << other->getID() << std::endl;
    os << "    Address: " << other->getAddress() << std::endl;
    os << "    Gender: " << other->getGender() << std::endl;
    os << "    Contact Number: " << other->getContact() << std::endl;
    os << "    Date of Birth: " << other->getDateOfBirth() << std::endl;
    os << "    Date of starting work: " << other->getDateOfMoveIn() << std::endl;
    os << std::endl;
    
    other->print(os);
    
    return os;
}


// --------------------- operator overloading to get all infomation of a Person ---------------------
std::istream& operator>>(std::istream& is, Person* other) {
    
    std::string tempName;
    std::cout << "    Name: ";
    std::getline(is >> std::ws, tempName);
    other->setName(tempName);
    
    int tempAge;
    std::cout << "    Age: ";
    is >> tempAge;
    other->setAge(tempAge);
    
    std::string tempID;
    std::cout << "    ID: ";
    std::getline(is >> std::ws, tempID);
    other->setID(tempID);
    
    std::string tempAddress;
    std::cout << "    Address: ";
    std::getline(is >> std::ws, tempAddress);
    other->setAddress(tempAddress);
    
    std::string tempGender;
    std::cout << "    Gender: ";
    std::getline(is >> std::ws, tempGender);
    other->setGender(tempGender);
    
    std::string tempContact;
    std::cout << "    Contact number: ";
    std::getline(is >> std::ws, tempContact);
    other->setContact(tempContact);
    
    std::string tempDOB;
    std::cout << "    Day of birth: ";
    std::getline(is >> std::ws, tempDOB);
    other->setDateOfBirth(tempDOB);
    
    std::string tempDOM;
    std::cout << "    Day of starting work: ";
    std::getline(is >> std::ws, tempDOM);
    other->setDateOfMoveIn(tempDOM);
    
    other->getInfo(is);
    return is;
}

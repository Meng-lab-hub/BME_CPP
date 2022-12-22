//
//  person.hpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef person_hpp
#define person_hpp

#include <iostream>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <fstream>


// a base class Person
class Person {
     // private attributs
private:
    std::string name;
    int age;
    std::string ID;
    std::string address;
    std::string gender;
    std::string contactNumber;
    std::string dateOfBirth;
    std::string dateOfMoveIn;
    // public methods
public:
    
    // a default construction
    Person();
    
    // all function to set a value to each private attributes of this class
    void setName(std::string name);
    void setAge(int age);
    void setID(std::string ID);
    void setAddress(std::string address);
    void setGender(std::string gender);
    void setContact(std::string contact);
    void setDateOfBirth(std::string DOB);
    void setDateOfMoveIn(std::string DOM);
    
    // all function to get a value of each private attributes of this class
    std::string getName(void) const;
    int getAge(void) const;
    std::string getID(void) const;
    std::string getAddress(void) const;
    std::string getGender(void) const;
    std::string getContact(void) const;
    std::string getDateOfBirth(void) const;
    std::string getDateOfMoveIn(void) const;

    
    
    // -----------------  a virtual function from (used to access a function of a derived class) ------------------
    
    // virtual function of class Doctor and Nurse
    virtual void setSalary(std::string salary);
    virtual void setSpecialized(std::string specialized);
    virtual void setOffice(std::string office);
    virtual void setEmail(std::string email);
    
    virtual std::string getSalary(void) const;
    virtual std::string getSpecialized(void) const;
    virtual std::string getOffice(void) const;
    virtual std::string getEmail(void) const;
    
    virtual std::ostream& print(std::ostream& os) const;
    virtual void getInfo(std::istream& is);
    
    virtual bool operator==(const Person* other);
    virtual void save(std::ostream& os);
    virtual void load(std::istream& is);
    
    
    // virtual function of class Patient
    virtual void setSymptoms(std::string symtomps);
    virtual void setRoom(std::string room);
    
    virtual std::string getSymtoms(void) const;
    virtual std::string getRoom(void) const;
    
    
};

//  ----------------- a operator overloading of class Person -----------------------------
// operator overloading to print all information of a Person
std::ostream& operator<<(std::ostream& os, const Person* other);

// operator overloading to get all infomation of a Person
std::istream& operator>>(std::istream& is, Person* other);


#endif /* person_hpp */


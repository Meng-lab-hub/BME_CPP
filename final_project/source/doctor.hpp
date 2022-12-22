//
//  doctor.hpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef doctor_hpp
#define doctor_hpp

#include "person.hpp"


// a derived class Doctor of a base class Person 
class Doctor : public Person {
    // private attributs
private:
    std::string salary;
    std::string specialized;
    std::string office;
    std::string email;
    // public methods
public:
    
    // a default construction
    Doctor();
    
    // all function to set a value to each private attributes of this class
    void setSalary(std::string salary);
    void setSpecialized(std::string specialized);
    void setOffice(std::string office);
    void setEmail(std::string email);
    
    
    // all function to get a value of each private attributes of this class
    std::string getSalary(void) const;
    std::string getSpecialized(void) const;
    std::string getOffice(void) const;
    std::string getEmail(void) const;
    
    // a function to print an additional attributes of this class, that a base class Person does not have
    std::ostream& print(std::ostream& os) const;
    
    // a function to set an infomation to a attributes of this class, that a base class Person does not have
    void getInfo(std::istream& is);
    
    // a function to save all infomation of this class (including a infomation of base class) into a file
    void save(std::ostream& os);
    
    // a function to load all infomation of this class (including a infomation of base class) from a file
    void load(std::istream& is);
    
    // an operator overloading to compare 2 instances of this class
    bool operator==(const Person* other);
};

#endif /* doctor_hpp */

//
//  patient.hpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef patient_hpp
#define patient_hpp

#include "person.hpp"


// a derived class Nurse of a base class Person 
class Patient : public Person {
    // private attributs
private:
    std::string symptoms;
    std::string room;
    // public methods
public:
    
    // a default construction
    Patient();
    
    // all function to set a value to each private attributes of this class
    void setSymptoms(std::string symtomps);
    void setRoom(std::string room);
    
    
    // all function to get a value of each private attributes of this class
    std::string getSymtoms(void) const;
    std::string getRoom(void) const;
    
    
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

#endif /* patient_hpp */

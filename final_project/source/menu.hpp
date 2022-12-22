//
//  menu.hpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef menu_hpp
#define menu_hpp

// add header file
#include "person.hpp"
#include "doctor.hpp"
#include "nurse.hpp"
#include "patient.hpp"
#include <exception>

// function to load a list of Doctor into a program
void loadDoctorList(std::multimap <std::string, Person*>& DB, int& num);

// function to load a list of Nurse into a program
void loadNurseList(std::multimap <std::string, Person*>& DB, int& num);

// function to load a list of Patient into a program
void loadPatientList(std::multimap <std::string, Person*>& DB, int& num);

// function to print a menu and give an interface for the user
int option(void);

// function to show how many people are there in the list
void numberOfPeople(int num);

// function to print a list of Person (Doctor, Nurse, Patient)
void printList(std::multimap<std::string, Person*>& DB);

// function to add a new Doctor into a list
void addDoctorTolist(std::multimap<std::string, Person*>& DB, int& num);

// function to add a new Nurse into a list
void addNurseToList(std::multimap<std::string, Person*>& DB, int& num);

// function to add a new Patient into a list
void addPatientToList(std::multimap<std::string, Person*>& DB, int& num);

// function to remove a person(Doctor, Nurse, Patient) from a list
void removeFromList(std::multimap<std::string, Person*>& DB, int& num);

// function to find some person from a list
void findFromList(std::multimap<std::string, Person*>& DB);

// function to show HowToUse for a user
void HowToUse(void);

// funcfiion to show Credits for a user
void Credits(void);



// function to save a list of Doctor into a file
void saveDoctorList(std::multimap<std::string, Person*>& DB, int& num);

// function to save a list of Nurse into a file
void saveNurseList(std::multimap<std::string, Person*>& DB, int& num);

// function to save a list of Patient into a file
void savePatientList(std::multimap<std::string, Person*>& DB, int& num);

#endif /* menu_hpp */

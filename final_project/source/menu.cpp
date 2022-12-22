//
//  menu.cpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 04. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//


#include "menu.hpp"


/* ------------------------------- exception handling ------------------------------ */


// ................ exception handling regarding opening each file ................
class CannotLoadDoctorList : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while opening file: ListOfDoctor.txt";
    }
} CannotOpenDoctorList;

class CannotLoadNurseList : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while opening file: ListOfNurse.txt";
    }
} CannotOpenNurseList;

class CannotLoadPatientList : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while opening file: ListOfPatient.txt";
    }
} CannotOpenPatientList;

class CannotLoadHowToUseFile : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while opening file: HowToUse.txt";
    }
} CannotOpenHowToUseFile;

class CannotLoadCreditFile : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while opening file: Credit.txt";
    }
} CannotOpenCreditFile;

// exception handling regarding closing each file

class CannotEndDoctorList : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while closing file: ListOfDoctor.txt";
    }
} CannotCloseDoctorList;

class CannotEndNurseList : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while closing file: ListOfNurse.txt";
    }
} CannotCloseNurseList;

class CannotEndPatientList : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while closing file: ListOfPatient.txt";
    }
} CannotClosePatientList;

class CannotEndHowToUseFile : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while closing file: HowToUse.txt";
    }
} CannotCloseHowToUseFile;

class CannotEndCreditFile : public std::exception {
    virtual const char* what() const throw() {
        return "Error occurs while closing file: Credit.txt";
    }
} CannotCloseCreditFile;








/* ------------------------------- function implementation ------------------------------ */

//   ................ function to load a list of Doctor into a program  ................

void loadDoctorList(std::multimap<std::string, Person*>& DB, int& num) {
    
    // file name is:
    char* fname = (char*) "/Users/meng/Documents/Xcode/testFile/testFile/ListOfDoctor.txt";
    
    // open a file and read
    std::ifstream is(fname);
    if (!is.is_open()) {
        // if cannot open such file properly, throw an exception
        throw CannotOpenDoctorList;
    }
    
    // read a first number from a file which is a number of people in a list
    is >> num;
    
    // create and load Doctor into our container in our program
    for (int i = 0; i < num; i++) {
        Person* other = new Doctor;
        other->load(is);
        DB.insert(std::pair <std::string, Person*> (other->getName(), other));
    }
    
    /* after loaded all information from a file into our container,
       close this file */
    is.close();
    // if cannot close such file properly, throw an exception
    if (is.is_open()) {             
        throw CannotCloseDoctorList;
    }
}



//  ................ function to load a list of Nurse into a program ................

void loadNurseList(std::multimap<std::string, Person*>& DB, int& num) {
    
    // file name is:
    char* fname = (char*) "/Users/meng/Documents/Xcode/testFile/testFile/ListOfNurse.txt";
    std::ifstream is(fname);
    
    // open a file and read
    if (!is.is_open()) {
        // if cannot open such file properly, throw an exception
        throw CannotOpenNurseList;
    }
    
    // read a first number from a file which is a number of people in a list
    is >> num;
    
    
    // create and load Doctor into our container in our program
    for (int i = 0; i < num; i++) {
        Person* other = new Nurse;
        other->load(is);
        DB.insert(std::pair <std::string, Person*> (other->getName(), other));
    }
    
    /* after loaded all information from a file into our container,
    close this file */
    is.close();
    // if cannot close such file properly, throw an exception
    if (is.is_open()) {
        throw CannotCloseNurseList;
    }
}


// ................ function to load a list of Patient into a program ................
void loadPatientList(std::multimap<std::string, Person*>& DB, int& num) {
    
    // file name is:
    char* fname = (char*) "/Users/meng/Documents/Xcode/testFile/testFile/ListOfPatient.txt";
    std::ifstream is(fname);
    
    // open a file and read
    if (!is.is_open()) {
        // if cannot open such file properly, throw an exception
        throw CannotOpenPatientList;
    }
    
    // read a first number from a file which is a number of people in a lists
    is >> num;
    
    // create and load Doctor into our container in our program
    for (int i = 0; i < num; i++) {
        Person* other = new Patient;
        other->load(is);
        DB.insert(std::pair <std::string, Person*> (other->getName(), other));
    }
    
    /* after loaded all information from a file into our container,
    close this file */
    is.close();
    if (is.is_open()) {
        // if cannot close such file properly, throw an exception
        throw CannotClosePatientList;
    }
}


// ................ function to print a menu and give an interface for the user ................

int option(void) {
    
    // show menu
    std::cout << std::endl << std::endl;
    std::cout << "...................................................................." << std::endl << std::endl;
    std::cout << "    ---------------- DATABASE OF HOSPITAL ----------------    " << std::endl << std::endl;
    
    
    std::cout << "         Menu:" << std::endl;
    std::cout << "               1. Show a number of doctor" << std::endl;
    std::cout << "               2. Show a number of nurse" << std::endl;
    std::cout << "               3. Show a number of patient" << std::endl;
    std::cout << "               4. Show all list of doctor" << std::endl;
    std::cout << "               5. Show all list of nurse" << std::endl;
    std::cout << "               6. Show all list of patient" << std::endl;
    std::cout << "               7. Add a doctor to a list" << std::endl;
    std::cout << "               8. Add a nurse to a list" << std::endl;
    std::cout << "               9. Add a patient to a list" << std::endl;
    std::cout << "               10. Remove a doctor from a list" << std::endl;
    std::cout << "               11. Remove a nurse from a list" << std::endl;
    std::cout << "               12. Remove a patient from a list" << std::endl;
    std::cout << "               13. Find a doctor from a list" << std::endl;
    std::cout << "               14. Find a nurse from a list" << std::endl;
    std::cout << "               15. Find a patient from a list" << std::endl;
    
    std::cout << "               16. How to use" << std::endl;
    std::cout << "               17. Credits" << std::endl;
    
    std::cout << "               0. Exit" << std::endl << std::endl;
    std::cout << "        Option: ";
    
    // get a menu selection from user.
    int choice;
    std::cin >> choice;
    std::cout << "...................................................................." << std::endl << std::endl;
    
    // return this selection
    return choice;
}


// ................ function to show how many people are there in the list ................
void numberOfPeople(int num) {
    std::cout << std::endl << "        " << num << " people(s) are in this list" << std::endl;
    
    // hold an output and wait for user to enter 0 to go back to the main menu
    std::cout << std::endl << "               0. Back" << std::endl << std::endl;
    int choice = -1;
    while (choice != 0) {
        std::cin >> choice;
    }
}


// ................ function to print a list of Person (Doctor, Nurse, Patient) ................

void printList(std::multimap<std::string, Person*>& DB) {
    // an variable to indicate whether the list is empty or not
    bool empty = true;
    for (auto i : DB) {
        // go through the whole list and print them
        std::cout << i.second << std::endl;
        // since we entered a loop, the list is not empty, so set empty is false
        empty = false;
    }
    
    // if the list is empty
    if (empty == true) {
        // print that the list is empty
        std::cout << std::endl << "        This list is empty!" << std::endl << std::endl;
    }
    
    // hold an output and wait for user to enter 0 to go back to the main menu
    std::cout << std::endl << "               0. Back" << std::endl << std::endl;
    int choice = -1;
    while (choice != 0) {
        std::cin >> choice;
    }
}


// ................ function to add a new Doctor into a list ................

void addDoctorTolist(std::multimap<std::string, Person*>& DB, int& num) {
    
    std::cout << "    <><><><><><><><><><> Adding a Doctor <><><><><><><><><><>    " << std::endl << std::endl;
    // create a new Doctor
    Person* other = new Doctor;
    // get an input for a new Doctor
    std::cin >> other;
    std::cout << "    <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>    " << std::endl << std::endl;
    // cast other to a derived class Doctor, because we want to compare Doctor and Doctor
    Doctor* tmp = (Doctor*) other;
    // a variable to indicate whether is new Doctor is duplicated to a doctor in a list or not
    bool duplicate = false;
    // check for duplication
    for (auto i : DB) {
        if (*tmp == i.second) {
            duplicate = true;
        }
    }
    
    // is a new Doctor is not duplicated
    if (duplicate == false) {
        // add that new Doctor into a list
        DB.insert(std::pair <std::string, Person*> (other->getName(), other));
        // increase a number of total Doctor in a list
        num++;
    }
    
    
    // hold an output and wait for user to enter 0 to go back to main menu
    std::cout << std::endl << "        Completed!" << std::endl;
    std::cout << std::endl << "               0. Back" << std::endl << std::endl;
    int choice = -1;
    while (choice != 0) {
        std::cin >> choice;
    }
}


// ................ function to add a new Nurse into a list ................

void addNurseToList(std::multimap<std::string, Person*>& DB, int& num) {
    std::cout << "    <><><><><><><><><><> Adding a Nurse <><><><><><><><><><>    " << std::endl << std::endl;
    // create a new Nurse
    Person* other = new Nurse;
    // get an input for a new Nurse
    std::cin >> other;
    std::cout << "    <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>    " << std::endl << std::endl;
    // cast other to a derived class Nurse, because we want to compare Nurse and Nurse
    Nurse* tmp = (Nurse*) other;
    // a variable to indicate whether is new Nurse is duplicated to a Nurse in a list or not
    bool duplicate = false;
    // check for duplication
    for (auto i : DB) {
        if (*tmp == i.second) {
            duplicate = true;
        }
    }
    
    // is a new Nurse is not duplicated
    if (duplicate == false) {
        // add that new Nurse into a list
        DB.insert(std::pair <std::string, Person*> (other->getName(), other));
        // increase a number of total Nurse in a list
        num++;
    }
    
    
    // hold an output and wait for user to enter 0 to go back to main menu
    std::cout << std::endl << "        Completed!" << std::endl;
    std::cout << std::endl << "               0. Back" << std::endl << std::endl;
    int choice = -1;
    while (choice != 0) {
        std::cin >> choice;
    }
}


// ................ function to add a new Patient into a list ................

void addPatientToList(std::multimap<std::string, Person*>& DB, int& num) {
    std::cout << "    <><><><><><><><><><> Adding a Patient <><><><><><><><><><>    " << std::endl << std::endl;
    // create a new Patient
    Person* other = new Patient;
    // get an input for a new Patient
    std::cin >> other;
    std::cout << "    <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>    " << std::endl << std::endl;
    // cast other to a derived class Patient, because we want to compare Patient and Patient
    Patient* tmp = (Patient*) other;
    // a variable to indicate whether is new Patient is duplicated to a Patient in a list or not
    bool duplicate = false;
     // check for duplication
    for (auto i : DB) {
        if (*tmp == i.second) {
            duplicate = true;
        }
    }
    
    // is a new Patient is not duplicated
    if (duplicate == false) {
         // add that new Patient into a list
        DB.insert(std::pair <std::string, Person*> (other->getName(), other));
        // increase a number of total Patient in a list
        num++;
    }
    
    
    // hold an output and wait for user to enter 0 to go back to main menu
    std::cout << std::endl << "        Completed!" << std::endl;
    std::cout << std::endl << "               0. Back" << std::endl << std::endl;
    int choice = -1;
    while (choice != 0) {
        std::cin >> choice;
    }
}


// ................ function to remove a person(Doctor, Nurse, Patient) from a list ................
void removeFromList(std::multimap<std::string, Person*>& DB, int& num) {
    
    // a variable to indicate if the list is empty
    bool empty = true;
    // print a whole list
    for (auto i : DB) {
        std::cout << i.second << std::endl;
        // if we can enter a loop, then the list is not empty
        empty = false;
    }
    
    
    // if the list is not empty
    if (empty == false) {
        std::cout << "        Enter a full name to be removed: ";
        std::string InName;
        // get a name of Person to be removed
        std::getline(std::cin >> std::ws, InName);
        
        // a variable to indicate if the given name is found
        bool found = false;
        
        // a variable to count a number of person that match this name
        int numberFound = 0;
        for (auto i: DB) {
            if (i.second->getName() == InName) {
                // if found that person, print his/her information
                std::cout << i.second << std::endl;
                // set found to true
                found = true;
                // increase the number of person that match this name
                numberFound++;
            }
        }
        
        // is this given name is not found
        if (found == false) {
            std::cout << std::endl << "        This person is not in the list. Please check again!" << std::endl;
            std::cout << std::endl << "               0. Back" << std::endl << std::endl;
            
            // hold an output and wait for user to continue
            int choice = -1;
            while (choice != 0) {
                std::cin >> choice;
            }
        } else {
            // if a given name is found
            
            // confirm again if user would like to remove this person
            int choice = -1;
            while (choice != 1) {
                std::cout << std::endl << "        REMOVE THIS PERSON? " << std::endl;
                std::cout << "               1. Yes!" << std::endl;
                std::cout << "               2. No!" << std::endl;
                std::cin >> choice;
            
                
                // if yes
                if (choice == 1) {
                    for (auto i: DB) {
                        if (i.second->getName() == InName) {
                            // delete this person
                            delete i.second;
                        }
                    }
                    // remove from a list
                    DB.erase(InName);
                    // decrease a number of total people in the list by a number of person that will be removed
                    num = num - numberFound;
                } else if (choice == 2) {
                    // if no
                    // break this loop
                    break;
                }
            }
            
            // hold an output and wait for user to continue
            std::cout << std::endl << "        Completed!" << std::endl;
            std::cout << std::endl << "               0. Back" << std::endl << std::endl;
            choice = -1;
            while (choice != 0) {
                std::cin >> choice;
            }
        }
    } else {
        // if the list if empty
        std::cout << std::endl << "        This list is empty!" << std::endl << std::endl;
        std::cout << std::endl << "               0. Back" << std::endl << std::endl;
        
        // hold an output and wait for user to continue
        int choice = -1;
        while (choice != 0) {
            std::cin >> choice;
        }
    }
    
}


// ................ function to find some person from a list ................

void findFromList(std::multimap<std::string, Person*>& DB) {
    std::cout << "        Enter a full name: ";
    std::string InName;
    // get a name that user wants to search
    std::getline(std::cin >> std::ws, InName);

    // variable to indicate if the given name is found
    bool found = false;
    for (auto i : DB) {
        if (i.second->getName() == InName) {
            // if found then print his/her information
            std::cout << i.second << std::endl;
            // and set found to true
            found = true;
        }
    }
    
    // if the given name is not found
    if (found == false) {
        std::cout << std::endl << "        This person is not in the list!" << std::endl;
        std::cout << std::endl << "               0. Back" << std::endl << std::endl;
        
        // print a not found message, hold an output and wait for user to continue
        int choice = -1;
        while (choice != 0) {
            std::cin >> choice;
        }
    } else {
        // if the given name is found, his/her infomation should have been printed
        
        // hold an output and wait for user to continue
        std::cout << std::endl << "               0. Back" << std::endl << std::endl;
        int choice = -1;
        while (choice != 0) {
            std::cin >> choice;
        }
    }
}


// ................ function to show HowToUse for a user ................
void HowToUse() {
    
    // open file HowToUse.txt
    std::ifstream myfile;
    myfile.open("/Users/meng/Documents/Xcode/testFile/testFile/HowToUse.txt", std::ios::in);
    // if file is not opened properly
    if (!myfile.is_open()) {
         // throw an exception
        throw CannotOpenHowToUseFile;
    }

    char ch;
    // get every character and print it to screen one by one
    while (myfile.get(ch)) {
        std::cout << ch;
    }
    
    
    // close a file
    myfile.close();
    // if a file is not closed properly
    if (myfile.is_open()) {
         // throw an exception
        throw CannotCloseHowToUseFile;
    }
    
    
    // hold an output and wait for user to continue
    std::cout << std::endl << "               0. Back" << std::endl << std::endl;
    int choice = -1;
    while (choice != 0) {
        std::cin >> choice;
    }
}


// ................ funcfiion to show Credits for a user ................
void Credits() {
    
    // open file Credit.txt
    std::ifstream myfile;
    myfile.open("/Users/meng/Documents/Xcode/testFile/testFile/Credit.txt", std::ios::in);
    // if file is not opened properly
    if (!myfile.is_open()) {
        // throw an exception
        throw CannotOpenCreditFile;
    }
    
    char ch;
    // get every character and print it to screen one by one
    while (myfile.get(ch)) {
        std::cout << ch;
    }
    // close a file
    myfile.close();
    // if a file is not closed properly
    if (myfile.is_open()) {
        // throw an exception
        throw CannotCloseCreditFile;
    }
    
    
    // hold an output and wait for user to continue
    std::cout << std::endl << "               0. Back" << std::endl << std::endl;
    int choice = -1;
    while (choice != 0) {
        std::cin >> choice;
    }
}


// ................ function to save a list of Doctor into a file ................

void saveDoctorList(std::multimap<std::string, Person*>& DB, int& num) {
    
    // file name:
    char* fname = (char*) "/Users/meng/Documents/Xcode/testFile/testFile/ListOfDoctor.txt";
    
    // open file
    std::ofstream os(fname);
    // if a file is not opened properly
    if (!os.is_open()) {
        // throw an exception
        throw CannotOpenDoctorList;
    }
    // at a very beginning of a file save a number of total Doctor
    os << num << std::endl;
    
    for (auto i : DB) {
        // then save all information of each Doctor repectively
        i.second->save(os);
    }
    
    
    // close file
    os.close();
    // if a file is not closed properly
    if(os.is_open()) {
        // throw an exception
        throw CannotCloseDoctorList;
    }
    
}


// ................ function to save a list of Nurse into a file ................

void saveNurseList(std::multimap<std::string, Person*>& DB, int& num) {
    
    // file name:
    char* fname = (char*) "/Users/meng/Documents/Xcode/testFile/testFile/ListOfNurse.txt";
    
    // open file
    std::ofstream os(fname);
    // if a file is not opened properly
    if (!os.is_open()) {
        // throw an exception
        throw CannotOpenNurseList;
    }
    // at a very beginning of a file save a number of total Doctor
    os << num << std::endl;
    
    for (auto i : DB) {
        // then save all information of each Doctor repectively
        i.second->save(os);
    }
    
    // close file
    os.close();
    // if a file is not closed properly
    if (os.is_open()) {
        // throw an exception
        throw CannotCloseNurseList;
    }
    
}


// ................ function to save a list of Patient into a files ................
void savePatientList(std::multimap<std::string, Person*>& DB, int& num) {
    
    // file name:
    char* fname = (char*) "/Users/meng/Documents/Xcode/testFile/testFile/ListOfPatient.txt";
    
    // open file
    std::ofstream os(fname);
    // if a file is not opened properly
    if (!os.is_open()) {
        // throw an exception
        throw CannotOpenPatientList;
    }
    // at a very beginning of a file save a number of total Doctor
    os << num << std::endl;
    
    for (auto i : DB) {
        // then save all information of each Doctor repectively
        i.second->save(os);
    }
    
    // close file
    os.close();
    // if a file is not closed properly
    if (os.is_open()) {
        // throw an exception
        throw CannotClosePatientList;
    }
    
}

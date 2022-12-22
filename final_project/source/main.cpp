#include "person.hpp"
#include "doctor.hpp"
#include "nurse.hpp"
#include "patient.hpp"
#include "menu.hpp"



int main(void) {
    
    /* a variable to count number of Doctor, Nurse, Patient */
    int numberOfDoctor = 0;
    int numberOfNurse = 0;
    int numberOfPatient = 0;
    
    
    /* a container that will store a list of Doctor, Nurse, Patient */
    std::multimap<std::string, Person*> DoctorList;
    std::multimap<std::string, Person*> NurseList;
    std::multimap<std::string, Person*> PatientList;
    
    
    /* load lists of People (Doctor, Nurse, Patient) from a file to our containers here */
    try {
        loadDoctorList(DoctorList, numberOfDoctor);
    }
    /* catch an exception if cannot open or close a file properly */
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    try {
        loadNurseList(NurseList, numberOfNurse);
    }
    /* catch an exception if cannot open or close a file properly */
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    try {
        loadPatientList(PatientList, numberOfPatient);
    }
    /* catch an exception if cannot open or close a file properly */
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    
    
    
    /* a variable to get a choice from user and travel around our program (menu selection) */
    int command = -1;
    
    /* using while loop to keep select a menu */
    while (command != 0) {
        command = option();
        switch (command) {
            case 1:
                // get total number of doctor
                numberOfPeople(numberOfDoctor);
                break;
            case 2:
                // get total number of Nurse
                numberOfPeople(numberOfNurse);
                break;
            case 3:
                // get total number of Patient
                numberOfPeople(numberOfPatient);
                break;
            case 4:
                // print a whole list of Doctor
                printList(DoctorList);
                break;
            case 5:
                // print a whole list of Nurse
                printList(NurseList);
                break;
            case 6:
                // print a whole list of Patient
                printList(PatientList);
                break;
            case 7:
                try {
                    // create a new Doctor, add to a list and increase a number of total doctor
                    addDoctorTolist(DoctorList, numberOfDoctor);
                }
                catch (std::bad_alloc&) {
                    // catch an error if memory allocation is failed
                    std::cout << "Memory allocation exception happened" << std::endl;
                }
                break;
            case 8:
                try {
                    // create a new Nurse, add to a list and increase a number of total nurse
                    addNurseToList(NurseList, numberOfNurse);
                }
                catch (std::bad_alloc&) {
                    // catch an error if memory allocation is failed
                    std::cout << "Memory allocation exception happened" << std::endl;
                }
                break;
            case 9:
                try {
                    // create a new Patient, add to a list and increase a number of total patient
                    addPatientToList(PatientList, numberOfPatient);
                }
                catch (std::bad_alloc&) {
                    // catch an error if memory allocation is failed
                    std::cout << "Memory allocation exception happened" << std::endl;
                }
                break;
            case 10:
                // remove a doctor from a list and decrease a number of total doctor
                removeFromList(DoctorList, numberOfDoctor);
                break;
            case 11:
                // remove a nurse from a list and decrease a number of total nurse
                removeFromList(NurseList, numberOfNurse);
                break;
            case 12:
                // remove a patient from a list and decrease a number of total patient
                removeFromList(PatientList, numberOfPatient);
                break;
            case 13:
                // search a doctor from a list using name
                findFromList(DoctorList);
                break;
            case 14:
                // search a nurse from a list using name
                findFromList(NurseList);
                break;
            case 15:
                // search a patient from a list using name
                findFromList(PatientList);
                break;
            case 16:
                // load and print an information about how to use from a file to screen
                HowToUse();
                break;
            case 17:
                // load and print an information about credits from a file to screen
                Credits();
                break;
            default:
                // while a choice is not the above choice, do nothing
                break;
        }
    }
    
    
    /* after quite a program, save a list of people(Doctor, Nurse, Patient) into a file */
    try {
        saveDoctorList(DoctorList, numberOfDoctor);
    }
    // catch an exception if cannot open or close a file properly
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    try {
        saveNurseList(NurseList, numberOfNurse);
    }
     // catch an exception if cannot open or close a file properly
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    try {
        savePatientList(PatientList, numberOfPatient);
    }
    // catch an exception if cannot open or close a file properly
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return EXIT_SUCCESS;
}

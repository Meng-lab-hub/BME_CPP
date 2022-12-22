//
//  Fifo.cpp
//  homework
//
//  Created by Khongmeng Kormoua on 2021. 03. 11..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Fifo.h"
using namespace std;

// A constructor, used to set a FIFO into an initial condition.
FIFO::FIFO() {
    elementNum = 0;
    pData = NULL;
}


// A copy constructor.
FIFO::FIFO(const FIFO &theOther) {
    elementNum = theOther.elementNum;
    
    pData = new double[elementNum];
    
    for (int i = 0; i < elementNum; i++)
        pData[i] = theOther.pData[i];
}


// A destructor: release dynamically allocated resources and set all attribute back to initialized state.
FIFO::~FIFO() {
    if (elementNum > 1)         // in case in a set there are more than 1 element
        delete[] pData;         // release an array in a set
    else                        // in case in a set there is only 1 or 0 element
        delete pData;           // release a data in a set
    elementNum = 0;             // set a number of element to 0 again as the initial state
    pData = NULL;               // set a pointer of an array to nowhere (NULL)
    
}


// A push method used to insert a new element to a FIFO
// if a push method is successful then return true
// if a push method is unsuccessful then return false
bool FIFO::push(double element) {
    
    double* tmp = new double[elementNum + 1];       // allocate space for temporary array with 1 larger size than the original one
    if (!tmp)                                       // if cannot allocate a memory
        return false;                                       // return false
    
    // if a memory can be allocated
    for (int i = 0; i < elementNum; i++)            // travel through the whole array of FIFO
        tmp[i] = pData[i];                          // copy all the content of the original array into the temporary array
    tmp[elementNum] = element;                      // at the end of the temporary array, add a new element
    
    delete[] pData;                                 // release a original array
    pData = tmp;                                    // set a original pointer to a temporary array
    elementNum++;                                   // increment a number of element in the array
    
    tmp = NULL;                                     // set a temporary pointer to NULL (nowhere)
    return true;                                    // return ture when we can push an element
}


// A pop method used to return the firstly entered element
// if a FIFO is empty (or some other fault) then no need to pop anything and return -1
double FIFO::pop() {
    
    if (elementNum == 0)        // if the FIFO is empty
        return -1;                      // return -1 to indicate that failed to pop
    
    
    // if FIFO is not empty
    double* tmp = new double[elementNum - 1];       // allocate a memory for a temporary array, with 1 size smaller than the original array
    if (!tmp)                                       // if cannot allocate a memory
        return -1;                                  // return -1 to indicate that failed to pop
    
    for (int i = 0; i < elementNum; i++)            // travel through the whole array of FIFO
        tmp[i] = pData[i + 1];                      // copy all the content of the orginal array except the first element to a temporary array
    
    double popOutElement;
    popOutElement = pData[0];                       // the first element of original array will be pop out, so store it in a local variable first
    
    delete[] pData;                                 // release an original array
    pData = tmp;                                    // set a pointer of original array to a temporary array
    tmp = NULL;                                     // set a temporary pointer to nowhere (NULL)
    elementNum--;                                   // decrease a number of element in a array of a set
    return popOutElement;                           // return the value of element that will be pop
}


// A method used to check if a element that we are looking for is in a set or not.
bool FIFO::isElement(double element) {
    for (int i = 0; i < elementNum; i++)
        if (pData[i] == element)
            return true;
    return false;
}


// A empty method, which is used to clear all data and bring the set back to the initial state.
void FIFO::empty() {
    if (elementNum > 1)         // in case in a set there are more than 1 element
        delete[] pData;         // release an array in a set
    else                        // in case in a set there is only 1 or 0 element
        delete pData;           // release a data in a set
    elementNum = 0;             // set a number of element to 0 again as the initial state
    pData = NULL;               // set a pointer of an array to nowhere (NULL)
}


// A print method, which is used to print all the element in the array of a FIFO.
void FIFO::print() {
    
    cout << endl;
    // in case a FIFO is empty
    if (elementNum == 0)
        cout << "this FIFO is empty!";
    
    // in case a FIFO is not empty
    else {
        cout << "we have: ";
        for (int i = 0; i < elementNum; i++)            // travel throught the whole array of FIFO
            cout << pData[i] << " ";                    // at each step of traveling, print a value of that element.
    }
    cout << endl;
}








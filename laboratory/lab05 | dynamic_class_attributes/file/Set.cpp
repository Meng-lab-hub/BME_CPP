//
//  Set.cpp
//  lab05
//
//  Created by Khongmeng Kormoua on 2021. 03. 10..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Set.h"
using namespace std;


// Initialize an empty set to a stable state by class constructor.
Set::Set() {
    elementNum = 0;             // set a number of element in a set to 0
    pData = NULL;               // set a pointer of a set to NULL first (nowhere)
}

// A copy constructor
Set::Set(const Set &theOther) {
    elementNum = theOther.elementNum;
    
    pData = new int[elementNum];
    
    for (int i = 0; i < elementNum; i++)
        pData[i] = theOther.pData[i];
}

// A destructor: release dynamically allocated resources and set all attribute back to initialized state.
Set::~Set() {
    if (elementNum > 1)         // in case in a set there are more than 1 element
        delete[] pData;         // release an array in a set
    else                        // in case in a set there is only 1 or 0 element
        delete pData;           // release a data in a set
    elementNum = 0;             // set a number of element to 0 again as the initial state
    pData = NULL;               // set a pointer of an array to nowhere (NULL)
}


// insert method: will take given element and add it to an set base on some conditions below:
/*
 1) if no memory can be allocated then return false.
 2) if an element that is to be inserted already exist in the set, then just return true.
 3) if iserting an element into a set is successful, return false.
 */
bool Set::insert(int element) {
    
    if (isElement(element) == true)                       // if an element to be inserted already exist in a set
        return true;                                      // true is to be returned
    else {                                                // if an element to be inserted does not exist in a set yet
        int* tmp = new (nothrow) int[elementNum + 1];           // allocate space for temporary array with 1 larger size than the original one
        if (!tmp)                                               // if cannot allocate a memory
            return false;                                               // return false
        else {                                                  // if a memory can be allocated
            for (int i = 0; i < elementNum; i++)                        // copy all the content of the original array into the temporary array
                tmp[i] = pData[i];
            
            tmp[elementNum] = element;                                  // at the end of the temporary array, add a new element
            
            delete[] pData;                                             // release a original array
            pData = tmp;                                                // set a original pointer to a temporary array
            elementNum++;                                               // increment a number of element in the array
            
            tmp = NULL;                                                 // set a temporary pointer to NULL (nowhere)
            return false;                                               // return false, base on the spefication if we can insert a new element
        }
    }
}


// remove method: is used to remove a given element from a set if there is such element in a set
// if there is no such element in the set, then the method shoud return false
bool Set::remove(int element) {
    
    if (isElement(element) == false)            // if there is no such element in the set
        return false;                           // return false
    
    int* tmp = new int[elementNum - 1];             // allocate a memory for a temporary array, with 1 size smaller than the original array
    for (int i = 0, j = 0; i < elementNum; i++)     // copy all the content of the original array to the temporary array
        if (pData[i] != element) {                  // except the elment in the array that is the same as the given element to be removed
            tmp[j] = pData[i];
            j++;
        }
    elementNum--;                                   // decrease a number of element in a array of a set
    delete[] pData;                                 // release an original array
    pData = tmp;                                    // set a pointer of original array to a temporary array
    tmp = NULL;                                     // set a temporary pointer to nowhere (NULL)
    return true;                                    // we can remove an element so true is to be returned
}

// isElement method: Check if the given element is contained by the set.
bool Set::isElement(int element) {
    for (int i = 0; i < elementNum; i++)            // travel through a whole array
        if (pData[i] == element)                    // if we found an element that we are looking for in the array
            return true;                                // return true to indicate that there is such element in this set
    return false;                                   // if we an element that we are looking for is not in the set then return false
}

// print method: Print the set elements separated by spaces. Puts a new line before the first an after the last elements.
void Set::print() {
    cout << endl;
    // in case a Set is empty
    if (elementNum == 0)
        cout << "this Set is empty!";
    
    // in case a Set is not empty
    else {
    cout << endl;                           // print new line
    for (int i = 0; i < elementNum; i++)    // travel through all element in the array
        cout << pData[i] << " ";                    // in each step when we go through the array, print them
    cout << endl;                           // print new line
    }
}


// empty method: clear a set, delete all elements
void Set::empty() {
    if (elementNum > 1)         // in case in a set there are more than 1 element
        delete[] pData;         // release an array in a set
    else                        // in case in a set there is only 1 or 0 element
        delete pData;           // release a data in a set
    elementNum = 0;             // set a number of element to 0 again as the initial state
    pData = NULL;               // set a pointer of an array to nowhere (NULL)
}

// print function: call a print method of a set by a reference of a set
void printSet(Set &s) {
    s.print();
}

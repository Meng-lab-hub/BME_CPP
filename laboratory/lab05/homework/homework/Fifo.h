//
//  Fifo.h
//  homework
//
//  Created by Khongmeng Kormoua on 2021. 03. 11..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef Fifo_h
#define Fifo_h

#include <iostream>     // for cout
#include <new>          // for nothrow (which is used to check if we allocate a memory)

class FIFO {
    // private attribute:
    int elementNum;     // a number of element inside an array of the FIFO
    double* pData;      // a pointer to a array of FIFO
public:
    // A constructor for Initialize an empty set.
    FIFO();
    
    // A copy constructor.
    FIFO(const FIFO &theOther);
    
    // A destructor: release dynamically allocated resources.
    ~FIFO();
    
    // A push method used to insert a new element to a FIFO
    // if a push method is successful then return true
    // if a push method is unsuccessful then return false
    bool push(double element);
    
    // A pop method used to return the firstly entered element
    // if a FIFO is empty (or some other fault) then no need to pop anything and return -1
    double pop();
    
    // A method used to check if a element that we are looking for is in a set or not.
    bool isElement(double element);
    
    // A empty method, which is used to clear all data and bring the set back to the initial state.
    void empty();
    
    // A print method, which is used to print all the element in the array of a FIFO.
    void print();
};



#endif /* Fifo_h */

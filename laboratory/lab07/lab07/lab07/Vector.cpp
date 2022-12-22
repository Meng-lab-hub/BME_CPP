//
//  Vector.cpp
//  lab07
//
//  Created by Khongmeng Kormoua on 2021. 03. 30..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Vector.h"


// Default constructors
Vector::Vector() {
    elementNum = 0;
    pData = NULL;
}

// Copy constructor
Vector::Vector(const Vector& theOther) {
    /*
    elementNum = theOther.elementNum;
    pData = new int[elementNum];
    for (int i = 0; i < elementNum; i++) {
        pData[i] = theOther.pData[i];
    }
     */
    // ----- earlier I implemented the old style of copy construction without the existing of operator=
    
    // ----- here I found that this simple method works completely fine as well
    *this = theOther;
}

// Destructor
Vector::~Vector() {
    // in my point of view clear and destructor should work in the same way
    clear();            // so I just call a clear method here.
}

// returns the array size
int Vector::size() const {
    return elementNum;
    
}

// clears the array
void Vector::clear() {
    if (elementNum > 1) {       // if the allocated memory has more than 1 element
        delete [] pData;        // delete in this way
    } else {                    // if the allocated memeory has less or equal to 1 element
        delete pData;           // delete in this way
    }
    elementNum = 0;             // set the number of element to 0
    pData = NULL;               // make pData point to NULL (which is safe to delete as well)
}

// erases (deletes) the array element with the given index;
// valid indices: from 0 to size-1
void Vector::erase(unsigned int position) {
    if (position < elementNum) {                        // if the position is in range
        int* tmp = new int[elementNum - 1];             // create a new place with less than 1 element
        for (int i = 0, j = 0; i < elementNum; i++) {
            if (i != position) {                        // copy every element from this vector to the tmp vector except the element at the given position
                tmp[j] = pData[i];
                j++;
            }
        }
    
        if (elementNum > 1) {                           // after copied, clear this vector
            delete [] pData;
        } else {
            delete pData;
        }
        pData = tmp;                                    // assign the tmp array to the array of this vector.
        tmp = NULL;                                     // point tmp to something else, the best option is nowhere.
        elementNum--;                                   // decrease the number of element after successful removing.
    }
}

// returns the array element with the given index, making possible to modify the element;
// valid indices: between 0 and size()-1
int& Vector::at(unsigned int position) {
    if (position < elementNum) {                        // if the given position is not out of range of the vector.
        return pData[position];                         // return a element of that positon as a reference, this make it possible to modify this element in main or somewhere else that they call for this method.
    } else {                                            // if the given position is out of range.
        // since we haven't studied about exception handling clearly, even thougth I tried to study on the internet, it's still not so clear for me to implement it in a method of a class like this. therefore I just simply print out that it is out of range
        // and I implement a similar method as insert method, if the index exceeds the array size, then the size should be increased, and the empty places should be filled with 0 (zero)
        std::cerr << "Out of range!, new element has been created! " << std::endl;
        int i = 0;                                          // position counter.
        int* tmp = new int[position + 1];                   // create a temporary space that has enough size for the position of the new element.
        for (; i < elementNum; i++) {
            tmp[i] = pData[i];                              // copy the all the content of thisarray into the temporary space.
        }
        for (; i < position + 1; i++) {                     // then the rest until the given position
            tmp[i] = 0;                                     // fill these space with 0
        }
        
        if (elementNum == 1) {                              // if the array of this vector has only 1 element
            delete pData;                                   // delete in this way
        } else if (elementNum > 1) {                        // if the array of this vector has more than 1 element
            delete [] pData;                                // delete in this way
        }
        pData = tmp;                                        // after clear up this vector, assign the temporary space to the array of this vector
        tmp = NULL;                                         // point tmp to nowhere.
        elementNum = position + 1;                          // assign the new number of element
        return pData[elementNum - 1];
    }
}

// returns the array element with the given index, without possibility to modify the element (see const keyword)
// valid indices: between 0 and size()-1
const int& Vector::at(unsigned int position) const {
    if (position < elementNum) {
        return pData[position];
    } else {                                            // if the given position is out of range.
        std::cerr << "Out of range!" << std::endl;
        // since we haven't studied about exception handling clearly, even thougth I tried to study on the internet, it's still not so clear for me to implement it in a method of a class like this. therefore I just simply print out that it is out of range.
        // for this const method, I cannot create a new element in the vector like before,but the return type is also const, so it is safe to return some element in the vector, so I return the last element of the vector.
        return pData[elementNum - 1];
    }
}

// inserts a new element into a place with the given index;
// if the index exceeds the array size, then the size should be increased, and the empty places should be filled with 0 (zero)
bool Vector::insert(unsigned int position, int element) {
    if (position < elementNum) {                            // if the given position is in range
        int* tmp = new int[elementNum + 1];                 // create a new space with size more than 1, for the new element
        for (int i = 0, j = 0; i < elementNum + 1; i++) {   // go through the array of this vector
            if (i == position) {                            // at the position that the new element should be inserted
                tmp[i] = element;                           // insert the new element here.
            } else {                                        // at the other position
                tmp[i] = pData[j];                          // copy the old array to the temporary array.
                j++;                                        // this is used to track the old array.
            }
        }
        
        delete [] pData;                                    // after copied and inserted the new element to tmp array, clear this array
        pData = tmp;                                        // assign the temporary array to this array
        tmp = NULL;                                         // now point the temporary pointer to nowhere
        elementNum++;                                       // after successful insertion, increment the number of element in this array
        return true;                                        // return true to indicate successfully insertion.
    } else {                                                // if the given position is out of range of the vector.
        int i = 0;                                          // position counter.
        int* tmp = new int[position + 1];                   // create a temporary space that has enough size for the position of the new element.
        for (; i < elementNum; i++) {
            tmp[i] = pData[i];                              // copy the all the content of thisarray into the temporary space.
        }
        for (; i < position; i++) {                         // then if i is still less that the position that we want to insert the new element
            tmp[i] = 0;                                     // fill these space with 0
        }
        tmp[position] = element;                            // finally when we reach the given position, insert the new element into this slot.
        
        if (elementNum == 1) {                              // if the array of this vector has only 1 element
            delete pData;                                   // delete in this way
        } else if (elementNum > 1) {                        // if the array of this vector has more than 1 element
            delete [] pData;                                // delete in this way
        }
        pData = tmp;                                        // after clear up this vector, assign the temporary space to the array of this vector
        tmp = NULL;                                         // point tmp to nowhere.
        elementNum = position + 1;                          // assign the new number of element
        return true;                                        // after successfully insert the new eleement return true
    }
}

// Operator=
const Vector& Vector::operator= (const Vector & theOther) {
    
    if (this == &theOther) {            // in case of self-assignment
        return *this;                   // return this vector
    }
    
    // in case not a self-assignment
    clear();            // First of all, clear this Vector and then we can copy theOther vector into this vector

    elementNum = theOther.elementNum;               // set the number of element of this vector as much as theOther vector
    pData = new int[elementNum];                    // allocate a memory space of this vector with the appropriate size
    for (int i = 0; i < elementNum; i++) {
        pData[i] = theOther.pData[i];               // copy every element from theOther vector to this vector one by one.
    }
    return *this;                                   // after completed copying, return this vector back.
}

// operator[]
int & Vector::operator [](unsigned int position) {
    if (position < elementNum) {                        // if the given position is in range
        return pData[position];                         // return an element at that position
    } else {                                            // if the given position is out of range.
        // since we haven't studied about exception handling clearly, even thougth I tried to study on the internet, it's still not so clear for me to implement it in a method of a class like this. therefore I just simply print out that it is out of range
        // and I implement a similar method as insert method, if the index exceeds the array size, then the size should be increased, and the empty places should be filled with 0 (zero)
        std::cerr << "Out of range!, new element has been created! " << std::endl;
        int i = 0;                                          // position counter.
        int* tmp = new int[position + 1];                   // create a temporary space that has enough size for the position of the new element.
        for (; i < elementNum; i++) {
            tmp[i] = pData[i];                              // copy the all the content of thisarray into the temporary space.
        }
        for (; i < position + 1; i++) {                     // then the rest until the given position
            tmp[i] = 0;                                     // fill these space with 0
        }
        
        if (elementNum == 1) {                              // if the array of this vector has only 1 element
            delete pData;                                   // delete in this way
        } else if (elementNum > 1) {                        // if the array of this vector has more than 1 element
            delete [] pData;                                // delete in this way
        }
        pData = tmp;                                        // after clear up this vector, assign the temporary space to the array of this vector
        tmp = NULL;                                         // point tmp to nowhere.
        elementNum = position + 1;                          // assign the new number of element
        return pData[elementNum - 1];
    }
}
const int & Vector::operator [](unsigned int position) const {
    if (position < elementNum) {                        // if the given position is in range
        return pData[position];                         // return an element at that position
    } else {                                            // if the given position is out of range.
        std::cerr << "Out of range!" << std::endl;
        // since we haven't studied about exception handling clearly, even thougth I tried to study on the internet, it's still not so clear for me to implement it in a method of a class like this. therefore I just simply print out that it is out of range.
        // for this const method, I cannot create a new element in the vector like before,but the return type is also const, so it is safe to return some element in the vector, so I return the last element of the vector.
        return pData[elementNum - 1];
    }
}


// sorting function (HOMEWORK)
void Vector::sort() {
    // I found that this std::sort is considerable very fast, and very simple, so I use it here for simplicity
    if (elementNum > 1) {                                   // if there are more than 1 element to sort.
        std::sort(pData, pData + elementNum);           // the first paramenter is the pointer to the first element, the second parameter is the pointer point to the first element with an addition of the lenght up to where we whould like to sort.
    }
}


// global function for printing vector data
std::ostream & operator << (std::ostream& os, const Vector& v) {
    for (int i = 0; i < v.elementNum; i++) {        // travel through the whole list of vector
        os << v.pData[i] << " ";                    // at each step of traversal put that element to output stream.
    }
    return os;                                      // return the output stream.
}

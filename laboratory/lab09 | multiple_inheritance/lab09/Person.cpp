//
//  Person.cpp
//  lab09
//
//  Created by Khongmeng Kormoua on 2021. 04. 28..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Person.h"
#include <iostream>
#include <fstream>
using namespace std;

// Implementation of ISerializable::Save
void Person::Save(std::ostream& os)
{
    os << (int)age << ';' << height << ';' << weight << endl;
}

// Implementation of ISerializable::Load
void Person::Load(std::istream& is)
{
    double height; double weight; int age; char c;
    is >> age;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> height;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> weight;
    if(is)
    {
      this->age = age;
      this->height = height;
      this->weight = weight;
    }
    else
    {
      cerr << "Error in input format." << endl;
    }


// Write implementation for other member functions

}



// Getters and setters
void Person::SetHeight(double height) {
    if (height > 0) {                   // if the given height is not negative
        this->height = height;          // set this height as the given height
    }
}

double Person::GetHeight() {
    return height;                      // return this height
}

void Person::SetWeight(double weight) {
    if (weight > 0) {                   // if the given weight is not negative
        this->weight = weight;          // set this weight as a given weight
    }
}

double Person::GetWeight() {
    return weight;                      // return this weight
}




// Comparing with another Person object (equal?)
bool Person::operator ==(const IComparable& theOther) {
    if (this->height != ((const Person&)theOther).height) {             // check if this height is not equal to theOther's height
        return false;                                                   // return false
    } else if (this->weight != ((const Person&)theOther).weight) {      // if this weight is not equal to theOther's weight
        return false;                                                   // return false
    } else if (this->age != ((const Person&)theOther).age) {            // if this age is not equal to theOther's age
        return false;                                                   // return false
    }
    return true;                                                        // if everything is the same, return true
}

// Comparing with another Person object (less?)
bool Person::operator >(const IComparable& theOther) {
    if (this->age > ((const Person&)theOther).age) {              // if this age is greater than theOher's age
        return true;                                              // return true
    } else {                                                      // if this age is not greater than theOther's age
        return false;                                             // return false
    }
}

//
//  Person.h
//  lab09
//
//  Created by Khongmeng Kormoua on 2021. 04. 28..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef Person_h
#define Person_h

#include "IComparable.h"
#include "ISerializable.h"

class Person: public IComparable, public ISerializable
{
     double height;
     double weight;
public:
    unsigned char age;

    // Constructor
    Person(unsigned char age,double height, double weight): age(age), height(height), weight(weight) {}

    // Getters and setters
    void SetHeight(double height);
    double GetHeight();
    void SetWeight(double weight);
    double GetWeight();

    // Comparing with another Person object (equal?)
    bool operator ==(const IComparable& theOther);
    // Comparing with another Person object (less?)
    bool operator >(const IComparable& theOther);

    // Saving to file
    void Save(std::ostream &);
    // Loading from file
    void Load(std::istream &);
};


#endif /* Person_h */

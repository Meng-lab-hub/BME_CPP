//
//  circle.cpp
//  lab04_2
//
//  Created by Khongmeng Kormoua on 2021. 03. 03..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "circle.hpp"

// All definition of class's constructors and class's methods are here.


// A definition of a class's constructor
Circle::Circle (double input) {
    
    // in case a negative value is given when a class is initialized (a negative value is given to a radius of a Circle).
    if (input < 0) {
        cout << "You gave a negative value for a radius of a circle. Please give only a positive value" << endl;
        
        // assign 0 to a radius instead of a negative value.
        radius = 0;
    } else {
        // in case a positive value is given to a radius of a circle.
        radius = input;
    }
}

// A definition of method "area" which is used to calculate an area of a circle.
double Circle::area() {
    return radius * radius * PI;
}

// A definition of method "circumference" which is used to calculate a circumference of a circle.
double Circle::circumference() {
    return 2 * PI * radius;
}

// A definition of method "print" which is used to print all useful infomation (radius, circumference and area).
void Circle::print() {
    
    // print a radius.
    cout << "A radius of a circle is: " << radius << endl;
    
    // print an area.
    cout << "An area of a circle is: " << area() << endl;
    
    // print a circumference.
    cout << "A circumference of a circle is: " << circumference() << endl << endl;
}

//
//  rectangle.cpp
//  lab04_1
//
//  Created by Khongmeng Kormoua on 2021. 03. 03..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "rectangle.hpp"

// All definition of class's constructors and class's methods are here.

// A definition of a class's constructor (in case of 1 or no parameter is given when a class is initialized)
Rectangle::Rectangle (double input) {
    
    // in case a negative value is given when a class is initialized (a negative value is given to a sides of a Rectangle).
    if (input < 0) {
        cout << "You gave a negative value for a side of a rectangle. Please give only a positive value" << endl;
        
        // assign 0 to a sides instead of a given negative value
        sideX = 0;
        sideY = 0;
    } else {
        // in case a positive value is given to a sides of a rectangle.
        sideX = input;
        sideY = input;
    }
}


// A definition of a class's constructor (in case of 2 parameters are given when a class is initialized)
Rectangle::Rectangle (double inputX, double inputY) {
    
    // in case a negative values are given when a class is initialized (a negative values are given to a sides of a Rectangle).
    if (inputX < 0 || inputY < 0) {
        cout << "You gave a negative value(s) for a side(s) of a rectangle. Please give only a positive values." << endl;
        
        // assign 0 to a sides instead of a given negative value
        sideX = 0;
        sideY = 0;
    } else {
        // in case a positive values are given to a sides of a rectangle.
        sideX = inputX;
        sideY = inputY;
    }
}

// A definition of method "area" which is used to calculate an area of a rectangle.
double Rectangle::area() {
    // return back a value of area which is a multiplication of 2 sides.
    return sideX * sideY;
}

// A definition of method "perimeter" which is used to calculate a perimeter of a rectangle.
double Rectangle::perimeter() {
    // return back a value of perimeter which is 2 times to a addition of 2 sides.
    return 2 * (sideX + sideY);
}

// A definition of method "print" which is used to print all useful infomation (sides, perimeter and area).
void Rectangle::print() {
    
    // print 2 sides.
    cout << "A sides of a Rectangle are: " << sideX << " and " << sideY << endl;
    
    // print a perimeter.
    cout << "A perimeter of a Rectangle is: " << perimeter() << endl;
    
    // print an area.
    cout << "An area of a Rectangle is: " << area() << endl << endl;
}

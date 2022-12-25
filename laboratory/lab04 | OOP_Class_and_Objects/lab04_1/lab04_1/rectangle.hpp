//
//  rectangle.hpp
//  lab04_1
//
//  Created by Khongmeng Kormoua on 2021. 03. 03..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef rectangle_hpp
#define rectangle_hpp

// for cout
#include <iostream>
using namespace std;

// class "Rectangle": here are all the constructor, attribute and method declaration of a class. A definition for them will be in additional source file.
class Rectangle {
    // declaration of main attribute (2 sides of a rectangle) of a class "Rectangle".
    // these 2 sides variables are not accessible from outside of a class (private).
    double sideX;
    double sideY;
    
public:
    // Constructor of a class. used for initialize a values to the class's attributes base on a given value.
    // since we have to consider several cases (1 parameter, 2 parameters and no parameter) we use an overload function here for that.
    
    // in case when a class is initialized by only 1 value or without any given value (a default value which is 0 will be used).
    Rectangle (double = 0);
    
    // in case when a class is initialized by 2 values.
    Rectangle (double, double);
    
    
    
    // a class's method which is be used to print all the data (2 sides, area, perimeter) of a class to a display.
    void print();
    
    // a class's method which is used to calculate the area of a rectangle.
    double area();
    
    // a class's method which is used to calculate a perimeter of a rectangle.
    double perimeter();
};

#endif /* rectangle_hpp */

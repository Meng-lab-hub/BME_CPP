//
//  circle.hpp
//  lab04_2
//
//  Created by Khongmeng Kormoua on 2021. 03. 03..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef circle_hpp
#define circle_hpp

// for cout.
#include <iostream>
// we define PI as 3.14159, in a code we will use "PI" instead of a number which will be more understandable.
#define PI 3.14159

using namespace std;

// class "Circle": here are all the constructor, attribute and method declaration of a class. A definition for them will be in additional source file.
class Circle {
    // declaration of main attribute (a radius) of a class "Circle".
    // this variable is not accessible from outside of a class (private).
    double radius;
    
public:
    // Constructor of a class. used for initialize a values to the class's attribute base on a given value.
    // since we have to consider several cases (positive parameter, negative parameter and no parameter) we use an overload function here for that.
    Circle (double = 0);
    
    // a class's method which is be used to print all the data (radius, area, circumference) of a class to a display.
    void print();
    
    // a class's method which is used to calculate the area of a circle.
    double area();
    
    // a class's method which is used to calculate a circumference of a circle.
    double circumference();
};

#endif /* circle_hpp */

//
//  main.cpp
//  lab04_2
//
//  Created by Khongmeng Kormoua on 2021. 03. 03..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//


// add a header which we have all declaration and definition of our class.
#include "circle.hpp"


// here in main funciton we test all possibilities that we can initialize a class circle.
int main(void) {
    
    /* initialize a class circle with a positive parameter. */
    cout << "Circle A:" << endl;
    Circle A(3.5);
    
    // print all information of this circle.
    A.print();
    
    
    /* initialize a class circle with no parameter. */
    cout << "Circle B:" << endl;
    Circle B;
    
    // print all information of this circle.
    B.print();
    
    
    /* initialize a class circle with a negative parameter. */
    cout << "Circle C:" << endl;
    Circle C(-8.5);
    
    // print all information of this circle.
    C.print();
    
    return 0;
}

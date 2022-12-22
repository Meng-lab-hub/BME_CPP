//
//  main.cpp
//  lab04_1
//
//  Created by Khongmeng Kormoua on 2021. 03. 03..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

// add a header which we have all declaration and definition of our class.
#include "rectangle.hpp"



// here in main funciton we test all possibilities that we can initialize a class rectangle.
int main(void) {
    
    /* initialize a class rectangle with 2 positive parameters. */
    cout << "Rectangle A:" << endl;
    Rectangle A(10.3, 3);
    
    // print all information of this rectangle.
    A.print();
    
    
    /* initialize a class rectangle with 1 positive parameter. */
    cout << "Rectangle B:" << endl;
    Rectangle B(3.5);
    
    // print all information of this rectangle.
    B.print();
    
    
    /* initialize a class rectangle with no parameter. */
    cout << "Rectangle C:" << endl;
    Rectangle C;
    
    // print all information of this rectangle.
    C.print();
    
    
    /* initialize a class rectangle with 1 negative parameter and 1 positive parameter */
    cout << "Rectangle D:" << endl;
    Rectangle D(-1, 2.4);
    
    // print all information of this rectangle.
    D.print();
    
    
    /* initialize a class rectangle with 2 negative parameters */
    cout << "Rectangle E:" << endl;
    Rectangle E(-5.5, -6.2);
    
    // print all information of this rectangle.
    E.print();
    
    
    /* initialize a class rectangle with 1 negative parameter */
    cout << "Rectangle F:" << endl;
    Rectangle F(-8.5);
    
    // print all information of this rectangle.
    F.print();
    
    return 0;
}

//
//  main.cpp
//  lecture05
//
//  Created by Khongmeng Kormoua on 2021. 03. 09..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include <string>
// #include "TestClass.h"
#include <iostream>
#include <math.h>
using namespace std;

 


const double PI = 3.14159265;  // global const var

 

// Class is responsible for itself: the state of the object always remains consistent
class Point
{
    int x;
    int y;
    mutable int z;   // mutable = this attribute can be modified from const methods
    static const int resX;   //=640 is not supported by all compilers (not in the standard)
    static const int resY;

 

public:
    void setX(int nx)
    {
        if (nx < 0 || nx>1024)
        {
            // show error
        }
        else
            x = nx;
    }
    void setY(int ny)
    {
        if (ny < 0 || ny>768)
        {
            // show error
        }
        else
            y = ny;
    }

 

    int getQuarter() const      // const method
    {
        z = -60;
        if (x > 0 && x < 320 && y>0 and y < 240)
        {
            //x = -1;   // Makes the class object inconsistent!
            return 2;
        }
            
        //else if (...)
        //    return ...
    }

 

    /*void resetX(int x)
    {
        this->x = x;
    }*/

 

    void draw()
    {
        // ......
    }
    void moveRight()
    {
        if(x<resX)
            x++;

 

    }
    
    // Initialization list
    Point(int px = 0, int py = 0): x(px), y(py) {}

 

    // Default constructor
    //Point() {}

 

    // Default destructor
    ~Point() {}

 

    // Copy constructor
    Point(const Point& other)
    {
        x = other.x;
        y = other.y;
    }

 

    // Friend function
    friend double distance(const Point& p);

 

    // Friend classes also exist
    // (you allow other class to access private members of your class
    
};
const int Point::resX = 640;    // 100% according to the standard!
const int Point::resY = 480;

 


double distance(const Point& p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

 


int main()
{
    cout << 2 * PI * 10 << endl;

 

    Point A(3, 5);

 

    cout << A.getQuarter() << endl;

 

    A.draw();

 

    // Constants in C++
    // 1) Const reference parameters (used very often!)
    // 2) Const global variable
    // 3) Const (static) attribute of a class
    // 4) Const class methods

 

 

    // Dynamic memory management in C++
    // Allocate mem for array of 10 integers

 

    // Standard C
    //int* pa = (int*)malloc(10 * sizeof(int));  // Does not call the constructor! Function
    //if (pa == NULL)
    //    cout << "Problems with mem allocation" << endl;
    //else
    //{
    //    pa[0] = 76;
    //    pa[1] = -4;
    //    free(pa);
    //}

 

    //// C++
    //int* pa = new int[10];   // New is an operator. Does call a constructor!
    //// Successful?
    //// 1) Exception handling (bad_alloc)  <--- Recommended for C++
    //// 2) nothrow + check for null pointer
    //pa[0] = 76;
    //pa[1] = -4;

 

    ////delete pa;  // <-- For single element
    //delete[] pa; // <-- For array of elements

 


    //Point* pA = new Point(3, 4);
    //pA->moveRight();
    //delete pA;

 

    //Point A;
    //A.resetX(50);

 

    return 0;
}

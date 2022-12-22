//
//  main.cpp
//  Lecture09
//
//  Created by Khongmeng Kormoua on 2021. 04. 13..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include <iostream>
using namespace std;

 

class Shape {
protected:
    int width, height;
public:
    Shape(int a, int b) :width(a), height(b) {}
    //virtual int area()  // virtual function
    //{
    //    return -1;
    //}

 

    // pure virtual function
    virtual int area() = 0;

 

    void print_area()
    {
        cout << this->area() << endl;
    }

 


};
// If the class containts at least one P.V.F. then the class is
// called ABSTRACT CLASS. Abstract classes cannot be instantiated.

 

// If the class contains at least one V.F. then the class is
// called polymorphic.

 

 

class Rectangle : public Shape {
public:
    Rectangle(int a, int b) : Shape(a, b) {}
    int area()
    {
        return width * height;
    }
};

 

class Triangle : public Shape {
public:
    Triangle(int a, int b) : Shape(a, b) {}
    int area()
    {
        return width * height / 2;
    }
};

 

int main()
{
    Shape* shapes[2];  // container (array of the fixed length)
    // shapes is STATIC!
    // Shape a;
 

    shapes[0] = new Rectangle(3, 4);
    shapes[1] = new Triangle(5, 2);
    // Uniform storage is OK up to here

 

    for (int i = 0; i < 2; i++)
    {
        shapes[i]->print_area();
        //cout << shapes[i]->area() << endl;
    }
    // Uniform handling is also OK up to here
    // Usage . . . .

 

    // Do not need anymore
    for (int i = 0; i < 2; i++)
        delete shapes[i];
    
    return 0;
}

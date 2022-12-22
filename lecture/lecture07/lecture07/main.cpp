//
//  main.cpp
//  lecture07
//
//  Created by Khongmeng Kormoua on 2021. 03. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include <iostream>
using namespace std;

 

class Vector
{
    int x, y;
public:
    Vector(int x, int y) : x(x), y(y) {}
    Vector() : x(0), y(0) {}

 

    void print() const
    {
        cout << "(" << x << ";" << y << ")" << endl;
    }
    Vector operator+(const Vector& b) const
    {
        return Vector(x + b.x, y + b.y);
        //Vector c;
        //c.x = x + b.x;
        //c.y = y + b.y;
        //return c;
    }
    Vector operator-(const Vector& b) const
    {
        return Vector(x - b.x, y - b.y);
    }

 

    int operator*(const Vector& b) const
    {
        return x * b.x + y * b.y;
    }

 

    Vector operator*(int num) const
    {
        return Vector(x * num, y * num);
    }

 

    Vector operator~() const
    {
        return Vector(y, x);
    }

 

//    Vector operator** ()   new operator cannot be created!

 

    friend Vector operator*(int num, const Vector& v);
};

 


Vector operator*(int num, const Vector& v)
{
//    return v * num;
    return Vector(num * v.x, num * v.y);
}

 

int main()
{
    Vector a(3, 6);
    Vector b(-1, 5);
    Vector c;
    Vector v;
    int d;

 

    int k, l = 6, m = 9;
    k = l + m;  // want to overload operator+(int, int)  ---> IMPOSSIBLE
    // operator+(int, Complex)  OK
    v = a * 5;
    v = 5 * a;  // only solution: global function!   int.operator+(Vector) is not possible!

 

    c = a + b;
    c = a - b;
    d = a * b;  // scalar product

 

    v=~a; // swap the coordinates :)        a.operator~()

 

    // HOMEWORK:
    // overloading of << and >> operators (print and input)
    // task: read the vector like cin>>v;
    //       write the vector like cout<<v;
    //       not use the print method: v.print() should be avoided

 


    c.print();
    // Two options
    // 1) as a member-function (class method): c=a.operator+(b) <--- PREFER THIS!
    // 2) globally (global function):  c = operator+(a,b)
    return 0;

 

    //int a, b, c;
    //a = b + c; //   rewrite in form of an operator function
    //           //   a = b.operator+(c);  as a method of left-hand operand
    //           //   a = operator+(b,c);  global function
    //a = b++;   // postfix increment  operator++(int)
    //a = ++b;   // prefix increment   operator++()
    //a[]        // array subscript   operator[]()
    //a = b > c ? b : c;  // ternary   EXPR ? RET1 : RET2  ---> cannot be overloaded :)
    // Operators, which you cannot overload in C++
    // ?:
    // . (dot operator, member selection)
    // :: scope
    // sizeof
    // some more...

 


}

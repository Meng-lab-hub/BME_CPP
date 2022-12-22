//
//  main.cpp
//  lecture08
//
//  Created by Khongmeng Kormoua on 2021. 03. 30..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

    
#include <string>
//#include "TestClass.h"
#include <iostream>
using namespace std;



// INHERITANCE


// Syntax:
//class derived_class_name : visibility_mode base_class_name
//{
//    // body
//}​​​​​​​;


class Employee
{
    //...
public:
    int salary;
    void work() const
    {
        cout << "working..." << endl;
    }
};

// public inheritance: preserves the visibility of inherited elements
                       // public --> public
                       // protected --> protected
                       // private --> private
                       // almost always used!!
// protected inheritance
// private inheritance


class SoftDev : public Employee
{
    //...
public:
    int bonus;
    void writeCode() const
    {
        cout << "coding..." << endl;
    }
    void work() const    // class method overriding, method is the same,
                         // but the body is different in the derived class
    {
        cout << "programming..." << endl;
    }
};

// Not everything is inherited!
// - constructors and destructors  !!!!!
// - operator=()
// - friends (functions and classes)



class A
{
private:
    double d;
public:
    float f1;
    A() {}
    A(double dv) : d(dv)
    {
        cout << "Constructor of the PARENT was called" << endl;
    }
    // other functionality
};

class B: public A
{
private:
    int v;
    using A::f1;        //restriction of visibility; "using" is added by xcode
                // You can restrict the visibility, but cannot ease it!
public:
    B() {}
    B(double dv1, int vv) : v(vv), A(dv1)
    {
        cout << "Constructor of the CHILD was called" << endl;
    }
};


// Order of the call in ****:
// 1) Memory allocation for items of A
// 2) Calling constructor of A (the parent)
// 3) Memory allocation for items of B
// 4) Calling constructor of B (derived)



// HOMEWORK!!
// Study "Multiple Inheritance"!  in C++



int main()
{
    B smth(3.14, 7);   // ****


                       //A obj(55.4);



    //Employee John;
    //John.salary = 350000;
    //SoftDev Bill;
    //Bill.bonus = 30000;
    //Bill.salary = 500000;
    //Bill.work();  // inherited from Employee, because every Software Developer
    //              // is also an Employee
    //Bill.writeCode();


    return 0;
}



//
//class Vector
//{
//    int x, y;
//public:
//    Vector(int x, int y) : x(x), y(y) {​​​​​​​}
//    Vector() : x(0), y(0) {​​​​​​​}
//
//    Vector operator+(const Vector& b) const
//    {
//        return Vector(x + b.x, y + b.y);
//        //Vector c;
//        //c.x = x + b.x;
//        //c.y = y + b.y;
//        //return c;
//    }
//    Vector operator-(const Vector& b) const
//    {
//        return Vector(x - b.x, y - b.y);
//    }
//
//    int operator*(const Vector& b) const
//    {
//        return x * b.x + y * b.y;
//    }
//
//    Vector operator*(int num) const
//    {
//        return Vector(x * num, y * num);
//    }
//
//    Vector operator~() const
//    {
//        return Vector(y, x);
//    }
//
////    Vector operator** ()   new operator cannot be created!
//
//    friend Vector operator*(int num, const Vector& v);
//    friend ostream& operator<<(ostream& os, const Vector& v);
//    friend istream& operator>>(istream& is, Vector& v);
//}​​​​​​​;
//
// Overloading of operator<<
//ostream& operator<<(ostream& os, const Vector& v)
//{
//    // How do we want to see the vector on the screen? ---> (X,Y)
//    os << "(";
//    os << v.x;
//    os << ";";
//    os << v.y;
//    os << ")";
//    return os;
//}
//
//istream& operator>>(istream& is, Vector& v)
//{
//    cout << "The vector coordinates" << endl;
//    cout << "Horizontal (x): ";
//    is >> v.x;
//    cout << "Vertical (y): ";
//    is >> v.y;
//    return is;
//}



//Vector operator*(int num, const Vector& v)
//{
////    return v * num;
//    return Vector(num * v.x, num * v.y);
//}
//
//int main()
//{
//    Vector a(3, 6);
//    Vector b(-1, 5);
//    Vector c;
//    Vector v;
//    int d;
//
//    int k, l = 6, m = 9;
//    k = l + m;  // want to overload operator+(int, int)  ---> IMPOSSIBLE
//    // operator+(int, Complex)  OK
//    v = a * 5;
//    v = 5 * a;  // only solution: global function!   int.operator+(Vector) is not possible!
//
//    c = a + b;
//    c = a - b;
//    d = a * b;  // scalar product
//
//    v=~a; // swap the coordinates :)        a.operator~()
//
//    // HOMEWORK:
//    // overloading of << and >> operators (print and input)
//    // task: read the vector like cin>>v;
//    //       write the vector like cout<<v;
//    //       not use the print method: v.print() should be avoided
//
//    cout << k << m << endl;
//    cout << c << c << c << endl << endl;
//    Vector s;
//    cin >> s;
//    cout << endl;
//    cout << s;
//
//
//    // Two options
//    // 1) as a member-function (class method): c=a.operator+(b) <--- PREFER THIS!
//    // 2) globally (global function):  c = operator+(a,b)
//    return 0;
//
//    //int a, b, c;
//    //a = b + c; //   rewrite in form of an operator function
//    //           //   a = b.operator+(c);  as a method of left-hand operand
//    //           //   a = operator+(b,c);  global function
//    //a = b++;   // postfix increment  operator++(int)
//    //a = ++b;   // prefix increment   operator++()
//    //a[]        // array subscript   operator[]()
//    //a = b > c ? b : c;  // ternary   EXPR ? RET1 : RET2  ---> cannot be overloaded :)
//    // Operators, which you cannot overload in C++
//    // ?:
//    // . (dot operator, member selection)
//    // :: scope
//    // sizeof
//    // some more...
//
//
//}
//
//
 

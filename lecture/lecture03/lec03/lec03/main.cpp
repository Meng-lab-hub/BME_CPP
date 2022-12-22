//#include <string>
//using namespace std;
//#include "classTest.hpp"
//
//// DRY principle: Don't Repaet Yourself
//
//// CLASS - user-defined data type with data members (attributes) and member functions (methods)
//// Class = fruit, objects (instances) - apple, banana, orange
//
//// OBJECT - identifiable entity, instance of a Class
//
//// 2 possibilities for defining a class (important for final project)
//
///*
//// First: inline
//class TestClass {       // class
//public:                 // access specifier (visibility)
//    int num;            // attribute (int)
//    string s;           // attribute (string)
//    int incrementNum() {
//        num++;
//        return num;
//    }
//};                      // end of class defination
//*/
//
//// Second (prefered) in big projects and distributed projects, must be used in final project
//// separated definition: header(.h) + implementation(.cpp)
//
//
//// 00 Concepts:
//// 1. Encapsulation data(properties, attributes) and functions (methods) are included to a single unit
//// 2. Data Hiding (Information Hiding)
//// 3. Polymorphism and Inheritance
//
//
//// Visibility modifiers;
//// public: from "anywhere"
//// private: only from the methods of the actual class, NOT from outside
//// protected: (used with inheritance) only from the methods of the actual class + from the inherited class
//
//
//// Class is responsible for itself: the state of the object always remains consistent
//class Point {
//private:
//    int x;
//    int y;
//public:
//    void init() {
//        x = 0;
//        y = 0;
//    }
//    void setX(int nx) {
//        if (x < 0 || x > 640) {
//            //Show error
//        }
//        else
//            x = nx;
//    }
//    void setY(int ny) {
//        if (y < 0 || y > 640) {
//            //Show error
//        }
//        else
//            y = ny;
//    }
//    void draw() {
//        //...
//    }
//    void moveRight() {
//        x++;
//    }
//
//};
//
//// Difference between class (C++) and structure (C):
//// - classes have attribute + methods
//// - default visibility in structures is "public", in class it is "private"
//
//int main(void) {
//    /*
//    TestClass t1;               // create an instance
//    t1.num = 55;
//    t1.s = "something";
//
//    TestClass t2;
//    t2.num = 65;
//    t2.s = "something else";
//
//    t2.incrementNum();
//     */
//    Point A;
//    // A.init
//    //A.x = -100;         // Problem: direct access to x and y!!     Solution: interface!
//    //A.y = 900000000;
//
//    A.setX(-100);       // error
//    A.setY(5000);
//    A.draw();
//
//    Point B;
//    B.draw();           // runtime error
//    return 0;
//}
//
//
//
//
//
//
///*
//
//int maxNum(int a, int b)
//{
//    return a > b ? a : b;
//
//    //if (a > b)   tha same!!
//    //    return a;
//    //else return b;
//}
//double inline maxNum(double a, double b)
//{
//    return a > b ? a : b;
//}
//float inline maxNum(float a, float b)
//{
//    return a > b ? a : b;
//}
//
//double maxNum(float a, float b, int g)
//{
//    //
//    return 10.0;
//}
//
//
////.. char, unsigned, ...
//
//
//void f(int x, int y=10, double d=3.14)  // default argument can be defined
//                                        // right->to->left only!
//{
//    // ...
//    // ...
//}
//
//
//int main()
//{
//    // In C:
//    f(1, 2, 3);
//
//    // In C++
//    f(1, 2, 3);   // x=1  y=2  d=3
//    f(1, 2);     // x=1  y=2  d=3.14 (default)
//    f(1);        // x=1  y=10(default)  d=3.14(default)
////    f();           // Compiler error
////    f(1, , 5.67);  // Compiler error
//    f(1,10,5.67); // OK
//
//
//
//    double a = 3.14, b = 2.72, c;
//    //c = maxNum(a,b);
//    c = a > b ? a : b;
//
//
//    // New in C++
//    // Function overloading
//    // Inline functions
//    // Default argument lest OR Default function parameters
//    // Constants a) const pointers, b) const parameters (ref& par) c) [const class methods]
//
//    // Storing data in (C, C++) programs
//    // 1) global
//    // 2) heap
//    // 3) stack
//
//    //FUNCTION CALL
//    //1) save the returning address
//    //2) load the function being called into memory
//    //3) copy argument values
//    //4) jump to function
//    //5) execute the function body (!!)
//    //6) store the return value on the stack
//    //7) jump back to the saved address
//    //8) read the returning value from the stack
//    // OVERHEAD!
//
//    char bop[] = "Basics of Programming 2";  // Fixed length char array
//    const char* p1 = bop;
//    //*p1 = 'a';    // error; changing the character
//    p1++;            // ok: shifting the pointer (to the right)
//
//    char* const p2 = bop;
//    *p2 = 'a';    // ok
//    //p2++;            // error
//
//    const char* const p3 = bop;
//    //*p3 = 'a';  // error
//    //p3++;        // error
//
//    // C++
//    //...
//    int sum = 0;
//    for (int i = 1; i <= 100; i++)
//        sum = sum + i;
//    // ...
//    return 0;
//}
//
//*/
//
//









// from professor

#include <string>
#include "classTest.hpp"
using namespace std;
 

// DRY principle: Don't Repeat Yourself
 
// CLASS  - user-defined data type with data members (attributes) and member functions (methods)
// Class = fruit, objects (instances) - apple, banana, orange
 
// OBJECT - identifiable entity, instance of the Class
 
// 2 possibilities for defining a class (important for Final Project!)
 
 
//Second (prefered) in big projects and distributed projects, must be used in Final Projects
// separated definition: HEADERS (.h)+IMPLEMENTATION(.cpp)
 
// OO Concepts:
// 1) Encapsulation: data (properties, attributes) and functions (methods) are included to a single unit (class)
// 2) Data Hiding (Information Hiding)
// 3) Polymorphism and Inheritance
 

// Visibility modifiers:
// public: from "anywhere"
// private: only from the methods of the actual class, NOT from outside
// protected: (used with inheritance) only from the methods of the actual class + from the inherited classes
 
// Class is responsible for itself: the state of the object always remains consistent
class Point
{
    int x;
    int y;
public:
    void init() {
        x = 0;
        y = 0;
    }
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
    void draw()
    {
        // ......
    }
    void moveRight()
    {
        x++;
    }
};

// Difference between class (C++) and structure (C):
//- classes have attributes + methods
//- default visibility in structures is "public", in classes it is "private"
 
int main()
{
    Point A;
    //A.init();
    A.setX(300);   // ERROR!!
    A.setY(410);
    A.draw();
 
    Point B;
    B.setX(860);
 
    Point C;
    C.draw();   // Runtime error, because x and y are memory garbage (no initialization!)
                // Solution: constructors!

    //TestClass t1;     // create an instance
    //t1.num = 55;
    //t1.s = "something";
 
    //TestClass t2;
    //t2.num = 67;
    //t2.s = "Something else";
 
    //t2.incrementNum();
 

    return 0;
}

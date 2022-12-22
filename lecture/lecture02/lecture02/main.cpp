//
//  main.cpp
//  testFile
//
//  Created by Khongmeng Kormoua on 2021. 02. 10..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

//#include <stdio.h>
//
//double g;    // global variable
//
//int max_num(int a, int b) {         // max_num int int (function overloading)
//    //int c;  // local variable
//    if (a > b)
//        return a;
//    else return b;
//}
//
//double inline max_num(double a, double b) {        // max_num double double (function overloading)
//    return a > b? a:b;
//}
//float inline max_num(float a, float b) {       // max_num float float (function overloading) and inline function
//    return a > b? a:b;
//}
//
//void f(int x, int y = 10, double d = 3.14) {        // default argument can be defined right to left only
//                                                    // f(int x, int y = 10, double d) error
//    //
//    //
//}
//
//int main(void) {
//    // new in C++:
//    // reference variable
//    // Function overloading
//    // inline function
//    // default argument lest or default function parameters
//    // constants a) const pointers, b) const parameters (ref& par), c) const class method
//
//    double a = 3.14, b = 2.72, c;
//    c = max_num(a, b);
//    printf("%.2lf\n", c);
//
//    int sum = 0;
//    for (int i = 1; i <= 100; i++)
//        sum = sum + i;
//
//
//    // in C++
//    f(1, 2, 3);     // x = 1, y = 2, d = 3
//    f(1, 2);        // x = 1, y = 2, d = 3.14 (default)
//    f(1);           // x = 1, y = 10 (default), d = 3.14 (default)
//    //f();            // error
//    //f(1, ,6.6);     // error, can't skip like this
//
//
//    char bop[] = "Basic of Programming 2";        // fixed length char array
//    const char* p1 = bop;       // read only pointer, can shift along the array
//    //*p1 = 'a';    this is bad case, character must be constant
//    //*p1++;        this is okay
//
//    char* const p2 = bop;       // pointer can't go to anywhere
//    //*p1 = 'a';    this is okay
//    //p2++;        this is bad case, pointer here must be constant
//
//    const char* const p3 = bop;     // fixed pointer, can't go anywhere, can't do anything
//    //*p1 = 'a';    error
//    //*p1++;        error
//
//    return 0;
//}



 
 // DRY principle: Don't Repaet Yourself
 
 int maxNum(int a, int b)
 {
     return a > b ? a : b;

     //if (a > b)   tha same!!
     //    return a;
     //else return b;
 }
 double inline maxNum(double a, double b)
 {
     return a > b ? a : b;
 }
 float inline maxNum(float a, float b)
 {
     return a > b ? a : b;
 }
  
 double maxNum(float a, float b, int g)
 {
     //
     return 10.0;
 }
  

 //.. char, unsigned, ...
  

 void f(int x, int y=10, double d=3.14)  // default argument can be defined
                                         // right->to->left only!
 {
     // ...
     // ...
 }
  

 int main()
 {
     // In C:
     f(1, 2, 3);
  
     // In C++
     f(1, 2, 3);   // x=1  y=2  d=3
     f(1, 2);     // x=1  y=2  d=3.14 (default)
     f(1);        // x=1  y=10(default)  d=3.14(default)
 //    f();           // Compiler error
 //    f(1, , 5.67);  // Compiler error
     f(1,10,5.67); // OK
  
  
  
     double a = 3.14, b = 2.72, c;
     //c = maxNum(a,b);
     c = a > b ? a : b;
  

     // New in C++
     // Function overloading
     // Inline functions
     // Default argument lest OR Default function parameters
     // Constants a) const pointers, b) const parameters (ref& par) c) [const class methods]

     // Storing data in (C, C++) programs
     // 1) global
     // 2) heap
     // 3) stack
  
     //FUNCTION CALL
     //1) save the returning address
     //2) load the function being called into memory
     //3) copy argument values
     //4) jump to function
     //5) execute the function body (!!)
     //6) store the return value on the stack
     //7) jump back to the saved address
     //8) read the returning value from the stack
     // OVERHEAD!
  
     char bop[] = "Basics of Programming 2";  // Fixed length char array
     const char* p1 = bop;
     //*p1 = 'a';    // error; changing the character
     p1++;            // ok: shifting the pointer (to the right)
  
     char* const p2 = bop;
     *p2 = 'a';    // ok
     //p2++;            // error
  
     const char* const p3 = bop;
     //*p3 = 'a';  // error
     //p3++;        // error
  
     // C++
     //...
     int sum = 0;
     for (int i = 1; i <= 100; i++)
         sum = sum + i;
     // ...
     return 0;
 }


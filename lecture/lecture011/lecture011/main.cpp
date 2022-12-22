//
//  main.cpp
//  lecture011
//
//  Created by Khongmeng Kormoua on 2021. 04. 20..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

 

// Fraction class
// 7/9  1/3  class
// 30  ->  30/1
// How to acieve it:
// 1) Conversion constructor:   from anything TO Fraction
// 2) Conversion operator       from Fraction TO anything else
// Prefer conversion constructor to operator!

 

class Fraction
{
    int numer, denom;
public:
    Fraction(int n, int d) : numer(n), denom(d) {}
    // Conv. cons. to convert integers to fractions
    Fraction(int n) : numer(n), denom(1) {}
    
    // explicit Fraction(int n) : numer(n), denom(1) {}
    
    
    //Fraction(double d) : .....
    //        Fraction(string fs) {...}
    // Parameter of a conv. cons. should be an already existing type

 

    // Conversion operator:
    // - No return type (no void)
    // - No parameters

 

    operator double()
    {
        return (double)numer / denom;
        // Error: 1) int / int  2) result is int  3) int -> double
        // Solution: int to double first, to have double/int -> result is double
    }

 

    operator string()
    {
        string n = to_string(numer);
        string d = to_string(denom);
        string r;
        r.append(n);
        r.append("/");
        r.append(d);
        return r;
        // int-> string for numerator and denominator
        // combine strings with separator "/"
        // return the result
    }
        
    // explicit keyword to restrict the implicit calls of the conv. constructor

 

    Fraction operator* (const Fraction& f)
    {
        return Fraction(numer * f.numer, denom * f.denom);
    }
};
// Ambiguities are important!!

 


int main()
{
    Fraction frac1(8);        // Constructor: conversion constructor explicit call!
    Fraction Frac2 = 109;    // The same

 

    // Constructor call explicitly: name_of_the_class(parameters)
    Fraction f10(7, 9);
    // Otherwise: implicit call
    f10 = 5 * 3;  // called by the compiler

 

 

    frac1 = 90;   // Conv. cons. is called for 90 -> fraction 90/1 -> assigned to frac1
    frac1 = (Fraction)36;   // C-style typecast: DEPRECATED (consider not using)
    frac1 = Fraction(36);    // Use this instead! Explicit constr. call

 

    Fraction f1(3, 5);
    Fraction f2(2, 7);
    Fraction f3 = f1 * f2;  // f3 = f1.operator*(f2)

 

    double d;
    d = f1;  // waiting for 0.6

 

    int i;
    i = f1;
    // Conversion from Fraction to double (done by conv. oper.)
    // Missing step: double -> integer (automatic conversion by compiler)
    // Note: possible loss of data (from wider type to smaller type)

 


    Fraction f5 = f1 * Fraction(4);    // do not have operator* (int) !!!
                            // Step1: 4 is converted to Fraction (4,1) based on the conv. cons.
                            // Step2: two fractions are multiplied by operator*(Fraction), which we already have
    // Result: 12/4;
    Fraction f6(3,5);

 

    string fstr = f6;
    cout << fstr << endl;

 

    return 0;
}

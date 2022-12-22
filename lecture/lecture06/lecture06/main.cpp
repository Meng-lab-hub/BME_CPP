//
//  main.cpp
//  lecture06
//
//  Created by Khongmeng Kormoua on 2021. 03. 16..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

    
#include <string>
//#include "TestClass.h"
#include <iostream>
using namespace std;
// Namespace pollution


const double PI = 3.14159265;  // global const var


// STATIC keyword in C++
//1) static variables
//2) static members of the class
                               
void func()
{
    static int cnt = 0;   // gets allocated for the lifetime of the program
    cout << cnt << endl;
    cnt++;
}


class StEx
{
private:
    static int v;   // Exists even without any class instances (class objects)
public:
    static void SetV(int vx)
    {
        // Validation: if(...)
        v = vx;
    }
    static int GetV()
    {
        return v;
    }
    void func()
    {
        //....
    }
};
int StEx::v = 0;



// A class, which keeps track on the number of its active instances (objects)


class A
{
    static int counter;
public:
    // Regular attributes of the class
    int x, y;
    // Regular methods of the class
    void smth() {
        
    }
    A()
    {
        //...
        counter++;
    }
    ~A() {
        counter--;
        
    }
    static int getCount()
    {
        return counter;
    }
};
int A::counter = 0;  // Initial value for counter (zero)


// NAMESPACES


// LIB1 (quick, but not exact)
namespace QuickGeometry
{
    const double pi = 3.1;
    double circumf(double R) {
        return 2 * pi * R;
        
    }
}
// End of LIB1


// LIB2 (slow, but exact)
namespace ExactGeometry
{
    const double pi = 3.1415926535;
    double circumf(double R) {
        return 2 * pi * R;
        
    }
}
// End of LIB2


void somefunc()
{
    using namespace QuickGeometry; // starts here
    cout << circumf(65) << endl;   // circumf of the QuickGeometry
} // finishes here



int main()
{
    // NAMESPACES:
    //using namespace QuickGeometry;
    //using namespace ExactGeometry;
    double R;
    R = 60.3;
    cout << QuickGeometry::circumf(R) << endl;
    cout << ExactGeometry::circumf(R) << endl;

 
    
    // STATIC:
    //A a1;
    //A a2;
    //A a3;
    //cout << "Instances of A: " << A::getCount() << endl;
    //




    ///*for (int i = 0; i < 10; i++)
    //    func();*/


    //// Static variables are shared among the instances of the class
    ////StEx::v = -95;  // Value assignment by using scope resolution (only to static!)
    //StEx::SetV(-95);
    //
    StEx obj1;
    StEx obj2;


//    obj1.v = 30;
//    obj2.v = -66;
    
    obj2.SetV(2);
    StEx::SetV(3);
    obj1.SetV(1);

    cout << obj1.GetV() << "   " << obj2.GetV() << endl;


    return 0;
}

//
//  main.cpp
//  lec13
//
//  Created by Khongmeng Kormoua on 2021. 05. 04..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;
// Generic types and Templates:
//1) Function template
//2) Class template
// Need: template parameter, special type of parameter, which is used to pass type as an argument
//int func(int a, int b)
//{
//  if (a < b) return a;
//  else return b;
//}
//
//double func(double a, double b)
//{
//  if (a < b) return a;
//  else return b;
//}
//
//char func(char a, char b)
//{
//  if (a < b) return a;
//  else return b;
//}
//Format
// template <class TypeID> function_declaration
// { body }
template <class T>   //myType is a type parameter
T getMin(T a, T b)
{
    if (a < b) return a;  // (must have operator<)
    else return b;
}
template<class U, class W>
U getMax(U a, W b)
{
    if (a > b) return a;
    else return b;
}
//class Point{...};

// Class Template
template<class T=double>
class MyPairContainer
{
    T values[2];   // contains 2 items of any valid type
public:
    MyPairContainer(T first, T second)
    {
        values[0] = first;
        values[1] = second;
    }
    T getMin() const
    {
        if (values[0] < values[1]) return values[0];
        else return values[1];
    }
    void swap()
    {
        T temp = values[0];
        values[0] = values[1];
        values[1] = temp;
    }
    // ...
};
template<class T>
class container
{
    T item;
public:
    container(T i) : item(i) {}
    T increase()
    {
        return ++item;
    }
};
// Template specialization (for char)
template<>
class container<char>
{
    char item;
public:
    container(char c) : item(c) {}
    char uppercase()
    {
        if ((item >= 'a') && (item <= 'z'))
            item += 'A' - 'a';
        return item;
    }
};
//template<>
//class container<long>
//  ...
int main()
{
    // TEMPLATE SPECIALIZATION
    container<int> c1(7);
    int d;
    d = c1.increase();
    
    container<char> c2('q');
    char c = c2.uppercase();
    

    //CLASS TEMPLATE
    MyPairContainer<> objInt(6, 7);  // created as a double, because of default T=double
    // and
    MyPairContainer<int> objIntm(6, 7);  // created as int
    // not the same!
    MyPairContainer<double> objDouble(56.32, 7.54);
    //objInt.getMin();
    objDouble.swap();
    // FUNCTION TEMPLATE
    int x = 4, y = 7, z;
    double w;
    //z = func(9.0, 6.0);
    z = getMin<int>(x, y);
    w = getMin<double>(5.0, 10.6);
    //getMin<Point>(...)   // works if if operator< is overloaded for Point class
    // Can be done like this:
    w = getMin(5.0, 9.1);
    w = getMax<double, int>(3.0, 90);
    w = getMax(3.14, 28);
    return 0;
}

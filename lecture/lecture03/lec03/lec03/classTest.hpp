//
//  classTest.hpp
//  lec03
//
//  Created by Khongmeng Kormoua on 2021. 02. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef classTest_hpp
#define classTest_hpp

#include <string>
using namespace std;

// First: inline
class TestClass {       // class
public:                 // access specifier (visibility)
    int num;            // attribute (int)
    string s;           // attribute (string)
    int incrementNum();
};                      // end of class defination
#endif /* classTest_hpp */

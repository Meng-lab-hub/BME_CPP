//
//  classTest.cpp
//  lec03
//
//  Created by Khongmeng Kormoua on 2021. 02. 23..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "classTest.hpp"

// implementation


// :: - scope operator
int TestClass::incrementNum() {
    // "this" pointer
    this->num = this->num + 1;
    // this->num++; same as num++
    num++;
    return num;
}

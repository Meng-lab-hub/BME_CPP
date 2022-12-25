//
//  Equipment.cpp
//  lab08
//
//  Created by Khongmeng Kormoua on 2021. 04. 14..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Equipment.h"

// constructor
Equipment::Equipment(int a, int b) : idenNum(a), price(b) {} // we will check later if int idenNum and int price

void Equipment::print(void) {
    std::cout << "Identification Number: " << idenNum << std::endl;
    std::cout << "Price: " << price << std::endl;
    
    printChildProperties();
}

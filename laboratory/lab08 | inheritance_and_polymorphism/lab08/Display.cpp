//
//  Display.cpp
//  lab08
//
//  Created by Khongmeng Kormoua on 2021. 04. 14..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Display.h"

Display::Display(int a, int b, int c) : Equipment(a, b) {
    this->yearOfAppro = c;
}

void Display::printChildProperties(void) {
    std::cout << "Year of Appropriation: " << yearOfAppro << std::endl;
}

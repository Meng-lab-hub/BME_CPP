//
//  Printer.cpp
//  lab08
//
//  Created by Khongmeng Kormoua on 2021. 04. 14..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Printer.h"


Printer::Printer(int a, int b, int c) : Equipment(a, b) {
    this->printSpeed = c;
}

/*
Printer::Printer(int a, int b, int c) {
    idenNum = a;
    price = b;
    printSpeed = c;
}
*/
void Printer::printChildProperties(void) {
    std::cout << "Printing Speed: " << printSpeed << std::endl;
}

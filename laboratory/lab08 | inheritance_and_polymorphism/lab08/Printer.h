//
//  Printer.h
//  lab08
//
//  Created by Khongmeng Kormoua on 2021. 04. 14..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef Printer_h
#define Printer_h

#include "Equipment.h"

class Printer : public Equipment {
private:
    int printSpeed;
public:
    Printer(int a = 0, int b = 0, int c = 0);
    // ~Printer();
    
    void printChildProperties(void);
};

#endif /* Printer_h */

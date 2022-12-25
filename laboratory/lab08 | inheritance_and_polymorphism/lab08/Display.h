//
//  Display.h
//  lab08
//
//  Created by Khongmeng Kormoua on 2021. 04. 14..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef Display_h
#define Display_h

#include "Equipment.h"

class Display : public Equipment {
private:
    int yearOfAppro;
public:
    Display(int a = 0, int b = 0, int c = 0);
    // ~Display();
    
    void printChildProperties(void);
};

#endif /* Display_h */

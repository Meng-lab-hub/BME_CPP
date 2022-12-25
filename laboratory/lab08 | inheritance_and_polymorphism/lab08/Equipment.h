//
//  Equipment.h
//  lab08
//
//  Created by Khongmeng Kormoua on 2021. 04. 14..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef Equipment_h
#define Equipment_h

#include <iostream>

class Equipment {
private:
    int idenNum;
    int price;
public:
    Equipment(int a = 0, int b = 0);
    // ~Equipment();
    
    virtual void printChildProperties(void) = 0;
    void print(void);
};

#endif /* Equipment_h */

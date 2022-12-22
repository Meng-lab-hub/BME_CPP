//
//  IComparable.h
//  lab09
//
//  Created by Khongmeng Kormoua on 2021. 04. 28..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef IComparable_h
#define IComparable_h

// This class provides interface for comparing ('equality' check, 'greater than' check)
class IComparable
{
public:
    virtual bool operator ==(const IComparable& )=0;
    virtual bool operator >(const IComparable& )=0;
};

#endif /* IComparable_h */

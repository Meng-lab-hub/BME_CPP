//
//  ISerializable.h
//  lab09
//
//  Created by Khongmeng Kormoua on 2021. 04. 28..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef ISerializable_h
#define ISerializable_h

#include <iostream>

// This class provides interface for saving/loading
class ISerializable
{
public:
    virtual void Save(std::ostream &)=0;
    virtual void Load(std::istream &)=0;
};

#endif /* ISerializable_h */

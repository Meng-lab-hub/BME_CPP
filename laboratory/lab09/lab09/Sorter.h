//
//  Sorter.h
//  lab09
//
//  Created by Khongmeng Kormoua on 2021. 04. 28..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#ifndef Sorter_h
#define Sorter_h

#include "IComparable.h"

class Sorter
{
public:
  static void BubbleSort(IComparable** pItems, unsigned itemCount);
  static void QuickSort(IComparable ** pItems, unsigned itemCount);
  // Other sorting algorithms can be implemented here...

};

#endif /* Sorter_h */

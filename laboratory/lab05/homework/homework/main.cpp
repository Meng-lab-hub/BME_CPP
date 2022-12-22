//
//  main.cpp
//  homework
//
//  Created by Khongmeng Kormoua on 2021. 03. 11..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Fifo.h"
using namespace std;

int main(void) {
    
    FIFO list1;         // initialize first FIFO "list1"
    
    // push some values (1, 2, 3) to list1
    list1.push(1);
    list1.push(2);
    list1.push(3);
    
    // print out all the elements in list1
    cout << "List 1:";
    list1.print();
    
    // pop out the firstly entered element from list1
    cout << endl;
    cout << "we pop out: " << list1.pop() << " from List 1" << endl;
    cout << endl;
    
    // print out all the elements in list1
    cout << "List 1:";
    list1.print();
    
    // pop out the first element in a queue of list1
    cout << endl;
    cout << "we pop out: " << list1.pop() << " from List 1" << endl;
    cout << endl;
    
    // print all the elements in list1
    cout << "List 1:";
    list1.print();
    
    // push some values (54, 124, 11) to list1 again
    list1.push(54);
    list1.push(124);
    list1.push(11);
    
    // print all the elements in list1
    cout << endl;
    cout << "List 1:";
    list1.print();
    
    // pop out the first element in a queue of list1
    cout << endl;
    cout << "we pop out: " << list1.pop() << " from List 1" << endl;
    cout << endl;
    
    // print all the elements in list1
    cout << "List 1:";
    list1.print();
    
    // pop out the first element in a queue of list1
    cout << endl;
    cout << "we pop out: " << list1.pop() << " from List 1" << endl;
    cout << endl;
    
    // print all the elements in list1
    cout << "List 1:";
    list1.print();
    
    FIFO list2(list1);      // initialize a second FIFO "list2" and copy all the data from list1 to list2
    
    // print all the elements in list2
    cout << endl;
    cout << "List 2:";
    list2.print();
    
    // push some values (38, 0) to list2
    list2.push(38);
    list2.push(0);
    
    // print all the elements in list2
    cout << endl;
    cout << "List 2:";
    list2.print();
    
    
    // check if 0 is an element of list2
    cout << endl;
    if (list2.isElement(0))
        cout << "'0' is an element in List 2";
    cout << endl;
    
    
    // pop out the first element in a queue of list2
    cout << endl;
    cout << "we pop out: " << list2.pop() << " from List 2" << endl;
    cout << endl;
    
    // print all the elements in list2
    cout << "List 2:";
    list2.print();
    cout << endl;
    
    // print all the elements in list1
    cout << "List 1:";
    list1.print();
    
    FIFO list3(list2);      // initialize a third FIFO "list3" and copy all the data from list2 to list3
    
    // print all the elements in list3
    cout << endl;
    cout << "List 3:";
    list3.print();
    
    // clear all the data in list3
    list3.empty();
    
    // print all the elements in list3
    cout << endl;
    cout << "List 3:";
    list3.print();
    cout << endl;
    
    return 0;
}

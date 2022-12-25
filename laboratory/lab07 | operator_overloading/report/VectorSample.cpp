//
//  main.cpp
//  lab07
//
//  Created by Khongmeng Kormoua on 2021. 03. 30..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "Vector.h"

using namespace std;
int main()
{
    Vector v1;

    // Testing 'insert' class method
    for(int i=1;i<10;i++)
    {
        v1.insert(i,i);
    }

    // Testing 'operator<<'
    cout<<v1<<endl;
    // Correct result:
    // 0 1 2 3 4 5 6 7 8 9

    // Testing copy constructor
    Vector v2(v1); // Same: Vector v2=v1;
    // Testing operator=
    Vector v3;
    v3=v2;

    // Modifying v1 (testing 'erase' class method)
    v1.erase(0);
    // v1.erase(9);

    cout<<endl<<v1<<endl<<v2<<endl<<v3<<endl;
    // Correct result:
    // 1 2 3 4 5 6 7 8 9
    // 0 1 2 3 4 5 6 7 8 9
    // 0 1 2 3 4 5 6 7 8 9

    v2.insert(0,-1);
    cout<<v2<<endl;
    // Correct result:
    // -1 0 1 2 3 4 5 6 7 8 9

    v2.insert(10,-1);
    cout<<v2<<endl;
    // Correct result:
    //  -1 0 1 2 3 4 5 6 7 8 -1 9

    v2.insert(12,-1);
    cout<<v2<<endl;
    // Correct result:
    // -1 0 1 2 3 4 5 6 7 8 -1 9 -1

    v2.insert(15,-1);
    cout<<v2<<endl;
    // Correct result:
    // -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -1

    v2[15]=-2;
    cout<<v2<<endl;
    // Correct result:
    // -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -2

    // v2[16]=3;
    
    
    // test sorting method.
    v2.sort();
    cout << endl;
    cout << v2 << endl;
    
    // test the case when we request an element at position which exceed the size of the vector.
    cout << "------------------------------------------" << endl;
    cout << v2.at(20) << endl;
    v2[20] = 100;
    cout << v2 << endl;
    
    // test self-assignment.
    cout << "------------------------------------------" << endl;
    v2 = v2;
    cout << v2 << endl;
    return 0;
}

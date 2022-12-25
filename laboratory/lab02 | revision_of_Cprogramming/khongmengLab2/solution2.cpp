//
//  main.cpp
//  lab02
//
//  Created by Khongmeng Kormoua on 2021. 02. 17..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main(void) {
    
    int num;
    
    // Asking for a size of the array
    printf("Number of element in the array: ");
    scanf("%d", &num);
    
    // allocate a needed space and store an inputs from the user in this space
    double* array = (double*)malloc(sizeof(double) * num);
    if (array == NULL) return EXIT_FAILURE;     //in case we don't get a pointer back, terminate a program
    double* ptr = array;
    for (int i = 0; i < num; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%lf", ptr);
        ptr++;
    }
    
    // print the original array
    ptr = array;
    for (int i = 0; i < num; i++) {
        printf("%.2lf ", *ptr);
        ptr++;
    }
    printf("\n");
    
    // sort the array in ascending order
    qsort(array,num,sizeof(double), compare);
    
    // print the sorted array
    ptr = array;
    for (int i = 0; i < num; i++) {
        printf("%.2lf ", *ptr);
        ptr++;
    }
    printf("\n");
    
    
    // free a allocated memory
    free(array);
    array = NULL;
    ptr = NULL;
    return 0;
 }

int compare(const void* a, const void *b) {

    // Returning value: <0, if a<b;
    //                   0, if a=b;
    //                  >0, if a>b.
    return (*(double*)a - *(double*)b); // here I sepacify a correct data type for 'a' and 'b' e.g (double*)a
                                        // then I dereference a pointer 'a' and 'b' to get a value that they point to
                                        // after that we can get and return a different between a and b directly
}

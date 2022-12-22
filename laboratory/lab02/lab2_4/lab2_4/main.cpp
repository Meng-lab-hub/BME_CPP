//
//  main.cpp
//  lab2_4
//
//  Created by Khongmeng Kormoua on 2021. 02. 17..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void reverse(char*, int);

int main(void) {
    
    int cCounter = 0;       // counting the number of character in the string
    char newChar;           // use to temporary store a new character
    char *str = (char*)malloc(sizeof(char));
    if (str == NULL) return EXIT_FAILURE;     //in case we don't get a pointer back, terminate a program
    str[0] = '\0';
    
    printf("Type your message: ");
    
    // get a string from a user until the user press ENTER
    while (scanf("%c", &newChar) == 1 && newChar != '\n') {
        char *newStr = (char*)malloc(sizeof(char) * (cCounter+1+1));
        if (newStr == NULL) return EXIT_FAILURE;     //in case we don't get a pointer back, terminate a program
        
        // copy the content of the old string to the new string one by one character
        for (int i = 0; i < cCounter; i++)
            newStr[i] = str[i];
        
        // at the end of the new string, add the new character that we read from the user and add the terminate after that
        newStr[cCounter] = newChar;
        newStr[cCounter+1] = '\0';
        
        // free the old string and point it to the new one.
        free(str);
        str = newStr;
        
        // increase the number of a character in the string
        ++cCounter;
    }
    
    // reverse and print a string
    reverse(str, cCounter);
    printf("Reversed message: %s\n", str);
    
    // finally, free the remaining allocated memory that haven't been freed till now.
    free(str);
    return 0;
}

void reverse(char* str, int len) {
    
    // to reverse a string we will create 2 pointers, one is at the begining, one is at the end
    // we will swap the character at those pointers and keep move those pointer to the middle
    
    char* head = str;
    char* tail = str;

    // get the tail pointer to the end of string (before '\0')
    for (int i = 0; i < len - 1; i++)
        tail++;
    
    // swap and move 2 pointers
    char tmp;
    for (int i = 0; i < len/2; i++) {
        tmp = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
    }
}

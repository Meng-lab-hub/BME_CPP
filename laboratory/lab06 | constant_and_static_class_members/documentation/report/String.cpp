//
//  String.cpp
//  lab06
//
//  Created by Khongmeng Kormoua on 2021. 03. 24..
//  Copyright © 2021. Khongmeng Kormoua. All rights reserved.
//

#include "String.h"
using namespace HomeMadeString;

// Default constructor (without arguments):
// set to default form of a string: element = 0; pData = "\0"
String::String () {
    elementNum = 0;
    pData = new char[1];
    pData[0] = '\0';
}

// Copy constructor:
String::String (const String& other) {
    elementNum = other.elementNum;              // set a number of character in this string equal to other string
    pData = new char[elementNum + 1];           // allocate a necessary space for the whole string (+1 is for a terminating character)
    
    for (int i = 0; i < elementNum; i++)        // travel through the whole string of other
        pData[i] = other.pData[i];                  // in each step of travelling, copy that element to this string
    pData[elementNum] = '\0';                   // At the end of this string which copied from other string, add terminating character '\0'
}

// Conversion constructor that expects a char* with '\0' at the end
// This constructor is responsible for the conversion char*-> String
String::String (const char* str) {
    const char* ptr = str;                                    // set one pointer which will be used to check and travel through the string str
    elementNum = 0;                                     // first set the the number of character in this string equal to 0
    pData = new char[1];                                // allocate a string with a space of 1 character for terminating character '\0'
    pData[0] = '\0';                                    // add terminating character to this string

    while (*ptr != '\0') {                              // travel through the str string untill reach the terminating character
                                                        /* we will copy the new element from str to this string, one by one character
                                                           as long as we don't reach the terminating character */
        if (elementNum > 0)                             // so first when we find a new element that is need to be copied we will delete this string
            delete [] pData;                            // delete this string in case there is only 1 space is allocated "terminating character"
        else
            delete pData;                               // delete this string in case there is multiple characters in the allocated memory
        
        pData = new char[elementNum + 1 + 1];           // allocate a new space with that is ready to take all the old string and the new character
        for (int i = 0; i < elementNum + 1; i++)        // travel through the string str
            pData[i] = str[i];                          // copy character one by one from str string to this string
        elementNum++;                                   // after added a new character from str string to this string, increase the number of char in this string
        pData[elementNum] = '\0';                       // at the end of this (new) string, add terminating character '\0'
        ptr++;                                          // after done copying this particular character, go and check the next character in str string.
    }
}

// Constructor with a char (c) and an int parameter (times)
// This constructor creates a string that contains 'times' pieces of the character c
// e.g. if c='$' and times=5 then String="$$$$$"
String::String(char c, int times) {
    pData = new char[times + 1];                        // allocate a memeory space for times element + 1 (terminating character '\0')
    for (int i = 0; i < times; i++)
        pData[i] = c;                                   // add c character to this string times times.
    pData[times] = '\0';                                // at the end of this string, add terminating character '\0'
    elementNum = times;                                 // set the number of character in this stirng equal to times
}

// Destructor:
String::~String () {
    if (elementNum > 0)             // if this string has more than 1 space allocated, delete in this way
        delete [] pData;
    else                            // if this string has only one space allocated (terminating character). delete in this way
        delete pData;
    elementNum = 0;                 // set the number of character equal to 0
}

// Copies the string to the buffer and terminates it with '\0' (string terminating character)
// Memory allocation for the buffer is to be done by a caller
void String::getStr (char * pBuff) const {
    for (int i = 0; i < elementNum + 1; i++)        // travel through the this string, also terminating character
        pBuff[i] = pData[i];                        // copy every element that we travel through to pBuff.
}

// Returns with the string length
int String::getLength() const {
    return elementNum;
}

// Writes the string to the given stream
void String::print (std::ostream& os) const {
    for (unsigned int i = 0; i < elementNum; i++)
        os << pData[i];
}

// Returns with the character at the given position, othewise 0
char String::getChar (int pos) const {
    if (pos < elementNum)           // if there is an element in the position that they ask for
        return pData[pos];          // return this element
    else                            // if there is no element in the position that they ask for
        return 0;                   // return 0
}

// --- Static Class Members. They work with two strings passed as parameters. ---

// Returns with a concatenated string
String String::concatenate (const String& string1, const String& string2) {
    String concatenated;                                                            // allocate a new string which we will return
    concatenated.pData = new char[string1.elementNum + string2.elementNum + 1];     // allocate a necessary space to concatenate the given 2 strings and '\0'
    for (int i = 0; i < string1.elementNum; i++)                                    // first copy string1 to the new string
        concatenated.pData[i] = string1.pData[i];
    
    for (int i = 0; i < string2.elementNum; i++)                                    // copy string2 next to the end of new string
        concatenated.pData[string1.elementNum + i] = string2.pData[i];
    
    concatenated.pData[string1.elementNum + string2.elementNum] = '\0';             // after copy 2 strings add terminating character to at the end
    concatenated.elementNum = string1.elementNum + string2.elementNum;              // set the number of character in this string as the sum of other two
    return concatenated;                                                            // after properly concatenated 2 strings to the new string return it.
}

// Compares two strings
bool String::compare (const String& string1, const String& string2) {
    if (string1.elementNum == string2.elementNum) {                 // first we check if 2 strings have the same number of character or not
        for (int i = 0; i < string1.elementNum; i++)                // travel through 2 strings
            if (string1.pData[i] != string2.pData[i])               // if we found some character of them are different at some position, they are not the same
                return false;
        return true;                                                // after check all elements, if all elements are the same, then they are the same
    }
    return false;                                                   // if the number of character are not the same then they are not the same
}

// Copies string2 to string1
void String::copy (String& string1, const String& string2) {
    
    string1.elementNum = string2.elementNum;                        // set the number of character of string1 = string2
    string1.pData = new char[string1.elementNum + 1];               // allocated a necessary space for string 1 to copy all content of string2

    for (int i = 0; i < string1.elementNum; i++)                    // go through the string2
        string1.pData[i] = string2.pData[i];                        // at each step, copy every character of string2 to string1
    string1.pData[string1.elementNum] = '\0';                       // at the end after copy string2 to string1, add terminating character at the end of strign1
    
    //string1 = string2;
    /*
     I was curious about calling a copy constructor like this, it turned out that the copy procedure worked completely okay
     but I got a runtime error, at the end when a deconstructor is called. It said the memory which will be freed is not allocated.
     */
     
}



// --- convert a static method to a non-static method. ---
/* The implementation of these method below, are exactly the same as the static method above,
   we just need to modify, some parameter
 */

// Returns with a concatenated string
String String::concatenate(const String& other) {
    String concatenated;
    concatenated.pData = new char[elementNum + other.elementNum + 1];
    for (int i = 0; i < elementNum; i++)
        concatenated.pData[i] = pData[i];
    
    for (int i = 0; i < other.elementNum; i++)
        concatenated.pData[elementNum + i] = other.pData[i];
    
    concatenated.pData[elementNum + other.elementNum] = '\0';
    concatenated.elementNum = elementNum + other.elementNum;
    return concatenated;
}

// Compares a given string to this string
bool String::compare(const String& other) {
    if (elementNum == other.elementNum) {
        for (int i = 0; i < elementNum; i++)
            if (pData[i] != other.pData[i])
                return false;
        return true;
    }
    return false;
}

// Copies other string to this string
void String::copy(const String& other) {
    elementNum = other.elementNum;
    pData = new char[elementNum + 1];
    
    for (int i = 0; i < elementNum; i++)
        pData[i] = other.pData[i];
    pData[elementNum] = '\0';
}

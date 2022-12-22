#include "String.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace TheUltimateString
{
        String::String()
        {
            pData=NULL;
            elementsNum=0;
        }

        String::String(const String& string)
        {
            pData=NULL;
            copy(*this,string);
        }

        
        String::String(const char c, unsigned int times)
        {
            elementsNum=times;

            if(elementsNum==0)
            {
                pData=NULL;
                return;
            }

            pData=new char[elementsNum+1];
            for(unsigned int i=0;i<elementsNum;i++)
            {
                pData[i]=c;
            }
            pData[elementsNum]='\0';
        }


        void String::print(ostream& os)
        {
            for(unsigned int i=0;i<elementsNum;i++)
            {
                os<<pData[i];
            }
        }

        String String::concatenate(const String & string1, const String & string2)
        {
            String s;
            s.elementsNum=string1.elementsNum+string2.elementsNum;

            if(s.elementsNum==0)
            {
                s.pData=NULL;
                return s;
            }

            s.pData=new char[s.elementsNum+1];

            for(unsigned int i=0;i<string1.elementsNum;i++)
            {
                s.pData[i]=string1.pData[i];
            }
            for(unsigned int j=string1.elementsNum;j<s.elementsNum;j++)
            {
                s.pData[j]=string2.pData[j-string1.elementsNum];
            }

            s.pData[s.elementsNum]='\0';
            return s;
        }

        bool String::compare(const String & string1, const String & string2)
        {
            if(string1.elementsNum!=string2.elementsNum)return false;

            for(unsigned int i=0;i<string1.elementsNum;i++)
            {
                if(string1.pData[i]!=string2.pData[i]) return false;
            }
            return true;
        }

        void String::copy(String &string1, const String &string2)
        {
            delete string1.pData;
            string1.elementsNum=string2.elementsNum;
            if(string1.elementsNum==0)
            {
                string1.pData=NULL;
                return;
            }
            string1.pData=new char[string1.elementsNum+1];
            for(unsigned int i=0;i<string1.elementsNum;i++)
            {
                string1.pData[i]=string2.pData[i];
            }
            string1.pData[string1.elementsNum]='\0';
        }

        // My implementation:

        // Conversion constructor that expects a char* with '\0' at the end
        // This constructor is responsible for the conversion char*-> String
        String::String(const char* str) {
            const char* ptr = str;                                    // set one pointer which will be used to check and travel through the string str
            elementsNum = 0;                                     // first set the the number of character in this string equal to 0
            pData = new char[1];                                // allocate a string with a space of 1 character for terminating character '\0'
            pData[0] = '\0';                                    // add terminating character to this string

            while (*ptr != '\0') {                              // travel through the str string untill reach the terminating character
                                                                    /* we will copy the new element from str to this string, one by one character
                                                                       as long as we don't reach the terminating character */
                if (elementsNum > 0)                             // so first when we find a new element that is need to be copied we will delete this string
                    delete [] pData;                            // delete this string in case there is only 1 space is allocated "terminating character"
                else
                    delete pData;                               // delete this string in case there is multiple characters in the allocated memory
                    
                pData = new char[elementsNum + 1 + 1];           // allocate a new space with that is ready to take all the old string and the new character
                for (int i = 0; i < elementsNum + 1; i++)        // travel through the string str
                    pData[i] = str[i];                          // copy character one by one from str string to this string
                elementsNum++;                                   // after added a new character from str string to this string, increase the number of char in this string
                pData[elementsNum] = '\0';                       // at the end of this (new) string, add terminating character '\0'
                ptr++;                                          // after done copying this particular character, go and check the next character in str string.
            }
        }


    // Returns with the character at the given position, otherwise 0
        char& String::operator[](unsigned int pos) {
                
            if (pos >= elementsNum || pos < 0) {                // if the given position is out of range
                throw 0;                                        // throw 0
            } else {                                            // if the given position is valid
                return pData[pos];                              // return the element corresponding to the given position
            }
        }
        // Returns with the constant character at the given position
        const char& String::operator[](unsigned int pos) const {
            if (pos >= elementsNum || pos < 0) {                // if the given position is out of range
                throw 0;                                        // throw 0
            } else {                                            // if the given position is valid
                return pData[pos];                              // return the element corresponding to the given position
            }
        }

        // Overloaded operators

// operator overloading for +
        String String::operator+(const String& theOther)const {
            return concatenate(*this, theOther);           // we concatenate this and theOther strings and return it
        }

// operator overloading for +=
        const String& String::operator+=(const String &theOther) {
            
            String* s = new String;                                     // create a new string
            copy(*s, concatenate(*this, theOther));                     // we concatenate this and theOther strings then copy them to s
            copy(*this, *s);                                            // make this string equal to the new created string
            delete s;
            return *this;                                               // return this new created string
        }

// operator overloading for =
        const String& String::operator=(const String& theOther) {
            
            copy(*this, theOther);      // copy theOther string to this string
            return *this;               // and return this string
        }

// operator overloading for ==
        bool String::operator==(const String& theOther) const {
            
            if (compare(*this, theOther) == true) {             // compare this string with theOther string
                return true;                                    // if they are the same return true
            } else {                                            // if they are not the same
                return false;                                   // return false
            }
        }

        // Returns with a read-only access to String
        String::operator const char*() const {
            return pData;           // return a pointer points to the first character of the stirng.
        }

}

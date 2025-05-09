/* HEADER FILE FOR STRING CLASS
 * Modified on: (9-5-2024)
 * Contains:Definitions of the class and their friend functions*/

#ifndef STR_HEAD_
#define STR_HEAD_

//The neccesary inbuild headers needed for compilation: 
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

class mystr;
class mystr

{
//pointer to hold dynamically allocated memory:

    char *s;

    public:
//Constructors and Destructors
    mystr();
    mystr(const char *p);
    mystr(mystr &temp);
    ~mystr();

//Overloaded operators
    void operator = (const char *p);
    void operator =(mystr temp);
    mystr operator +(mystr obj);
    char& operator[](int i);
    friend ostream & operator << (ostream &out,mystr temp);
    friend istream & operator >> (istream &in,mystr &temp);

//friend functions for string operations
    friend  mystr& mystrcpy(mystr src,mystr &dest);
    friend  mystr& mystrncpy(mystr src,mystr &dest,int n);
    friend int mystrcmp(mystr s1,mystr s2);
    friend int mystrncmp(mystr s1,mystr s2,int n);
    friend int mystrstr(mystr src,const char *sub);
    friend int mystrlen(mystr &src);
    friend int mystrchr(mystr src,char ch);
    friend void mystrrev(mystr &src);
    friend int mystrrchr(mystr &temp,char ch);
    friend void mystrupper(mystr &src);
    friend void mystrlower(mystr &src);
    friend void mystrtoggle(mystr &src);
    friend mystr& mystrcat(mystr src,mystr &dest);
    friend mystr& mystrncat(mystr src,mystr &dest,int n);

};

#endif

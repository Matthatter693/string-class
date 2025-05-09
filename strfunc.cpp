/*Member functions and operator overloaded function
 *Date of modification:(9-10-2025)
 * */

#include"strhead.h"

/*Constructor and Destructors*/
//default
mystr::mystr()
    {
        s=new char[100];
    }

//parametrized
mystr::mystr(const char *p)
    {
        s=new char[strlen(p)+1];
        strcpy(s,p); 
    }

//paramterized overloaded constructor 
mystr::mystr(mystr &temp)
    {
        s=new char[strlen(temp.s)+1];
        strcpy(s,temp.s);
    }

//destructor
mystr::~mystr()
    {
        delete []s;
    }

//overloaded operators
//'=' operator overloaded two times to accept a string literal and object as an input

void mystr::operator = (const char *p)
    {
        s=new char[strlen(p)+1];
        strcpy(s,p);
    }

void  mystr::operator =(mystr temp){
    delete []s;
    s=new char[strlen(temp.s)+1];
    strcpy(s,temp.s);
}

mystr mystr:: operator +(mystr obj)
    {
        mystr temp =new char[strlen(s)+strlen(obj.s)];
        strcpy(temp.s,s);
        strcat(temp.s,obj.s);
        return temp;
    }

char& mystr::operator[](int i)
{
return s[i];
}

//note: both << & >> can only be overloaded as friend functions
//return type is made of ostream and istream objects so that the operators can be used consecutively
//in a chained manner
ostream & operator<< (ostream &out,mystr temp){
  for(int i=0;i<strlen(temp.s);i++)
    out<<temp.s[i];
  return out;
}


istream & operator >> (istream &in,mystr &temp){
  scanf("%s",temp.s);
  return in;
}



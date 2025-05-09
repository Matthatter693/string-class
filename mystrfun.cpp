/*USER DEFINED STRING FUNCTIONS
 *Modified on:(9-5-2025)
 *Contains definitions for the user defined string functions*/

#include"strhead.h"

/*User defined strcpy and strncpy
 *
 *[mystrcpy]:-
 *  function arguments:(source object,destination object)
 *  return type:object reference
 *
 *[mystrncpy]:-
 *  function arguments:(source object,destination object,no.of elements to be copied)
 *  return type:object reference
 *
 *  USAGE:copies string to destination from source
 *
 * */

mystr& mystrcpy(mystr src,mystr &dest)
{
  int i;
  for(i=0;src[i];i++)
    dest[i]=src[i];
  dest[i]='\0';//adding null-termination
  return dest;
}

mystr& mystrncpy(mystr src,mystr &dest,int n)
{
  int i;
  for(i=0;src[i];i++)
    dest[n+i]=src[i];
  dest[n+i]='\0';
  return dest;
}

/*User defined strcmp and strncmp
 *
 *[mystrcmp]:-
 *  function arguments:(object 1,object 2)
 *  return type:integer(if no difference found returned value is '0'.
 *  Else the numerical difference between the ascii value is returned.)
 *
 *[mystrncpy]:-
 *  function arguments:(object1,object2,no.of elements to compared)*   
 *  return type:integer(if no difference found returned value is '0'.
 *  Else the numerical difference between the ascii value is returned.)
 *
 *  USAGE:compares two string input
 * */

int mystrcmp(mystr s1,mystr s2)
{
  int i;
  for(i=0;s1[i];i++){
    if(s1[i]!=s2[i])
      return s1[i]-s2[i];
  }
  return s1[i]-s2[i];
}

int mystrncmp(mystr s1,mystr s2,int n)
{
  int i;
  for(i=0;s1[n+i];i++){
    if(s1[n+i]!=s2[i])
      return s1[n+i]-s2[i];
  }
  return s1[n+i]-s2[i];
}

/*User defined strlen
 *
 *[mystrlen]:-
 *  function arguments:(object src)
 *  return type:integer(length of the string)
 *  USAGE:gives string length
 *
 * */

int mystrlen(mystr &src)
{
  int i;
  for(i=0;src[i];i++);
  return i;
}


/*User defined string search functions
 * 1)strstr
 * 2)strchr
 * 3)strrchr
 *
 *1)[mystrstr]:-
 *  function arguments:(object 1,substring *p)
 *  return type:integer(index in which string is present)
 *  USAGE:finds and gives the location of the substring
 *
 *2)[mystrchr]:-
 *  function arguments:(object 1,character ch)
 *  return type:integer(index in which char is present)
 *  USAGE:finds and gives the location of the given character
 *
 *3)[mystrrchr]:-
 *  function arguments:(object 1,character ch)
 *  return type:integer(index in which string is present)
 *  USAGE:finds and gives the location of the substring(searches from end of the string)
 *
 * */

int mystrstr(mystr src,const char *sub)
{
  int i,j;
  for(i=0;src[i];i++){
    if(src[i]==sub[0]){
      for(j=1;sub[j];j++){
        if(src[j+i]!=sub[j])
          break;
      }
      if(sub[j]=='\0')
        return i;
    }
  }
  return 0;
}

int mystrchr(mystr src,char ch)
{
  int i;
  for(i=0;src[i];i++){
    if(src[i]==ch)
      return i;
  }
    return 0;
}


int mystrrchr(mystr &temp,char ch){
int i;
for(i=mystrlen(temp);i>=0;i--)
  if(temp[i]==ch)
    return i;
return 0;

}


/*User defined strrev
 *
 *[mystrrev]:-
 *  function arguments:(object refernce src)
 *  return type:void
 *  USAGE:reverses the string object input
 *
 * */

void mystrrev(mystr &src)
{
  char *temp=new char[strlen(src.s)+1];
  strcpy(temp,src.s);
  char *p=temp;
  char *q=temp+strlen(temp)-1;
  char t;
  while(p<q)
  {
    t=*p;
    *p=*q;
    *q=t;
    p++;
    q--;
  }
  strcpy(src.s,temp);
  delete []temp;
}

/*User defined string modification functions
 *
 * 1)mystrupper
 * 2)mystrlower
 * 3)mystrtoggle
 *
 *1)[mystrupper]:-
 *  function arguments:(object reference src)
 *  return type:void
 *  USAGE:toggles lower_case characters to upper_case
 *
 *2)[mystrchr]:-
 *  function arguments:(object reference ch)
 *  return type:void
 *  USAGE:toggles upper_case characters to lower_case
 *
 *3)[mystrtoggle]:-
 *  function arguments:(object reference ch)
 *  return type:void
 *  USAGE:toggles upper_case characters to lower_case,toggles lower_case characters to upper_case
 *
 * */

void mystrupper(mystr &src)
{
  for(int i=0;src[i];i++)
  {
    if(islower(src[i]))
      src[i]=src[i]-32;
  }
}

void mystrlower(mystr &src)
{
  for(int i=0;src[i];i++)
  {
    if(isupper(src[i]))
      src[i]=src[i]+32;
  }
}

void mystrtoggle(mystr &src){
  for(int i=0;src[i];i++)
  {
    if(isupper(src[i]))
    {
      src[i]=src[i]+32;
    }
    else if(islower(src[i]))
    {
      src[i]=src[i]-32;
    }
  }
}


/*User defined strcat and strncat
 *
 *[mystrcat]:-
 *  function arguments:(object source,object destination)
 *  return type:object reference
 *
 *[mystrcat]:-
 *  function arguments:(object1,object2,no.of elements to compared)*   
 *  return type:object reference
 *
 *  USAGE:concatenates two string input
 * */

mystr& mystrcat(mystr src,mystr &dest)
{
  char *temp = new char[mystrlen(src)+mystrlen(dest)+1];
  strcpy(temp,dest.s);
  strcat(temp,src.s);
  printf("%s\n",temp);
  delete []dest.s;
  dest.s=temp;
  return dest;
}

mystr& mystrncat(mystr src,mystr &dest,int n)
{
  char *temp = new char[mystrlen(src)+mystrlen(dest)+1];
  strcpy(temp,dest.s);
  strncat(temp,src.s,n);
  printf("%s\n",temp);
  delete []dest.s;
  dest.s=temp;
  return dest;
}

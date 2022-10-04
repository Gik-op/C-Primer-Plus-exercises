#include "person.h"
#include <string>
#include <cstring>
#include <iostream>

Person::Person(const std::string &ln, const char *fn)
{
    lname=ln;
    strncpy(fname,fn,LIMIT-1);
}

Person::~Person()
=default;

void Person::Show() const
{
    using std::cout;
    if(lname[0]=='\0')
        cout<<"No name!\n";
    else
        cout<<fname<<" "<<lname<<"\n";
}

void Person::FormalShow() const
{
    using std::cout;
    if(lname[0]=='\0')
        cout<<"No name!\n";
    else
        cout<<lname<<","<<fname<<"\n";
}

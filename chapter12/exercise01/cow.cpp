#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
    strcpy(name,"NULL");
    hobby=new char[1];
    hobby[0]='\0';
    weight=0.0;
}

Cow::Cow(const char *nm,const char *ho,double wt)
{
    int len=strlen(ho);
    strncpy(name,nm,19);
    name[19]='\0';
    hobby=new char[len+1];
    strncpy(hobby,ho,len);
    hobby[len]='\0';
    weight=wt;
}

Cow::Cow(const Cow &c)
{
    int len=strlen(c.hobby);
    strcpy(name,c.name);
    hobby=new char[len+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
}

Cow::~Cow()
{
    delete []hobby;
}

Cow & Cow::operator=(const Cow &c)
{
    if(this==&c)
        return *this;
    int len=strlen(c.hobby);
    delete []hobby;
    strcpy(name,c.name);
    hobby=new char[len+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
    return *this;
}

void Cow::showCow() const
{
    std::cout<<"Name: "<<name<<" hobby: "
             <<hobby<<" weight: "<<weight<<std::endl;
}

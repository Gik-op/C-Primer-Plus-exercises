#include <iostream>
#include <cstring>
#include "golf.h"

GOLF::GOLF()
{
    strcpy(fullname,"\0");
    hand=0;
}

GOLF::GOLF(const char *name,int hc)
{
    strncpy(fullname,name,Len-1);
    hand=hc;
}

GOLF::~GOLF()
=default;

int GOLF::setgolf()
{
    int MAX=256,value;
    char name[MAX],input[MAX];
    std::cout<<"Please enter the name:";
    std::cin.getline(name,MAX);
    if(name[0]=='\0')
        return 0;
    std::cout<<"Please enter the handicap:";
    std::cin.getline(input,MAX);
    value=strtol(input,NULL,10);
    *this=GOLF(name,value);
    return 1;
}

void GOLF::handicap(int hc)
{
    hand=hc;
}

void GOLF::showgolf()const
{
    std::cout<<"The name is "<<fullname<<std::endl;
    std::cout<<"The handicap is "<<hand<<std::endl;
}
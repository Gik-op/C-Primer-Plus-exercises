#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf &g,const char *name,int hc)
{
    strncpy(g.fullname,name,Len-1);
    g.handicap=hc;
}

int setgolf(golf &g)
{
    char input[Len];
    std::cout<<"Please enter the name:";
    std::cin.getline(input,Len);
    if(input[0]=='\0')
        return 0;
    else
        strcpy(g.fullname,input);
    std::cout<<"Please enter the handicap:";
    std::cin.getline(input,Len);
    g.handicap=strtol(input,NULL,10);
    return 1;
}

void handicap(golf &g,int hc)
{
    g.handicap=hc;
}

void showgolf(const golf &g)
{
    std::cout<<"The name is "<<g.fullname<<std::endl;
    std::cout<<"The handicap is "<<g.handicap<<std::endl;
}
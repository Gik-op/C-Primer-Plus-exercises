#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg()
{
    strcpy(name,"Plorga");
    CI=50;
}

Plorg::Plorg(char *str, int ci)
{
    strncpy(name,str,size-1);
    CI=ci;
}

Plorg::~Plorg()
=default;

void Plorg::setCI(int ci)
{
    CI=ci;
}

void Plorg::showPlorg()
{
    using std::cout;
    cout<<name<<" "<<CI<<"\n";
}
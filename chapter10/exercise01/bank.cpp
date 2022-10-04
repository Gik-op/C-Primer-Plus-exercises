#include "bank.h"
#include <cstring>
#include <iostream>

Depositor::Depositor()
{
    strcpy(name,"\0");
    strcpy(account,"\0");
    money=0;
}

Depositor::Depositor(char *nam,char *acc,double dep)
{
    strncpy(name,nam,MAX-1);
    strncpy(account,acc,MAX-1);
    money=dep;
}

Depositor::~Depositor()
= default;

void Depositor::showDep() const
{
    using std::cout;
    using std::endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Account: "<<account<<endl;
    cout<<"Deposit: "<<money<<endl;
}

Depositor Depositor::addMoney(double add)
{
    money+=add;
    return *this;
}

Depositor Depositor::cutMoney(double cut)
{
    using std::cout;
    if(cut>money)
    {
        cout<<"More than the deposit!\n";
        cout<<"You can only get "<<money<<"!\n";
    }
    else
        money-=cut;
    return *this;
}

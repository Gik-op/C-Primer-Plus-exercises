#include "wine.h"
#include <iostream>

Wine::Wine()
{
    label = "none";
    years = 0;
    PairArray::first().resize(years);
    PairArray::second().resize(years);
}

Wine::Wine(const char *l, int y)
{
    label = l;
    years = y;
    PairArray::first().resize(years,0);
    PairArray::second().resize(years,0);
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
{
    label = l;
    years = y;
    PairArray::first().resize(years);
    PairArray::second().resize(years);
    for(int i=0;i<years;i++)
    {
        PairArray::first()[i]=yr[i];
        PairArray::second()[i]=bot[i];
    }
}

static int getNum();

void Wine::GetBottles()
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout<<"Enter "<<label<<" data for "<<years<<" year(s):"<<endl;
    for(int i=0;i<years;i++)
    {
        cout<<"Enter year:";
        PairArray::first()[i]=getNum();
        cout<<"Enter bottles for that year:";
        PairArray::second()[i]=getNum();
    }
}

void Wine::Show()
{
    using std::cout;
    using std::endl;
    cout<<"Wine: "<<label<<endl;
    cout<<"\tYear\tBottles"<<endl;
    for(int i=0;i<years;i++)
    {
        cout.width(4);
        cout<<"\t"<<PairArray::first()[i]<<"\t"<<PairArray::second()[i]<<endl;
    }
}

int getNum()
{
    int num;
    using std::cin;
    using std::cout;
    while(!(cin>>num)||num<=0)
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
        cout<<"Wrong input!Again:";
    }
    return num;
}
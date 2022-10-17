#include "wine.h"
#include <iostream>

Wine::Wine()
{
    label = "none";
    years = 0;
    yrs_bots.first().resize(years);
    yrs_bots.second().resize(years);
}

Wine::Wine(const char *l, int y)
{
    label = l;
    years = y;
    yrs_bots.first().resize(years,0);
    yrs_bots.second().resize(years,0);
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
{
    label = l;
    years = y;
    yrs_bots.first().resize(years);
    yrs_bots.second().resize(years);
    for(int i=0;i<years;i++)
    {
        yrs_bots.first()[i]=yr[i];
        yrs_bots.second()[i]=bot[i];
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
        yrs_bots.first()[i]=getNum();
        cout<<"Enter bottles for that year:";
        yrs_bots.second()[i]=getNum();
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
        cout<<"\t"<<yrs_bots.first()[i]<<"\t"<<yrs_bots.second()[i]<<endl;
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
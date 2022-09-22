#include <iostream>

using namespace std;
#define MONTH 12
#define YEARS 3

int main()
{
    const char *month[MONTH]=
            {"Jau","Feb","Mar","Apr","May","Jun",
             "July","Aug","Sep","Oct","Nov","Dec"};
    int bookSale_num[YEARS][MONTH]={0},sumSale[YEARS]={0},Sum=0;
    for(int year=0;year<YEARS;year++)
    {
        for(int index=0;index<MONTH;index++)
        {
            cout<<"Hey,please enter the number of books sold in Year"<<year+1<<" "<<month[index]<<":";
            cin>>bookSale_num[year][index];
            sumSale[year]+=bookSale_num[year][index];
        }
        Sum+=sumSale[year];
    }
    for(int year=0;year<YEARS;year++)
        cout<<"Hey,we've sold "<<sumSale[year]<<" C++ For Fools Year "<<year+1<<".\n";
    cout<<"We sold "<<Sum<<" at all!\n";
    return 0;
}
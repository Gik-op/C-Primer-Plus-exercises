#include <iostream>
#include "name.h"

void SALES::setSales(Sales &s,const double ar[],int n)
{
    double total=0,max,min;
    min=max=ar[0];
    for(int count=0;count<QUARTERS;count++)
    {
        if(count<n)
        {
            s.sales[count]=ar[count];
            total+=s.sales[count];
            max=(max<s.sales[count]?s.sales[count]:max);
            min=(min>s.sales[count]?s.sales[count]:min);
        }
        else
            s.sales[count]=0;
    }
    s.average=total/n;
    s.max=max;
    s.min=min;
}

void SALES::setSales(Sales &s)
{
    using std::cout;
    using std::endl;
    using std::cin;
    double total=0,max=0,min=0,number;
    for(int i=0;i<QUARTERS;i++)
    {
        cout<<"Please enter a number:";
        while(!(cin>>number))
        {
            cin.clear();
            while(cin.get()!='\n')
                continue;
            cout<<"Wrong input!Input again:";
        }
        s.sales[i]=number;
        total+=number;
        if(i==0)
        {
            max=s.sales[i];
            min=s.sales[i];
        }
        max=(max<s.sales[i]?s.sales[i]:max);
        min=(min>s.sales[i]?s.sales[i]:min);
    }
    s.average=total/QUARTERS;
    s.min=min;
    s.max=max;
}

void SALES::showSales(const Sales &s)
{
    using std::cout;
    using std::endl;
    for(int i=0;i<QUARTERS;i++)
        cout<<"sales"<<"#"<<i+1<<":"<<s.sales[i]<<endl;
    cout<<"Average of sales: "<<s.average<<endl;
    cout<<"Max of sales: "<<s.max<<endl;
    cout<<"Min of sales: "<<s.min<<endl;
}

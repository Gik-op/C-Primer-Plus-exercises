#include <iostream>
#include "name.h"

namespace SALES
{
    Sales::Sales(const double ar[],int n)
    {
        double total=0,Max,Min;
        Min= Max=ar[0];
        for(int count=0;count<QUARTERS;count++)
        {
            if(count<n)
            {
                sales[count]=ar[count];
                total+=sales[count];
                Max=(Max < sales[count] ? sales[count] : Max);
                Min=(Min > sales[count] ? sales[count] : Min);
            }
            else
                sales[count]=0;
        }
        average=total/n;
        max=Max;
        min=Min;
    }

    Sales::Sales()
    {
        using std::cout;
        using std::endl;
        using std::cin;
        double total=0,Max=0,Min=0,number;
        cout<<"To create an object, please enter "<<QUARTERS<<" numbers.\n";
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
            sales[i]=number;
            total+=number;
            if(i==0)
            {
                Max=sales[i];
                Min=sales[i];
            }
            Max=(Max < sales[i] ? sales[i] : Max);
            Min=(Min > sales[i] ? sales[i] : Min);
        }
        average=total/QUARTERS;
        max=Max;
        min=Min;//程序走到这里时，已创建出一个类对象，但接下来不会跳出该函数，而是返回第32行
    }

    Sales::~Sales()
    =default;

    void Sales::showSales()const
    {
        using std::cout;
        using std::endl;
        for(int i=0;i<QUARTERS;i++)
            cout<<"sales"<<"#"<<i+1<<":"<<sales[i]<<endl;
        cout<<"Average of sales: "<<average<<endl;
        cout<<"Max of sales: "<<max<<endl;
        cout<<"Min of sales: "<<min<<endl;
    }
}


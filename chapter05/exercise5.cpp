#include <iostream>

using namespace std;
#define MONTH 12

int main()
{
    const char *month[MONTH]=
            {"Jau","Feb","Mar","Apr","May","Jun",
             "July","Aug","Sep","Oct","Nov","Dec"};
    int bookSale_num[MONTH],sumSale=0;
    for(int index=0;index<MONTH;index++)
    {
        cout<<"Hey,please enter the number of books sold in "<<month[index]<<":";
        cin>>bookSale_num[index];
        sumSale+=bookSale_num[index];
    }
    cout<<"Hey,we've sold "<<sumSale<<" C++ For Fools this year!"<<endl;
    return 0;
}

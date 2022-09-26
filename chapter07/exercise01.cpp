#include <iostream>

using namespace std;

int main()
{
    double num1,num2,aver;
    cout<<"Please enter two numbers:";
    cin>>num1>>num2;
    while(num1!=0&&num2!=0)
    {
        aver=2.0*num1*num2/(num1+num2);
        cout<<"The harmonic average between "<<num1<<" and "
            <<num2<<" is "<<aver<<".\n";
        cout<<"Enter another two(0 to quit):";
        cin>>num1;
        if(num1!=0)
            cin>>num2;
    }
    cout<<"Done.\n";
    return 0;
}

#include <iostream>

using namespace std;

double add(double x,double y);
double mix(double x,double y);
double min(double x,double y);
double calculate(double x,double y,double (*ptr)(double,double));

int main()
{
    double num1,num2;
    double (*pf[3])(double,double)={add,mix,min};
    while(1)
    {
        cout<<"Please enter two numbers(0 0 to quit):";
        while (!(cin>>num1>>num2))
        {
            cin.clear();
            while (cin.get()!='\n')
                continue;
            cout<<"please Enter two numbers:";
        }
        if(num1==0&&num2==0)
            break;
        for(int i=0;i<3;i++)
            cout<<"The result for function "<<i+1<<" is "<<calculate(num1,num2,pf[i])<<endl;
    }
    cout<<"Done!"<<endl;
    return 0;
}

double calculate(double x,double y,double (*ptr)(double,double))
{
    return ptr(x,y);
}

double add(double x,double y)
{
    return x+y;
}
double mix(double x,double y)
{
    return x*y;
}
double min(double x,double y)
{
    return x>y?y:x;
}


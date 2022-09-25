#include <iostream>

using namespace std;

#define rate1 0.1
#define rate2 0.15
#define rate3 0.2

#define base1w5 1000
#define base3w5 4000

int main()
{
    double tax;
    unsigned int salary=0;
    do{
        if(salary)
        {
            if(salary<5000)
                tax=0;
            else if(salary<15000)
                tax=(salary-5000)*rate1;
            else if(salary<35000)
                tax=base1w5+(salary-15000)*rate2;
            else
                tax=base3w5+(salary-35000)*rate3;
            cout<<"Your tax is "<<tax<<" tvarps.\n";
        }
        cout<<"Please enter your salary(input a negative or non-numeric number to quit):";
    }while(cin>>salary);
    cout<<"Bye!"<<endl;
    return 0;
}

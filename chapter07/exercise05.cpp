#include <iostream>

using namespace std;

long long Factor(int num);

int main()
{
    int number;
    cout<<"Please enter a number that you want to calculate:";
    while(cin>>number&&number>=0)
    {
        cout<<number<<"! = "<<Factor(number)<<endl;
        cout<<"Next number (a negative number to stop):";
    }
    cout<<"Bye.\n";
    return 0;
}

long long Factor(int num)
{
    if(num>1)
        return num*Factor(num-1);
    else
        return 1;
}

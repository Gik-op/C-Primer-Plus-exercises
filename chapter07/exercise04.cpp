#include <iostream>

long double probability(unsigned numbers,unsigned picks);

int main()
{
    using namespace std;
    double first,second,pick1,pick2;
    cout<<"Enter the first number of choices on the game card and\n"
          "the number of picks allowed:\n";
    while((cin>>first>>pick1)&&pick1<=first)
    {
        cout<<"Enter the second number of choices on the game card and\n"
              "the number of picks allowed:\n";
        if((cin>>second>>pick2)&&pick2<=second)
        {
            cout<<"You have one chance in ";
            cout<<probability(first,pick1)*probability(second,pick2);
            cout<<" of winning.\n";
        }
        else
            break;
        cout<<"Next two numbers (q to quit):";
    }
    cout<<"Bye.\n";
    return 0;
}

long double probability(unsigned numbers,unsigned picks)
{
    long double result=1.0;
    long double n;
    unsigned p;
    for(n=numbers,p=picks;p>0;n--,p--)
        result=result*n/p;
    return result;
}



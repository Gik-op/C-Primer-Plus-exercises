#include <iostream>
#include "plorg.h"

#define MAX 256

int main()
{
    using namespace std;
    Plorg item1;
    int number;
    char input[MAX],num[MAX];
    cout<<"An example for plorg:";
    item1.showPlorg();
    cout<<"Please input a name for plorg:";
    cin.getline(input,MAX);
    cout<<"Please enter a number for CI:";
    cin.getline(num,MAX);
    number=strtol(num,NULL,10);
    Plorg item2(input,number);
    while(true)
    {
        cout<<"Your plorg:";
        item2.showPlorg();
        cout<<"Please enter a number to change CI(q to quit):";
        cin.getline(num,MAX);
        number=strtol(num,NULL,10);
        if(number==0)
            break;
        item2.setCI(number);
        item2.showPlorg();
    }
    cout<<"Bye.\n";
    return 0;
}

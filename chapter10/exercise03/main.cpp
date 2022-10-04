#include <iostream>
#include "golf.h"

const int MEM=8;
const int MAX=256;

int main()
{
    using namespace std;
    GOLF group[MEM];
    int count=0,come,value;
    while(count<MEM)
    {
        char input[MAX];
        come=group[count].setgolf();
        if(come==0)
            break;
        cout<<"If you want to change the handicap,please enter the new value(0 to go on):";
        cin.getline(input,MAX);
        value=strtol(input,NULL,10);
        if(value)
            group[count].handicap(value);
        count++;
    }
    if(count==0)
    {
        group[0]=GOLF("Ann Birdfree",24);
        count++;
    }
    for(int i=0;i<count;i++)
        group[i].showgolf();
    cout<<"Bye."<<endl;
    return 0;
}
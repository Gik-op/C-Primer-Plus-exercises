#include <iostream>
#include "golf.h"

const int MEM=8;
const int MAX=256;

int main()
{
    using namespace std;
    golf group[MEM];
    int count=0,come,value;
    while(count<MEM)
    {
        char input[MAX];
        come=setgolf(group[count]);
        if(come==0)
            break;
        cout<<"If you want to change the handicap,please enter the new value(0 to go on):";
        cin.getline(input,Len);
        value=strtol(input,NULL,10);
        if(value)
            handicap(group[count],value);
        count++;
    }
    if(count==0)
    {
        setgolf(group[0],"Ann Birdfree",24);
        count++;
    }
    for(int i=0;i<count;i++)
        showgolf(group[i]);
    cout<<"Bye."<<endl;
    return 0;
}

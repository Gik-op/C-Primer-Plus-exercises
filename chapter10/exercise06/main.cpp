#include <iostream>
#include "move.h"

#define MAX 256

int main()
{
    using namespace std;
    Move pos,step;
    double x,y;
    char input[MAX],*ptr;
    cout<<"Your position is:";
    pos.showMove();
    while(true)
    {
        cout<<"Please enter your move(x y):";
        cin.getline(input,MAX);
        x=strtod(input,&ptr);
        y=strtod(ptr,NULL);
        if(x==0&&y==0)
            break;
        step.reset(x,y);
        cout<<"Your move is:";
        step.showMove();
        pos=pos.add(step);
        cout<<"Now your position is:";
        pos.showMove();
    }

    cout<<"Bye.\n";
    return 0;
}

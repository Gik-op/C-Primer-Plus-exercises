#include <iostream>
#include "person.h"

int main()
{
    using namespace std;
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy","Sam");
    Person aim[3]={one,two,three};
    for(int i=0;i<3;i++)
    {
        aim[i].Show();
        cout<<endl;
        aim[i].FormalShow();
        cout<<endl;
    }
    return 0;
}

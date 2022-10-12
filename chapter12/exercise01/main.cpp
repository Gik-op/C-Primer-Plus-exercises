#include <iostream>
#include "cow.h"

#define MAX 256

void show(Cow &c1,Cow &c2)
{
    std::cout<<"Cow #1:\n";
    c1.showCow();
    std::cout<<"Cow #2:\n";
    c2.showCow();
}
void change(Cow &c1,Cow &c2)
{
    Cow temp;
    temp=c1;
    c1=c2;
    c2=temp;
}

int main()
{
    using namespace std;
    char name[MAX],hobby[MAX];
    double wt;
    Cow one("Cow","Eating",234);
    cout<<"Hello, please enter a name for the cow:";
    cin.getline(name,MAX);
    cout<<"Please enter the hobby:";
    cin.getline(hobby,MAX);
    cout<<"Please enter the weight:";
    cin>>wt;
    Cow two(name,hobby,wt);
    show(one,two);
    change(one,two);
    show(one,two);
    return 0;
}

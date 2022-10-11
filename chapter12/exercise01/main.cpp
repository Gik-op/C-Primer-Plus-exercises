#include <iostream>
#include "cow.h"

#define MAX 256

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
    cout<<"Cow #1:";
    one.showCow();
    cout<<"Cow #2:";
    two.showCow();
    two=one;
    cout<<"Cow #1:";
    one.showCow();
    cout<<"Cow #2:";
    two.showCow();

    return 0;
}

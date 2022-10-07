#include <iostream>
#include "list.h"

#define MAX 256

void show(Item &one);

int main()
{
    using namespace std;
    char input[MAX];
    List list;
    Item num;
    while(!(list.isfull()))
    {
        cout<<"Please enter a number to add to the list(q to quit):";
        cin.getline(input,MAX);
        num=strtol(input,NULL,10);
        while((!(isdigit(input[0])))&&input[0]!='q')
        {
            cout<<"Wrong input!Input again(eg.245,16 or q to quit):";
            cin.getline(input,MAX);
            num=strtol(input,NULL,10);
        }
        if(input[0]=='q')
            break;
        list.addItem(num);
    }
    cout<<"Here are the list.\n";
    if(list.isempty())
        cout<<"The list is empty.\n";
    else
        list.visit(show);
    cout<<"Bye.\n";
    return 0;
}

void show(Item &one)
{
    std::cout<<one<<std::endl;
}

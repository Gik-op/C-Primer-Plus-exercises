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
        num=strtol(input,NULL,10);//存在负数的数值溢出问题
        if(num<=0&&!(isdigit(input[0])))//考虑增加鲁棒性验证
            break;
        list.addItem(num);
    }
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

#include <iostream>
#include "stack.h"

Stack::Stack(int n)
{
    top=-1;
    size=n;
    pitems=new Item[size];
}

Stack::Stack(const Stack &st)
{
    top=st.top;
    size=st.size;
    pitems=new Item[size];
    for(int i=0;i<=top;i++)
        pitems[i]=st.pitems[i];
}

Stack::~Stack()
{
    delete []pitems;
}

bool Stack::isempty() const
{
    return top==-1;
}

bool Stack::isfull() const
{
    return top==(size-1);
}

bool Stack::push(const Item &item)
{
    bool add=true;

    if(top<size-1)
    {
        top++;
        pitems[top]=item;
    }
    else
    {
        std::cout<<"The stack is full!\n";
        add=false;
    }
    return add;
}

bool Stack::pop(Item &item)
{
    bool dele=true;
    if(top>-1)
    {
        item=pitems[top];
        top--;
    }
    else
    {
        std::cout<<"The stack is empty!\n";
        dele=false;
    }
    return dele;
}

Stack & Stack::operator=(const Stack &st)
{
    if(this==&st)
        return *this;
    top=st.top;
    size=st.size;
    delete []pitems;
    pitems=new Item[size];
    for(int i=0;i<=top;i++)
        pitems[i]=st.pitems[i];
    return *this;
}
#include <iostream>
#include "list.h"

List::List()
{
    mem_num=0;
}

List::~List()
=default;

void List::addItem(Item one)
{
    if(isfull())
        std::cout<<"The list is full!Can't add items.\n";
    else
    {
        item[mem_num]=one;
        mem_num++;
    }
}

bool List::isempty() const
{
    if(mem_num==0)
        return true;
    else
        return false;
}

bool List::isfull() const
{
    if(mem_num==size)
        return true;
    else
        return false;
}

void List::visit(void (*pf)(Item &))
{
    for(int i=0;i<mem_num;i++)
        pf(item[i]);
}
#ifndef EXERCISE08_LIST_H
#define EXERCISE08_LIST_H

typedef unsigned long Item;

class List
{
private:
    enum {size=14};
    Item item[size];
    int mem_num;
public:
    List();
    ~List();
    void addItem(Item);
    bool isempty()const;
    bool isfull()const;
    void visit(void (*pf)(Item &));
};

#endif //EXERCISE08_LIST_H

#ifndef EXERCISE04_STACK_H
#define EXERCISE04_STACK_H

typedef unsigned long Item;

class Stack
{
private:
    enum{MAX=10};
    Item *pitems;
    int size;
    int top;
public:
    Stack(int n=MAX);
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    Stack & operator=(const Stack &st);
};

#endif //EXERCISE04_STACK_H

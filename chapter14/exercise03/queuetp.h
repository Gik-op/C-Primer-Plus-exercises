#ifndef EXERCISE03_QUEUETP_H
#define EXERCISE03_QUEUETP_H

template <typename Item>
class Queue
{
private:
// class scope definitions
    // Node is a nested structure definition local to this class
    struct Node { Item item; struct Node * next;};
    enum {Q_SIZE = 10};
// private class members
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q) : qsize(0) { }
    Queue & operator=(const Queue & q) { return *this;}
public:
    explicit Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};

template <typename Item>
Queue<Item>::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <typename Item>
Queue<Item>::~Queue()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename Item>
bool Queue<Item>::isempty() const
{
    return items == 0;
}

template <typename Item>
bool Queue<Item>::isfull() const
{
    return items == qsize;
}

template <typename Item>
int Queue<Item>::queuecount() const
{
    return items;
}

template <typename Item>
bool Queue<Item>::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <typename Item>
bool Queue<Item>::dequeue(Item & item)
{
    if (front == nullptr)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return true;
}

#endif //EXERCISE03_QUEUETP_H

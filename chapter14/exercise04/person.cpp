#include "person.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// Person functions
Person::Person()
{
    first = "none";
    last = "none";
}

Person::Person(char *f, char *l)
{
    first = f;
    last = l;
}

void Person::Data() const
{
    using std::cout;
    using std::endl;
    cout<<"Name: "<<first<<" , "<<last<<endl;
}

void Person::Get()
{
    using std::cout;
    using std::endl;
    using std::cin;
    cout<<"Enter the first name:";
    getline(cin,first);
    cout<<"Enter the last name:";
    getline(cin,last);
}

void Person::Show()
{
    Data();
}

void Person::Set()
{
    Get();
}

// Gunslinger functions

void Gunslinger::Data() const
{
    using std::cout;
    using std::endl;
    cout<<"The draw time: "<<time<<endl;
    cout<<"The nick number: "<<number<<endl;
}

template <typename T> void getNum(T &t);

void Gunslinger::Get()
{
    using std::cout;
    using std::cin;
    cout<<"Enter the draw time:";
    getNum(time);
    cout<<"Enter the nick number:";
    getNum(number);
}

void Gunslinger::Show()
{
    std::cout<<"Category: Gunslinger:"<<std::endl;
    Person::Data();
    Data();
}

void Gunslinger::Set()
{
    Person::Get();
    Gunslinger::Get();
}

// PokerPlayer functions

int PokerPlayer::Draw()
{
    srand(time(0));
    return rand()%52+1;
}

void PokerPlayer::Data() const
{
    using std::cout;
    using std::endl;
    cout<<"The card: "<<Draw()<<endl;
}

void PokerPlayer::Show()
{
    std::cout<<"Category: PokerPlayer"<<std::endl;
    Person::Data();
    Data();
}

void PokerPlayer::Set()
{
    Person::Get();
}

// BadDude functions

void BadDude::Data() const
{
    Gunslinger::Data();
    PokerPlayer::Data();
}

void BadDude::Get()
{
    Gunslinger::Get();
}

void BadDude::Show()
{
    std::cout<<"Category: BadDude"<<std::endl;
    Person::Data();
    Data();
}

void BadDude::Set()
{
    Person::Get();
    Get();
}

// static functions

template <typename T>
void getNum(T &t)
{
    T num;
    using std::cin;
    using std::cout;
    while(!(cin>>num)||num<=0)
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
        cout<<"Wrong input!Again:";
    }
    t = num;
}
#ifndef EXERCISE04_PERSON_H
#define EXERCISE04_PERSON_H

#include <string>

using std::string;

class Person
{
private:
    string first;
    string last;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Person();
    Person(char *f,char *l);
    ~Person() = default;
    virtual void Show()=0;
    virtual void Set()=0;
};

class Gunslinger : virtual public Person
{
private:
    double time;
    int number;
protected:
    void Data() const;
    void Get();
public:
    Gunslinger() : Person() { time=0;number=0; }
    Gunslinger(char *f,char *l,double t,int n) : Person(f,l) { time=t;number=n; }
    ~Gunslinger() = default;
    double Draw() const { return time; }
    virtual void Show();
    virtual void Set();
};

class PokerPlayer : virtual public Person
{
protected:
    void Data() const;
public:
    PokerPlayer() : Person() {}
    PokerPlayer(char *f,char *l) : Person(f,l) {}
    static int Draw() ;
    virtual void Show();
    virtual void Set();
};

class BadDude : public Gunslinger,public PokerPlayer
{
protected:
    void Data() const;
    void Get();
public:
    BadDude() : Person(),Gunslinger(),PokerPlayer() {}
    BadDude(char *f,char *l,double t,int n) : Person(f,l),Gunslinger(f,l,t,n) {}
    ~BadDude() = default;
    double Gdraw() { return Gunslinger::Draw(); }
    static int Cdraw() { return PokerPlayer::Draw(); }
    virtual void Show();
    virtual void Set();
};

#endif //EXERCISE04_PERSON_H

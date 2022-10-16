#include "port.h"  // include <iostream>
#include <cstring>

// Port functions

Port::Port(const char *br, const char *st, int b)
{
    int len = strlen(br);
    brand = new char[len+1];
    strcpy(brand,br);
    strncpy(style,st,19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port &p)
{
    int len = strlen(p.brand);
    brand = new char[len+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if(this==&p)
        return *this;
    delete []brand;
    int len = strlen(p.brand);
    brand = new char[len+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout<<"Brand: "<<brand<<endl;
    cout<<"Kind: "<<style<<endl;
    cout<<"Bottles: "<<bottles<<endl;
}

ostream & operator<<(ostream & os,const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles <<endl;
    return os;
}

// Vintageport functions

VintagePort::VintagePort()
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br, const char *st, int b, const char *nn, int y) : Port(br,st,b)
{
    int len = strlen(br);
    nickname = new char[len+1];
    strcpy(nickname,nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    int len = strlen(vp.nickname);
    nickname = new char[len+1];
    strcpy(nickname,vp.nickname);
    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if(this==&vp)
        return *this;
    Port::operator=(vp);
    delete []nickname;
    int len = strlen(vp.nickname);
    nickname = new char[len+1];
    strcpy(nickname,vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout<<"Nickname: "<<nickname<<endl;
    cout<<"Year: "<<year<<endl;
}

ostream & operator<<(ostream & os,const VintagePort &vp)
{
    os << (const Port &)vp;
    os << vp.nickname << ", " << vp.year << endl;
    return os;
}
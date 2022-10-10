#include <iostream>
#include "complex0.h"

complex::complex()
{
    real=imag=0.0;
}

complex::complex(double r, double i)
{
    real=r;
    imag=i;
}

complex::~complex()
=default;

complex complex::operator+(const complex &c) const
{
    complex one(real+c.real,imag+c.imag);
    return one;
}

complex complex::operator-(const complex &c) const
{
    complex one(real-c.real,imag-c.imag);
    return one;
}

complex complex::operator*(const complex &c) const
{
    complex one(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
    return one;
}

complex complex::operator*(double m) const
{
    complex one(m*real,m*imag);
    return one;
}

complex operator~(const complex &c)
{
    complex one(c.real,-c.imag);
    return one;
}

std::ostream & operator<<(std::ostream &os,const complex &c)
{
    os<<"("<<c.real<<","<<c.imag<<"i)";
    return os;
}

std::istream & operator>>(std::istream &is,complex &c)
{
    std::cout<<"real: ";
    if(!(is>>c.real))
        return is;
    std::cout<<"imaginary: ";
    is>>c.imag;
    return is;
}
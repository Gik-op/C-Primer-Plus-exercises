#include <iostream>
#include "move.h"

using std::cout;
using std::endl;

Move::Move(double a,double b)
{
    x=a;
    y=b;
}

Move::~Move()
=default;

void Move::showMove() const
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}
Move Move::add(const Move &m) const
{
    return Move(x+m.x,y+m.y);
}

void Move::reset(double a,double b)
{
    x=a;
    y=b;
}

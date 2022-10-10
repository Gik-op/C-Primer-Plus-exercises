#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    state=0;
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    state=1;
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    state=0;
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
=default;

// set the state
void Stonewt::set_state(int st)
{
    if(st==0||st==1)
        state=st;
    else
        std::cout<<"Wrong state!\n";
}

// compare--my god I'm so clever that I only use two function definitions
bool Stonewt::operator<(const Stonewt &stn) const
{
    if(pounds<stn.pounds)
        return true;
    else
        return false;
}

bool Stonewt::operator==(const Stonewt &stn) const
{
    if(pounds==stn.pounds)
        return true;
    else
        return false;
}

// calculation
Stonewt Stonewt::operator+(const Stonewt &stn) const
{
    Stonewt one(pounds+stn.pounds);
    return one;
}

Stonewt Stonewt::operator-(const Stonewt &stn) const
{
    Stonewt one(pounds-stn.pounds);
    return one;
}

Stonewt Stonewt::operator*(double m) const
{
    Stonewt one(m*pounds);
    return one;
}

// show weight
std::ostream & operator<<(std::ostream &os,const Stonewt &stn)
{
    if(stn.state==0)
        os << stn.pounds << " pounds";
    else
        os << stn.stone << " stone, " << stn.pds_left << " pounds";
    return os;
}
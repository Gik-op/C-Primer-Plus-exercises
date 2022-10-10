#ifndef EXERCISE06_STONEWT_H
#define EXERCISE06_STONEWT_H

#include <iosfwd>

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
    int state;                    // 0 for double pounds, 1 for stone,lbs
public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void set_state(int st);
    bool operator<(const Stonewt &stn) const;
    bool operator>(const Stonewt &stn) const
    {return !((*this)<stn)&&!((*this)==stn);}
    bool operator==(const Stonewt &stn) const;
    bool operator!=(const Stonewt &stn) const
    {return !((*this)==stn);}
    bool operator<=(const Stonewt &stn) const
    {return !((*this)>stn);}
    bool operator>=(const Stonewt &stn) const
    {return !((*this)<stn);}
    Stonewt operator+(const Stonewt &stn) const;
    Stonewt operator-(const Stonewt &stn) const;
    Stonewt operator*(double m) const;
    friend Stonewt operator*(double m,const Stonewt &stn)
    {return stn*m; }
    friend std::ostream & operator<<(std::ostream &os,const Stonewt &stn);   // show weight
};

#endif //EXERCISE06_STONEWT_H

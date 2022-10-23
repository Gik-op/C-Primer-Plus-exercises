#ifndef EXERCISE03_EXC_MEAN_H
#define EXERCISE03_EXC_MEAN_H

#include <iostream>
#include <stdexcept>

class bad : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    explicit bad(double val1,double val2,const char *s): std::logic_error(s) { v1=val1;v2=val2;}
};

class bad_hmean : public bad
{
public:
    explicit bad_hmean(double val1,double val2,const char *s="hmean(): invalid arguments: a = -b\n"): bad(val1,val2,s) {}
};


class bad_gmean : public bad
{
public:
    explicit bad_gmean(double val1,double val2,const char *s="gmean(): arguments should be >= 0\n"): bad(val1,val2,s) {}
};


#endif //EXERCISE03_EXC_MEAN_H

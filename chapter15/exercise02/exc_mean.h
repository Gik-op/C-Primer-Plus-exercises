#ifndef EXERCISE02_EXC_MEAN_H
#define EXERCISE02_EXC_MEAN_H

#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
    explicit bad_hmean(const char *s="hmean(): invalid arguments: a = -b\n"): std::logic_error(s) {}
};


class bad_gmean : public std::logic_error
{
public:
    explicit bad_gmean(const char *s="gmean(): arguments should be >= 0\n"): std::logic_error(s) {}
};

#endif //EXERCISE02_EXC_MEAN_H

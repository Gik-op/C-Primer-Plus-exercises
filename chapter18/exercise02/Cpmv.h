#ifndef EXERCISE02_CPMV_H
#define EXERCISE02_CPMV_H

#include <string>

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };
private:
    Info *pi;
public:
    Cpmv();
    Cpmv(std::string q,std::string z);
    Cpmv(const Cpmv &cp);
    Cpmv(Cpmv && mv) noexcept ;
    ~Cpmv() { delete pi;}
    Cpmv & operator=(const Cpmv &cp);
    Cpmv & operator=(Cpmv && mv) noexcept ;
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
};

#endif //EXERCISE02_CPMV_H

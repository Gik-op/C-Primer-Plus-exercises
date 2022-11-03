#include "Cpmv.h"
#include <iostream>
#include <utility>

Cpmv::Cpmv()
{
    pi = new Info;
    pi->qcode = "none";
    pi->zcode = "none";
}

Cpmv::Cpmv(Cpmv &&mv) noexcept
{
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::Cpmv(const Cpmv &cp)
{
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(std::string q, std::string z)
{
    pi = new Info;
    pi->qcode = std::move(q);
    pi->zcode = std::move(z);
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    Cpmv one;
    one.pi = new Info;
    one.pi->zcode = pi->zcode + " " + obj.pi->zcode;
    one.pi->qcode = pi->qcode + " " + obj.pi->qcode;
    return one;
}

Cpmv & Cpmv::operator=(Cpmv &&mv) noexcept
{
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv & Cpmv::operator=(const Cpmv &cp)
{
    if(this==&cp)
        return *this;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}

void Cpmv::Display() const
{
    using std::cout;
    using std::endl;
    cout << "Qcode:" << pi->qcode << endl;
    cout << "Zcode:" << pi->zcode << endl;
}
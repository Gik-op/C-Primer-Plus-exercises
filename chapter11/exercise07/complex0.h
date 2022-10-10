#ifndef EXERCISE07_COMPLEX0_H
#define EXERCISE07_COMPLEX0_H

class complex
{
private:
    double real;
    double imag;
public:
    complex();
    complex(double r,double i);
    ~complex();
    complex operator+(const complex &c) const;
    complex operator-(const complex &c) const;
    complex operator*(const complex &c) const;
    complex operator*(double m) const;
    friend complex operator*(double m,const complex &c)
    {return c*m;}
    friend complex operator~(const complex &c);
    friend std::ostream & operator<<(std::ostream &os,const complex &c);
    friend std::istream & operator>>(std::istream &is,complex &c);
};

#endif //EXERCISE07_COMPLEX0_H

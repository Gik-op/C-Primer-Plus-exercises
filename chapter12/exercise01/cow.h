#ifndef EXERCISE01_COW_H
#define EXERCISE01_COW_H

class Cow{
private:
    char name[20];
    char *hobby;
    double weight;
public:
    Cow();
    Cow(const char *nm,const char *ho,double wt);
    Cow(const Cow &c);
    ~Cow();
    Cow & operator=(const Cow &c);
    void showCow() const;
};

#endif //EXERCISE01_COW_H

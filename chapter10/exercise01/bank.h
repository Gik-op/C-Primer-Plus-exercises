#ifndef EXERCISE01_BANK_H
#define EXERCISE01_BANK_H

const int MAX=50;

class Depositor
{
private:
    char name[MAX];
    char account[MAX];
    double money;
public:
    Depositor();
    Depositor(char *nam,char *acc,double dep);
    ~Depositor();
    void showDep() const;
    Depositor addMoney(double add);
    Depositor cutMoney(double cut);
};

#endif //EXERCISE01_BANK_H

#include <iostream>

using namespace std;

const double rate_Da = 0.10;
const double rate_Cl = 0.05;

int main()
{
    int year=0;
    double base=100,money_D,money_C;
    money_D=base;
    money_C=base;
    while(money_D>=money_C)
    {
        year++;
        money_D+=base*rate_Da;
        money_C+=money_C*rate_Cl;
    }
    cout << "After " << year << " years,"
         << "Daphne will have $" << money_D
         << " and Cleo will have $" << money_C << ".\n";
    return 0;
}

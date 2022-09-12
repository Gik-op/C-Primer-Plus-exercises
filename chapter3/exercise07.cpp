#include <iostream>

int main()
{
    using namespace std;
    double gas_eu,gas_us;
    const double km2mile = 0.6214;
    const double gal2l = 3.785;
    cout << "Please enter the fuel consumption of a car(EU): ";
    cin >> gas_eu;
    gas_us = 100*km2mile/(gas_eu/gal2l);
    cout << "The corresponding fuel consumption of a car(US): "<< gas_us << ".\n";
    return 0;
}

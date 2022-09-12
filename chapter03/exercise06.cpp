#include <iostream>

int main()
{
    using namespace std;
    double distance,gas;
    cout << "Please enter the mileage(mile) and the amount of gasoline(gallon) used.(eg.XX XX)" << endl;
    cin >> distance >> gas;
    cout << "The mileage per gallon is " << distance/gas << ".\n";
    return 0;
}

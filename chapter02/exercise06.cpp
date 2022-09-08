#include <iostream>

double light2unit(double);

int main()
{
    using namespace std;
    double light_year;
    cout << "Enter the number of light years: ";
    cin >> light_year;
    cout << light_year << " light years = "
         << light2unit(light_year) << " astronomical units." << endl;
    return 0;
}

double light2unit(double light)
{
    return light*63240;
}

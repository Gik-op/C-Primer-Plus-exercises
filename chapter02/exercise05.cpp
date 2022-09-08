#include <iostream>

double transform(double);

int main()
{
    using namespace std;
    double Cel;
    cout << "Please enter a Celsius value:";
    cin >> Cel;
    cout << Cel << " degrees Celsius is " << transform(Cel) << " degrees Fahrenheit.\n";
    return 0;
}

double transform(double c_degree)
{
    double f_degree = c_degree*1.8 + 32.0;
    return f_degree;
}

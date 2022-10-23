#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z1,z2;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {
            z1 = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z1 << endl;
            z2 = gmean(x,y);
            cout << "Geometric mean of " << x << " and " << y
                << " is " << z2 << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (bad_hmean & bg)
        {
            cout << bg.what();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean & hg)
        {
            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}
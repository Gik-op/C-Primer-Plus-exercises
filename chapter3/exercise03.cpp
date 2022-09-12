#include <iostream>

int main()
{
    using namespace std;
    double l_dgr,l_min,l_sec,latitude;
    const double coeff = 60.0;
    cout << "Enter a latitude in degrees, minutes, and seconds:\n";
    cout << "First, enter the degrees: ";
    cin >> l_dgr;
    cout << "Next, enter the minutes of arc: ";
    cin >> l_min;
    cout << "Finally, enter the seconds of arc: ";
    cin >> l_sec;
    latitude = l_dgr+(l_min+l_sec/coeff)/coeff;
    cout << l_dgr << " degrees, "
         << l_min << " minutes, "
         << l_sec << " seconds = "
         << latitude << " degrees.\n";
    return 0;
}

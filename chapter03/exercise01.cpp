#include <iostream>

int main()
{
    using namespace std;
    const int ft2in = 12;
    int height;
    cout << "Hello, please enter the integer number of your height(inch):_____\b\b\b\b\b";
    cin >> height;
    cout << "Your height is " << height/ft2in << " foot(s), " << height%ft2in << " inch(es).\n";
    return 0;
}

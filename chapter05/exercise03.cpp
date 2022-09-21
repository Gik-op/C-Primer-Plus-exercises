#include <iostream>

using namespace std;

int main()
{
    double num=0,sum=0;
    cout << "Please enter a number(0 to quit):";
    cin >> num;
    while(num)
    {
        sum+=num;
        cout << "Enter the next number,please(0 to quit):";
        cin >> num;
    }
    cout << "The sum of all numbers is " << sum << ".\n";
    return 0;
}

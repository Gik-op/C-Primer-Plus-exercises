#include <iostream>
using std::cout;
using std::endl;
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main()
{
    Stonewt incognito = 275; // uses constructor to initialize
    Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);
    Stonewt all;

    cout << "The celebrity weighed ";
    cout << incognito << endl;
    cout << "The detective weighed ";
    cout << wolfe << endl;
    cout << "The President weighed ";
    taft.set_state(0);
    cout << taft << endl;
    incognito = 276.8;      // uses constructor for conversion
    taft = 325;             // same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighed ";
    cout << incognito << endl;
    cout << "After dinner, the President weighed ";
    taft.set_state(0);
    cout << taft << endl;
    display(taft, 2);
    cout << "The president weighed " << taft-incognito << " more than the celebrity.\n";
    cout << "The celebrity and the President weighed ";
    all = incognito+taft;
    cout << all << endl;
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "275 pounds * 1.75 = " << Stonewt(275)*1.75 << endl;
    cout << "1.75 * 280 pounds = " << 1.75*Stonewt(280) << endl;
    cout << "No stone left unearned\n";
    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        cout << st << endl;
    }
}
#include <iostream>
#include "Cpmv.h"

int main()
{
    using namespace std;
    Cpmv one;
    cout << "Cpmv: one\n";
    one.Display();

    Cpmv two("HappyQ","RelaxZ");
    cout << "\nCpmv: two\n";
    two.Display();

    Cpmv three(two);
    cout << "\nCpmv: three(two)\n";
    three.Display();

    Cpmv four(two+three);
    cout << "\nCpmv: four(two+three)\n";
    four.Display();

    one = two;
    cout << "\none = two:\n";
    one.Display();
    one = two+three;
    cout << "\none = two+three:\n";
    one.Display();

    cout << "Done.\n";
    return 0;
}

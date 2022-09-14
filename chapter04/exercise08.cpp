#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
    double d_pizza;
    double w_pizza;
    string company;
};

int main()
{
    auto *piz = new Pizza;//auto in C++ : find the type based on the value
    cout << "Please enter the diameter of this pizza: ";
    cin >> piz->d_pizza;
    cout << "The weight of this pizza: ";
    (cin >> piz->w_pizza).get(); // handle the space character in the buffer
    cout << "Please enter the company of this pizza: ";
    getline(cin,piz->company);
    cout << "The information:\n";
    cout << "Company: " << piz->company << endl
         << "Diameter: " << piz->d_pizza << endl
         << "Weight: " << piz->w_pizza << endl;
    delete piz;
    return 0;
}

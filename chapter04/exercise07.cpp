#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
    string company;
    double d_pizza;
    double w_pizza;
};

int main()
{
    Pizza piz;
    cout << "Please enter the company of this pizza: ";
    getline(cin,piz.company);
    cout << "The diameter of this pizza: ";
    cin >> piz.d_pizza;
    cout << "The weight of this pizza: ";
    cin >> piz.w_pizza;
    cout << "The information:\n";
    cout << "Company: " << piz.company << endl
         << "Diameter: " << piz.d_pizza << endl
         << "Weight: " << piz.w_pizza << endl;
    return 0;
}

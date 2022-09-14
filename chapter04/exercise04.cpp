#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fName,lName;
    cout << "Enter your first name: ";
    getline(cin,fName);
    cout << "Enter your last name: ";
    getline(cin,lName);
    lName = lName+", "+fName;
    cout << "Here's the information in a single string: " << lName << endl;
    return 0;
}
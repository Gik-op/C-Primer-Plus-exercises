#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string fName,lName;
    char grade;
    int age;
    cout << "What's your first name? ";
    getline(cin,fName);
    cout << "What's your last name? ";
    getline(cin,lName);
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What's your age? ";
    cin >> age;
    cout << "Name: " << lName << ", " << fName << endl;
    cout << "Grade: " << char(grade+1) << endl;
    cout << "Age :" << age << endl;
    return 0;
}

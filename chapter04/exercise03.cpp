#include <iostream>
#include <cstring>

#define MAX 256

using namespace std;

int main()
{
    char fName[MAX],lName[MAX];
    cout << "Enter your first name: ";
    cin.getline(fName,MAX);
    cout << "Enter your last name: ";
    cin.getline(lName,MAX);
    strcat(lName,", ");
    strcat(lName,fName);
    cout << "Here's the information in a single string: " << lName << endl;
    return 0;
}

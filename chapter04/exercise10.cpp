#include <iostream>
#include <array>

#define Time 3

using namespace std;

int main()
{
    static array<double,Time> runGrade;
    double sum=0,average;
    for(int i=0;i<Time;i++)
    {
        cout << "Please enter the grades you get (40meters) : ";
        cin >> runGrade[i];
        sum += runGrade[i];
    }
    average = sum/3.0;
    for(int j=0;j<Time;j++)
    {
        cout << "Time " << j+1 << endl;
        cout << "Grade: " << runGrade[j] << endl;
    }
    cout << "The average grade is " << average << endl;
    return 0;
}

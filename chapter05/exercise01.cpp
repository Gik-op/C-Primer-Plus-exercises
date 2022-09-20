#include <iostream>

using namespace std;

int main()
{
    double num1,num2,sum,temp;
    cout << "Please enter two integers:";
    cin >> num1 >> num2;
    /*if(num1>num2)
     * { temp=num1;num1=num2;num2=temp;}
     * to find the smaller one*/
    sum = temp = num1;
    while(temp<num2)
    {
        temp++;
        sum += temp;
    }
    cout << "The sum of all integers between "
         << num1 << " and " << num2 << " is " << sum << endl;
    return 0;
}

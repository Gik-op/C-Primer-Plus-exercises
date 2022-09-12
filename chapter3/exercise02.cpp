#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    int h_foot,h_inch;
    double BMI,height,weight;
    const int ft2in = 12;
    const double in2meter = 0.0254;
    const double kg2pound = 2.2;
    cout << "Please enter your height(XX(foots) XX(inches)):";
    cin >> h_foot >> h_inch;
    cout << "Please enter your weight(pound):";
    cin >> weight;
    height = (h_foot*ft2in+h_inch)*in2meter;
    weight /= kg2pound;
    BMI = weight/pow(height,2.0);
    cout << "The BMI is " << BMI << ".\n";
    return 0;
}

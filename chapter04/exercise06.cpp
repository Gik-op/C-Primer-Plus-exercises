#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string brand;
    double weight;
    int calorie;
};

int main()
{
    CandyBar snack[3] = {
            {"Mocha Munch",2.3,350},
            {"Hello world",4.4,270},
            {"Maxence well",1.8,480}
    };
    cout << "CandyBar snack:\n";
    for(int i:{0,1,2})
    {
        cout << "Brand: " << snack[i].brand << endl;
        cout << "Weight: " << snack[i].weight << endl;
        cout << "Calorie: " << snack[i].calorie << endl;
    }
    return 0;
}

#include <iostream>

int main()
{
    using namespace std;
    long long world_pp,china_pp;
    double percent;
    cout << "Enter the world's population: ";
    cin >> world_pp;
    cout << "Enter the population of China: ";
    cin >> china_pp;
    percent = (double)china_pp/(double)world_pp;
    cout << "The population of China is " << percent*100 << "% of the world population.\n";
    return 0;
}

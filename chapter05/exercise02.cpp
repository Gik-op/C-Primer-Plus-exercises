#include <iostream>
#include <array>

using namespace std;

#define ArSize 101

int main()
{
    array <long double,ArSize> Factor={1,1};
    for(int i=2;i<ArSize;i++)
        Factor[i]=i*Factor[i-1];
    for(int j=0;j<ArSize;j++)
        cout << j << "!= " << Factor[j] <<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

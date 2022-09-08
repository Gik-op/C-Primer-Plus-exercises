#include <iostream>

using namespace std;

void song1();
void song2();

int main() {
    std::cout << "Hey,look at this silly song!" << std::endl;
    song1();
    song1();
    song2();
    song2();
    return 0;
}

void song1()
{
    cout << "Three blind mice" << endl;
}

void song2()
{
    cout << "See how they run" << endl;
}

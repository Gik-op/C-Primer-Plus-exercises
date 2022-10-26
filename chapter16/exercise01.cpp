#include <iostream>
#include <vector>

bool isPalin(std::vector<char> &v);

int main()
{
    using namespace std;
    vector<char> input;
    char temp;
    cout << "Please enter a string:\n";
    while((temp = cin.get())!= '\n')
        input.push_back(temp);
    cout.setf(ios_base::boolalpha);
    cout << "The Judgment is " << isPalin(input) << ".\n";
    return 0;
}

bool isPalin(std::vector<char> &v)
{
    using std::vector;
    vector<char>::reverse_iterator re = v.rbegin();
    vector<char>::iterator it = v.begin();
    while(re!=v.rend()&&it!=v.end())
    {
        if(*re!=*it)
            return false;
        re++;
        it++;
    }
    return true;
}
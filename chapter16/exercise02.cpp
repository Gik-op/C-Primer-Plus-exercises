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
    vector<char> ToCompare;
    auto ptr = v.begin();
    while(ptr!=v.end())
    {
        if(isalpha(*ptr))
        {
            if(isupper(*ptr))
                *ptr = tolower(*ptr);
            ToCompare.push_back(*ptr);
        }
        ptr++;
    }
    vector<char>::reverse_iterator re = ToCompare.rbegin();
    vector<char>::iterator it = ToCompare.begin();
    /*while(it!=ToCompare.end())
        std::cout << *it++;
    std::cout << std::endl;
     it = ToCompare.begin(); */ // use this block if you want to see the process
    while(re!=ToCompare.rend()&&it!=ToCompare.end())
    {
        if(*re!=*it)
            return false;
        re++;
        it++;
    }
    return true;
}
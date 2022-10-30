#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    int ct=0;
    char ch;
    cout<<"Please enter something:\n";
    while(cin.peek()!='$')
    {
        cin.get(ch);
        ct++;
    }
    cout << "You've input " << ct << " characters until \'$\'.\n";
    return 0;
}

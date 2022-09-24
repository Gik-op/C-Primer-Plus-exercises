#include <iostream>

using namespace std;

int main()
{
    int ch;
    cout<<"Hey,input something!(@ to stop)"<<endl;
    ch=cin.get();
    while(ch!='@')
    {
        if(islower(ch))
            ch=toupper(ch);
        else if(isupper(ch))
            ch=tolower(ch);
        cout<<(char)ch;
        ch=cin.get();
    }
    cout<<endl<<"Done!";
    return 0;
}

#include <iostream>
#include <cctype>

using namespace std;

void ShowUp(string &);

int main()
{
    string input;
    cout<<"Enter a string (q to quit):";
    getline(cin,input);
    while(input[0]!='q'&&input[0]!='\0')
    {
        ShowUp(input);
        cout<<"Next string (q to quit):";
        getline(cin,input);
    }
    cout<<"Bye."<<endl;
    return 0;
}

void ShowUp(string &st)
{
    int i=0;
    while(st[i])
    {
        if(islower(st[i]))
            st[i]=toupper(st[i]);
        cout.put(st[i++]);
    }
    cout<<endl;
}

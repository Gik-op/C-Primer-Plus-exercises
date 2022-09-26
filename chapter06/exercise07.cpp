#include <iostream>
#include <cstring>

using namespace std;

#define NUM(x) ((x)>1?"words":"word")

int main()
{
    string word;
    char ch;
    int vowels=0,consonants=0,all=0;
    cout<<"Enter words (q to quit):\n";
    while(1)
    {
        cin>>word;
        ch=word.at(0);
        if(isalpha(ch)&&(word.size())>1)
        {
            if(strchr("AaEeIiOoUu",ch))
                vowels++;
            else
                consonants++;
        }
        if(ch!='q'||word.size()>1)
            all++;
        else
            break;
    }
    cout<<vowels<<" "<<NUM(vowels)<<" beginning with vowels\n";
    cout<<consonants<<" "<<NUM(consonants)<<" beginning with consonants\n";
    cout<<all-vowels-consonants<<" others\n";
    return 0;
}

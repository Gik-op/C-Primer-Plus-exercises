#include <iostream>
#include <cstring>

using namespace std;

#define MAX 256

int main()
{
    char input[MAX];
    char choice;
    cout<<"Please enter one of the following choices:\n";
    cout<<"c) carnivore  p) pianist\nt) tree  g) game\n";
    do{
        cout<<"\nPlease enter a c,p,t, or g:";
        cin.getline(input,MAX);
        choice=input[0];
    }while(!strchr("cptg",choice));
    switch(choice)
    {
        case'c':cout<<"Tigers are carnivores.\n";break;
        case'p':cout<<"Who is a pianist?\n";break;
        case't':cout<<"A maple is a tree.\n";break;
        case'g':cout<<"Play a game!\n";break;
        default:cout<<"Something wrong.\n";
    }
    cout<<"\nBye.\n";
    return 0;
}

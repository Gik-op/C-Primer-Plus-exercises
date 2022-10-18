#include <iostream>
#include <cstring>
#include "person.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Person * gang[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the gang category:\n"
             << "g: gunslinger  p: poker-player  "
             << "b: bad-dude  q: quit\n";
        cin >> choice;
        while (strchr("gpbq", choice) == nullptr)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'g':   gang[ct] = new Gunslinger;
                break;
            case 'p':   gang[ct] = new PokerPlayer;
                break;
            case 'b':   gang[ct] = new BadDude;
                break;
        }
        cin.get();
        gang[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        gang[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete gang[i];
    cout << "Bye.\n";
    return 0;
}
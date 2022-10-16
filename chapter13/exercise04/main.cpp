#include <iostream>
#include "port.h"

const int size=5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Port * wine[size];

    std::string bran,sty,bott,kind;
    int bot;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the brand: ";
        getline(cin,bran);
        cout << "Enter the style: ";
        getline(cin,sty);
        cout << "Enter the number of bottles: ";
        getline(cin,bott);
        bot = strtol((char *)bott.data(),NULL,10);
        cout << "Enter 1 for normal Port, "
             << "2 for VintagePort: ";
        while ((getline(cin,kind)) && (kind[0] != '1' && kind[0] != '2'))
            cout <<"Enter 1 or 2: ";
        if (kind[0] == '1')
            wine[i] = new Port((char *)bran.data(),(char *)sty.data(), bot);
        else
        {
            int yr;
            std::string nick,year;
            cout << "Enter the nickname: ";
            getline(cin,nick);
            cout << "Enter the year: ";
            getline(cin,year);
            yr = strtol((char *)year.data(),NULL,10);
            wine[i] = new VintagePort((char *)bran.data(),(char *)sty.data(),bot,(char *)nick.data(),yr);
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        wine[i]->Show();
        cout << endl;
    }

    for (int i = 0; i < size; i++)
    {
        delete wine[i];  // free memory
    }
    cout << "Done.\n";
    return 0;
}

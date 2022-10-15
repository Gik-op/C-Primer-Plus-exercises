#include <iostream>
#include <string>
#include "dma.h"
const int MEM = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DMA * p_clients[MEM];
    std::string temp;
    int tempR;
    char kind;

    for (int i = 0; i < MEM; i++)
    {
        cout << "Enter DMA's label: ";
        getline(cin,temp);
        cout << "Enter DMA's rating: ";
        cin >> tempR;
        cout << "Enter 1 for baseDMA, "
             << "2 for lacksDMA or 3 for hasDMA: ";
        while ((cin >> kind).get() && (kind != '1' && kind != '2' && kind !='3'))
            cout <<"Enter 1,2 or 3: ";
        if (kind == '1')
            p_clients[i] = new baseDMA((char *)temp.data(), tempR);
        else if(kind == '2')
        {
            std::string color;
            cout << "Enter the color: ";
            getline(cin,color);
            p_clients[i] = new lacksDMA((char *)color.data(),(char *)temp.data(), tempR);
        }
        else
        {
            std::string style;
            cout << "Enter the style: ";
            getline(cin,style);
            p_clients[i] = new hasDMA((char *)style.data(),(char *)temp.data(), tempR);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < MEM; i++)
    {
        p_clients[i]->View();
        cout << endl;
    }

    for (int i = 0; i < MEM; i++)
    {
        delete p_clients[i];  // free memory
    }
    cout << "Done.\n";
    return 0;
}
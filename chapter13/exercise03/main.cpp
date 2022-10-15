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
    std::string temp,rate,kind;
    int tempR;

    for (int i = 0; i < MEM; i++)
    {
        cout << "Enter DMA's label: ";
        getline(cin,temp);
        cout << "Enter DMA's rating: ";
        getline(cin,rate);
        tempR = strtol((char *)rate.data(),NULL,10);
        cout << "Enter 1 for baseDMA, "
             << "2 for lacksDMA or 3 for hasDMA: ";
        while ((getline(cin,kind)) && (kind[0] != '1' && kind[0] != '2' && kind[0] !='3'))
            cout <<"Enter 1,2 or 3: ";
        if (kind[0] == '1')
            p_clients[i] = new baseDMA((char *)temp.data(), tempR);
        else if(kind[0] == '2')
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

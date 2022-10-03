#include <iostream>
#include "name.h"

int main()
{
    using namespace std;
    using namespace SALES;
    Sales sell[2];
    double init[QUARTERS]={2.2,3.3,4.4,5.5};
    setSales(sell[0],init,4);
    setSales(sell[1]);
    showSales(sell[0]);
    showSales(sell[1]);
    cout<<"Bye.\n";
    return 0;
}

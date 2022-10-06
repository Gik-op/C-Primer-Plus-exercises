#include <iostream>
#include "name.h"

int main()
{
    using namespace std;
    using namespace SALES;
    double init[QUARTERS]={2.2,3.3,4.4,5.5};
    Sales sell0=Sales(init,4);
    Sales sell1=Sales();
    sell0.showSales();
    sell1.showSales();
    cout<<"Bye.\n";
    return 0;
}

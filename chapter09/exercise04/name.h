#ifndef EXERCISE04_NAME_H
#define EXERCISE04_NAME_H

namespace SALES
{
    const int QUARTERS=4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    void setSales(Sales &s,const double ar[],int n);
    void setSales(Sales &s);
    void showSales(const Sales &s);
}



#endif //EXERCISE04_NAME_H

#ifndef EXERCISE04_NAME_H
#define EXERCISE04_NAME_H

namespace SALES
{
    const int QUARTERS=4;
    class Sales
    {
    private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    public:
        Sales();
        Sales(const double ar[],int n);
        ~Sales();
        void showSales()const;
    };
}



#endif //EXERCISE04_NAME_H

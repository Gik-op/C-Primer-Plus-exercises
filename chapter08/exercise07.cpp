// tempover.cpp --- template overloading
#include <iostream>

struct debts
{
    char name[50];
    double amount;
};

template <typename T>            // template A
T SumArray(T arr[], int n);

template <typename T>            // template B
T SumArray(T *arr[], int n);

int main()
{
    using namespace std;
    int sum_i,things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
            {
                    {"Ima Wolfe", 2400.0},
                    {"Ura Foxe", 1300.0},
                    {"Iby Stout", 1800.0}
            };
    double sum_debt,*pd[3];
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;


    sum_i=SumArray(things, 6);  // uses template A
    cout << "Showing Mr. E's sum of things: "<<sum_i;
    sum_debt=SumArray(pd, 3);    // uses template B
    cout << "Showing Mr. E's sum of debts: "<<sum_debt;
    // cin.get();
    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum=0;
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        sum+=arr[i];
    return sum;
}

template <typename T>
T SumArray(T *arr[], int n)
{
    T sum=0;
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        sum+=*(arr[i]);
    return sum;
}

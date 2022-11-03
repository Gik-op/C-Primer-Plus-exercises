#include <iostream>

template<typename T,typename...Args>
long double sum_list(T value,Args...args);

template<typename T>
long double sum_list(T value) { return (long double)value;}

int main()
{
    using std::cout;
    long double sum[2];
    sum[0] = sum_list(1.23,2.48,56,7.28,9.88);
    cout << "The sum of (1.23,2.48,56,7.28,9.88) is " << sum[0] << ".\n";
    sum[1] = sum_list(20,30,40);
    cout << "The sum of (20,30,40) is " << sum[1] << ".\n";
    cout << "Done.\n";
    return 0;
}

template<typename T,typename...Args>
long double sum_list(T value,Args...args)
{
    return (long double)(value+sum_list(args...));
}
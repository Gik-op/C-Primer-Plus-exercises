#include <iostream>

template <typename T>
T max5(T arr[5]);

int main()
{
    using namespace std;
    int max_i,arr_i[5]={-3,2,1,0,-1};
    double max_d,arr_d[5]={2.5,3.8,6.6,2.1,1.6};
    max_i=max5(arr_i);
    max_d= max5(arr_d);
    cout<<"The max number of the first array is "<<max_i<<endl;
    cout<<"The max number of the second array is "<<max_d<<endl;
    return 0;
}

template <typename T>
T max5(T arr[5])
{
    T max=arr[0];
    for(int i=0;i<5;i++)
        max=(max<arr[i]?arr[i]:max);
    return max;
}

#include <iostream>
#include <cstring>

template <typename T>
T maxn(T arr[],int size);
template<> char * maxn(char *arr[],int size);

int main()
{
    using namespace std;
    int max_i,arr_i[6]={1,2,3,4,5,6};
    double max_d,arr_d[4]={1.2,2,4.4,3.6};
    char *max_str,*arr_ch[5]={"Happy","Valentine","'s","Day","!\n"};
    max_i=maxn(arr_i,6);
    max_d=maxn(arr_d,4);
    max_str=maxn(arr_ch,5);
    cout<<"The max number of the first array is "<<max_i<<endl;
    cout<<"The max number of the second array is "<<max_d<<endl;
    cout<<"The max string of the third array is \""<<max_str<<"\""<<endl;
    return 0;
}

template <typename T>
T maxn(T arr[],int size)
{
    T max=arr[0];
    for(int i=0;i<size;i++)
        max=(max<arr[i]?arr[i]:max);
    return max;
}
template<> char * maxn(char *arr[],int size)
{
    char *max=arr[0];
    for(int i=0;i<size;i++)
        max=(strlen(max)<strlen(arr[i])?arr[i]:max);
    return max;
}

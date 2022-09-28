#include <iostream>

using namespace std;

#define Size 10

int Fill_array(double *arr,int size);
void Show_array(double *arr,int size);
void Reverse_array(double *arr,int size);

int main()
{
    int count;
    double arr[Size];
    count=Fill_array(arr,Size);
    cout<<count<<endl;
    Show_array(arr,count);
    Reverse_array(arr,count);
    Show_array(arr,count);
    return 0;
}

int Fill_array(double *arr,int size)
{
    int i=0;
    cout<<"Please enter some numbers\n";
    cout<<"#1:";
    while(i<size&&cin>>arr[i]&&arr[i]>0)
        cout<<"#"<<++i+1<<":";
    return i;
}

void Show_array(double *arr,int size)
{
    for(int i=0;i<size;i++)
        cout<<"#"<<i+1<<":"<<arr[i]<<" ";
    cout<<endl;
}

void Reverse_array(double *arr,int size)
{
    double temp;
    for(int i=1;i<size/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-1-i]=temp;
    }
}


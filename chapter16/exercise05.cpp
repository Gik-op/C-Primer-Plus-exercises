#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
void createArr(T ar[],int n);

template<class T>
int reduce(T ar[],int n); // rank,delete the duplicates, return the number of items

int main()
{
    using namespace std;
    int size = 8,unique[2];
    long arr[size];
    string arr_s[size];
    cout<<"Please enter "<<size<<" numbers:\n";
    createArr(arr,size);
    cout<<"Please enter "<<size<<" strings:\n";
    createArr(arr_s,size);
    unique[0] = reduce(arr,size);
    unique[1] = reduce(arr_s,size);
    cout<<"The number of unique numbers is "<<unique[0]<<endl;
    cout<<"The new array is :\n";
    for(int j=0;j<unique[0];j++)
        cout<<arr[j]<<" ";
    cout<<endl;
    cout<<"The number of unique strings is "<<unique[1]<<endl;
    cout<<"The new array is :\n";
    for(int j=0;j<unique[1];j++)
        cout<<arr_s[j]<<" ";
    cout<<endl;
    return 0;
}

template<class T>
void createArr(T arr[],int n)
{
    using std::cin;
    using std::cout;
    int i=0;
    do{
        T temp;
        while(!(cin>>temp))
        {
            while(cin.get()!='\n')
                continue;
            cout<<"Wrong input!Again:";
            cin>>temp;
        }
        arr[i]=temp;
        i++;
    }while(i<n);
    while(cin.get()!='\n')
        continue;
}

template<class T>
int reduce(T ar[],int n)
{
    using std::vector;
    vector<T> temp;
    int size;
    for(int i=0;i<n;i++)
        temp.push_back(ar[i]);
    std::sort(temp.begin(), temp.end());
    auto end = std::unique(temp.begin(), temp.end());
    temp.erase(end,temp.end());
    size = temp.size();
    for(int i=0;i<size;i++)
        ar[i]=temp[i];
    return size;
}
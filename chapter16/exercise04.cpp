#include <iostream>
#include <algorithm>
#include <vector>

int reduce(long ar[],int n); // rank,delete the duplicates, return the number of items

int main()
{
    using namespace std;
    int size = 8,i=0,unique;
    long arr[size];
    cout<<"Please enter "<<size<<" numbers:\n";
    do{
        long temp;
        while(!(cin>>temp))
        {
            while(cin.get()!='\n')
                continue;
            cout<<"Wrong input!Again:";
            cin>>temp;
        }
        arr[i]=temp;
        i++;
    }while(i<size);
    unique = reduce(arr,size);
    cout<<"The number of unique numbers is "<<unique<<endl;
    cout<<"The new array is :\n";
    for(int j=0;j<unique;j++)
        cout<<arr[j]<<" ";
    cout<<endl;
    return 0;
}

int reduce(long ar[],int n)
{
    using std::vector;
    vector<long> temp;
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
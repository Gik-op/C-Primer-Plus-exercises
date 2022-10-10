#include <iostream>
#include "stonewt.h"

const int MAX=256;
const int mem=6;

using std::cout;
using std::endl;
using std::cin;

int main()
{
    char input[MAX];
    double temp;
    int above11=0;
    Stonewt standard=11,max,min;
    Stonewt array[mem]={Stonewt(214.77),Stonewt(126.48),Stonewt(148.94)};
    for(int i=3;i<mem;i++)
    {
        cout<<"Please enter the number of pounds: ";
        cin.getline(input,MAX);
        temp=strtod(input,NULL);
        while(!isdigit(input[0]))
        {
            printf("Wrong input!\nInput again:");
            cin.getline(input,MAX);
            temp=strtod(input,NULL);
        }
        array[i]=temp;
    }
    max=min=array[0];
    for(int i=0;i<mem;i++)
    {
        if(array[i]>max)
            max=array[i];
        if(array[i]<min)
            min=array[i];
        if(array[i]>=standard)
            above11++;
    }
    cout<<"The min of the array: "<<min<<endl;
    cout<<"The max of the array: "<<max<<endl;
    cout<<"The number of members with a value above 11 is : "<<above11<<endl;
    cin.get();
    return 0;
}

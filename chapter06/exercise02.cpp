#include <iostream>

using namespace std;
const int Size=10;

#define NUM(x) ((x)>1?"numbers":"number")
#define BE(x) ((x)>1?"are":"is")

int main()
{
    int index,count=0;
    double donation[Size],sum=0,average;
    cout<<"Please enter the numbers you want to calculate:\n";
    for(index=0;index<Size;index++)
    {
        cout<<"#"<<index+1<<":";
        if(cin>>donation[index])
            sum+=donation[index];
        else
            break;
    }
    average=sum/index;
    for(int i=0;i<index;i++)
        if(donation[i]>average)
            count++;
    cout<<"The average of all the "<<index<<" "<<NUM(index)<<" is "<<average
        <<" and there "<<BE(count)<<" "<<count<<" "<<NUM(count)<<" which "<<BE(count)<<" greater than the average."<<endl;
    return 0;
}

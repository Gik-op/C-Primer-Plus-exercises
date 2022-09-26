#include <iostream>

using namespace std;

#define LIM 10

int setScore(double *arr,int size);
void showScore(const double *arr,int size);
double meanScore(const double *arr,int size);

int main()
{
    int size;
    double scores[LIM],aver;
    size=setScore(scores,LIM);
    if(size==0)
        cout<<"No data!\n";
    else
    {
        showScore(scores,size);
        aver=meanScore(scores,size);
        cout<<"The average of all the scores is "<<aver<<" .\n" ;
    }
    return 0;
}

int setScore(double *arr,int size)
{
    int count=0;
    std::cout<<"Please enter your data\n(no more than 10,but you can enter 0 to stop)\n";
    while(count<size)
    {
        std::cout<<"#"<<count+1<<":";
        cin>>arr[count];
        if(arr[count]==0)
            break;
        count++;
    }
    return count;
}

void showScore(const double *arr,int size)
{
    std::cout<<"The result:\n";
    for(int i=0;i<size;i++)
        std::cout<<"#"<<i+1<<":"<<arr[i]<<"   ";
    std::cout<<std::endl;
}

double meanScore(const double *arr,int size)
{
    double aver=0;
    for(int i=0;i<size;i++)
        aver+=arr[i];
    return aver/size;
}

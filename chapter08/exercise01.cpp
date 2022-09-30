#include <iostream>

#define MAX 256

void stupidFuc(char *str,int i=0);

int main()
{
    using namespace std;
    char input[MAX],num[MAX];
    int number;
    while(1)
    {
        cout<<"Please enter a string(empty line to quit):\n";
        cin.getline(input,MAX);
        if(input[0]=='\0')
            break;
        cout<<"Please enter the number that you will use in the function:";
        cin.getline(num,MAX);
        number=strtol(num,NULL,10);
        cout<<"The result for stupidFuc("<<"\""<<input<<"\""<<", "<<number<<")is\n";
        stupidFuc(input,number);
    }
    cout<<"Bye.\n";
    return 0;
}

void stupidFuc(char *str,int i)
{
    static int count=1;
    if(i==0)
        std::cout<<str<<std::endl;
    else
        for(int j=0;j<count;j++)
            std::cout<<str<<std::endl;
    count++;
}

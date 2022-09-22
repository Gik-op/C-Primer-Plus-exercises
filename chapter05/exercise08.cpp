#include <iostream>
#include <cstring>

using namespace std;

#define MaxLine 256

int main()
{
    char input[MaxLine];
    int count=0;
    cout<<"Enter words(to stop,type the word done):"<<endl;
    do {
        (cin>>input).get();
        if(strcmp(input," "))
            count++;
    }while(strcmp(input,"done"));
    cout<<"You entered a total of "<<count-1<<" words.\n";//count includes the word "done"
    return 0;
}

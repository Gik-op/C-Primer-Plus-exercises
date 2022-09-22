#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int count=0;
    cout<<"Enter words(to stop,type the word done):"<<endl;
    do {
        (cin>>input).get();
        if(input!=" ")
            count++;
    }while(input!="done");
    cout<<"You entered a total of "<<count-1<<" words.\n";//count includes the word "done"
    return 0;
}

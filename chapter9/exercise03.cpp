#include <iostream>
#include <cstring>

#define buffer_size 50

typedef struct{
    char dross[20];
    int slag;
}chaff;

int main()
{
    using namespace std;
    static int buffer[buffer_size];
    auto arr=new (buffer) chaff[2];
    for(int count=0;count<2;count++)
    {
        char input[buffer_size];
        cout<<"Please enter something for dross:";
        cin.getline(input,19);
        while(input[0]=='\0')
        {
            cout<<"Wrong input!Again:";
            cin.getline(input,19);
        }
        strcpy(arr[count].dross,input);
        cout<<"Please enter an integer for salg:";
        cin.getline(input,buffer_size);
        arr[count].slag=strtol(input,NULL,10);
    }
    for(int count=0;count<2;count++)
    {
        cout<<"#"<<count+1<<endl;
        cout<<"Dross: "<<arr[count].dross<<"  Slag: "<<arr[count].slag<<endl;
    }
    cout<<"Bye.\n";
    return 0;
}

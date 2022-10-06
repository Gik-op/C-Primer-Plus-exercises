#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;
    Stack st;
    char ch;
    customer guest;
    double total=0;
    cout<<"Please enter A to add a purchase order,\n"
        <<"P to process a PO, or Q to quit.\n";
    while(cin>>ch&&toupper(ch)!='Q')
    {
        while(cin.get()!='\n')
            continue;
        if(!isalpha(ch))
        {
            cout<<'\a';
            continue;
        }
        switch(ch)
        {
            case'A':
            case'a':cout<<"Enter your name: ";
                    cin>>guest.fullname;
                    cout<<"Enter a PO number to add: ";
                    cin>>guest.payment;
                    if(st.isfull())
                        cout<<"Stack already full\n";
                    else
                        st.push(guest);
                    break;
            case'p':
            case'P':if(st.isempty())
                        cout<<"Stack already empty.\n";
                    else{
                        st.pop(guest);
                        total+=guest.payment;
                        cout<<guest.fullname<<" #"<<guest.payment<<"popped.\n";
                        cout<<"Total: "<<total<<"\n";
                    }
                    break;
        }
        cout<<"Please enter A to add a purchase order,\n"
            <<"P to process a PO or Q to quit.\n";
    }
    cout<<"Bye."<<endl;
    return 0;
}

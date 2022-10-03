#include <iostream>
#include "bank.h"

const int MAXLINE=256;

int main()
{
    using namespace std;
    double deposit;
    char name[MAX],account[MAX],input[MAX];
    cout<<"Let's create an account!\n";
    cout<<"Please enter your name:";
    cin.getline(name,MAXLINE);
    if(name[0])
    {
        cout<<"Please enter your account:";
        cin.getline(account,MAXLINE);
        while(!account[0])
        {
            cout<<"Wrong input!Input again:";
            cin.getline(account,MAXLINE);
        }
        cout<<"Please enter your deposit:";
        cin.getline(input,MAXLINE);
        deposit=strtod(input,NULL);
        Depositor my_account(name,account,deposit);
        while(1)
        {
            cout<<"Let's see your account:\n";
            my_account.showDep();
            cout<<"Do you want to add money?(Y or N):";
            cin.getline(input,MAXLINE);
            if(input[0]=='Y')
            {
                cout<<"How much you want to add?\n";
                cin.getline(input,MAXLINE);
                deposit=strtod(input,NULL);
                my_account.addMoney(deposit);
            }
            cout<<"Do you want to draw money?(Y or N):";
            cin.getline(input,MAXLINE);
            if(input[0]=='Y')
            {
                cout<<"How much you want to draw?\n";
                cin.getline(input,MAXLINE);
                deposit=strtod(input,NULL);
                my_account.cutMoney(deposit);
            }
            cout<<"Do you want to leave?(Y or N)\n";
            cin.getline(input,MAXLINE);
            if(input[0]=='Y')
                break;
        }
    }
    cout<<"Bye.\n";
    return 0;
}

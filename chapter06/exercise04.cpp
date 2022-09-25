#include <iostream>
#include <cstring>

#define strsize 25
#define member 5
using namespace std;

struct bop{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;//0=fullname,1=title,2=bopname
};

struct bop BOP[member]={
        {"Wimp Macho","professor","fool",0},
        {"Raki Rhodes","Junior Programmer","Fox",1},
        {"Celia Laiter","Senior Programmer","MIPS",2},
        {"Hoppy Hipman","Professor","Analyst Trainee",2},
        {"Pat Hand","Professor","LOOPY",2}
};

void show_list(struct bop[],int size,char choice);

int main()
{
    char choice;
    char input[strsize];
    cout<<"Benevolent Order of Programmers Report\n";
    cout<<"a.display by name    b.display by title\n";
    cout<<"c.display by bopname d.display by preference\nq.quit\n";
    do
    {
        cout<<"Enter your choice:";
        cin.getline(input,strsize);
        choice=input[0];
        while(!strchr("abcdq",choice))
        {
            cout<<"Wrong input,input again:";
            cin.getline(input,strsize);
            choice=input[0];
        }
        if(choice=='q')
            break;
        show_list(BOP,member,choice);
    }while(1);
    cout<<"Bye!\n"<<endl;
    return 0;
}

void show_list(struct bop Bop[],int size,char choice)
{
    for(int i=0;i<size;i++)
    {
        if(choice=='a'||(choice=='d'&&Bop[i].preference==0))
            cout<<Bop[i].fullname<<endl;
        else if(choice=='b'||(choice=='d'&&Bop[i].preference==1))
            cout<<Bop[i].title<<endl;
        else if(choice=='c'||(choice=='d'&&Bop[i].preference==2))
            cout<<Bop[i].bopname<<endl;
    }
}

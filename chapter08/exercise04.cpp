#include <iostream>
#include <cstring>

using namespace std;

typedef struct{
    char *str;
    int ct;
}stringy;

void set(stringy &base,const char *arr);

void show(const string &one,int times=1);
void show(const stringy &,int times=1);

int main()
{
    stringy beany;
    char testing[]="Reality isn't what it used to be.";
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0]='D';
    testing[1]='u';
    show(testing);
    show(testing,3);
    show("Done!");
    return 0;
}

void set(stringy &base,const char *arr)
{
    int max=256;
    base.str=new char[max];
    strcpy(base.str,arr);
    base.ct=strlen(arr);
}

void show(const string &one,int times)
{
    for(int i=0;i<times;i++)
        std::cout<<one<<std::endl;
}
void show(const stringy &base,int times)
{
    for(int i=0;i<times;i++)
        std::cout<<base.str<<std::endl;
}


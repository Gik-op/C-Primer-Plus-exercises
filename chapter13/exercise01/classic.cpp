#include <iostream>
#include <cstring>
#include "classic.h"

// Cd member functions

Cd::Cd(char *s1,char *s2,int n,double x)
{
    strncpy(performers,s1,mem-1);
    performers[mem-1]='\0';
    strncpy(label,s2,size-1);
    label[size-1]='\0';
    selections=n;
    playtime=x;
}

Cd::Cd(const Cd &d)
{
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}

Cd::Cd()
{
    performers[0]='\0';
    label[0]='\0';
    selections=0;
    playtime=0;
}

Cd::~Cd()
=default;

void Cd::Report() const
{
    using std::cout;
    using std::endl;
    cout<<"Performers: "<<performers<<endl;
    cout<<"Label: "<<label<<endl;
    cout<<"Selections: "<<selections<<endl;
    cout<<"Playtime: "<<playtime<<endl;
}

Cd & Cd::operator=(const Cd &d)
{
    if(this==&d)
        return *this;
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
    return *this;
}

// classic member functions

Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : Cd(s1, s2,n,x)
{
    strncpy(master,s3,len-1);
    master[len-1]='\0';
}

Classic::Classic(const Cd &d, char *s) : Cd(d)
{
    strncpy(master,s,len-1);
    master[len-1]='\0';
}

Classic::Classic(const Classic &c) : Cd(c)
{
    strcpy(master,c.master);
}

Classic::Classic() : Cd()
{
    master[0]='\0';
}

Classic::~Classic()
=default;

void Classic::Report() const
{
    Cd::Report();
    std::cout<<"Masterpiece: "<<master<<std::endl;
}

Classic & Classic::operator=(const Classic &c)
{
    if(this==&c)
        return *this;
    Cd::operator=(c);
    strcpy(master,c.master);
    return *this;
}
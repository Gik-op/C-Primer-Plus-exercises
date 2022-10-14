#include <iostream>
#include <cstring>
#include "classic.h"

// Cd member functions

Cd::Cd(char *s1,char *s2,int n,double x)
{
    int mem=strlen(s1);
    int size=strlen(s2);
    performers = new char[mem+1];
    strcpy(performers,s1);
    label = new char[size+1];
    strcpy(label,s2);
    selections=n;
    playtime=x;
}

Cd::Cd(const Cd &d)
{
    int mem=strlen(d.performers);
    int size=strlen(d.label);
    performers = new char[mem+1];
    strcpy(performers,d.performers);
    label = new char[size+1];
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}

Cd::Cd()
{
    performers = new char[1];
    performers[0]='\0';
    label = new char[1];
    label[0]='\0';
    selections=0;
    playtime=0;
}

Cd::~Cd()
{
    delete []performers;
    delete []label;
}

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
    int mem=strlen(d.performers);
    int size=strlen(d.label);
    delete []performers;
    performers = new char[mem+1];
    strcpy(performers,d.performers);
    delete []label;
    label = new char[size+1];
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
    return *this;
}

// classic member functions

Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : Cd(s1, s2,n,x)
{
    int len=strlen(s3);
    master = new char[len+1];
    strcpy(master,s3);
}

Classic::Classic(const Cd &d, char *s) : Cd(d)
{
    int len=strlen(s);
    master = new char[len+1];
    strcpy(master,s);
}

Classic::Classic(const Classic &c) : Cd(c)
{
    int len=strlen(c.master);
    master = new char[len+1];
    strcpy(master,c.master);
}

Classic::Classic() : Cd()
{
    master = new char[1];
    master[0]='\0';
}

Classic::~Classic()
{
    delete []master;
}

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
    int len=strlen(c.master);
    delete []master;
    master = new char[len+1];
    strcpy(master,c.master);
    return *this;
}
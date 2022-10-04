#ifndef EXERCISE02_PERSON_H
#define EXERCISE02_PERSON_H

#include <string>

class Person{
private:
    static const int LIMIT=25;
    std::string lname;
    char fname[LIMIT];
public:
    Person(){lname="";fname[0]='\0';}
    Person(const std::string &ln,const char *fn="Heyyou");
    ~Person();
    void Show()const;        //firstname lastname format
    void FormalShow()const;  //lastname,firstname format
};

#endif //EXERCISE02_PERSON_H

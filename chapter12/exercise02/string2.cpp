#include <cstring>
#include <cctype>
#include "string2.h"
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method

int String::HowMany()
{
    return num_strings;
}

// class methods

String::String(const char * s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

// overloaded operator methods

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

String operator+(String &st1,String &st2)
{
    String one(st1);
    strcat(one.str,st2.str);
    one.len+=st2.len;
    return one;
}

String & String::stringlow()
{
    for(int i=0;i<len;i++)
        if(isupper(str[i]))
            str[i]=tolower(str[i]);
    return *this;
}

String & String::stringup()
{
    for(int i=0;i<len;i++)
        if(islower(str[i]))
            str[i]=toupper(str[i]);
    return *this;
}

int String::has(char c) const
{
    int count=0;
    for(int i=0;i<len;i++)
        if(str[i]==c)
            count++;
    return count;
}
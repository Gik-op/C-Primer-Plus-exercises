#ifndef EXERCISE02_STRING2_H
#define EXERCISE02_STRING2_H

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str;
    int len;                // length of string
    static int num_strings; // number of objects
    static const int CINLIM = 80;  // cin input limit
public:
// constructors and other methods
    String(const char * s);
    String();
    String(const String &); // copy constructor
    ~String();
    int length () const { return len; }
// overloaded operator methods
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
// overloaded operator friends
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
// new function
    friend String operator+(String &st1,String &st2);
    String & stringlow();
    String & stringup();
    int has(char c) const;
// static function
    static int HowMany();
};

#endif //EXERCISE02_STRING2_H

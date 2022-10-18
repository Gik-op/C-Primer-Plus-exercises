#include "emp.h"

// abstr_emp functions

abstr_emp::abstr_emp()
{
    fname = "none";
    lname = "none";
    job = "none";
}

abstr_emp::abstr_emp(const string &fn, const string &ln, const string &j)
{
    fname = fn;
    lname = ln;
    job = j;
}

void abstr_emp::ShowAll() const
{
    using std::cout;
    using std::endl;
    cout<<"First name: "<<fname<<endl;
    cout<<"Last name: "<<lname<<endl;
    cout<<"Job: "<<job<<endl;
}

void abstr_emp::SetAll()
{
    using std::cout;
    using std::cin;
    using std::endl;
    while(cin.get()!='\n')
        continue;
    cout<<"Enter first name:";
    getline(cin,fname);
    cout<<"Enter last name:";
    getline(cin,lname);
    cout<<"Enter the job:";
    getline(cin,job);
}

std::ostream & operator<<(std::ostream & os,const abstr_emp &e)
{
    os<<"First name: "<<e.fname<<std::endl;
    os<<"Last name:"<<e.lname<<std::endl;
    return os;
}

abstr_emp::~abstr_emp() = default;

// employee functions

employee::employee() : abstr_emp() {}

employee::employee(const string &fn, const string &ln, const string &j) : abstr_emp(fn,ln,j) {}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

// manager functions

manager::manager() : abstr_emp()
{
    inchargeof = 0;
}

manager::manager(const string &fn, const string &ln, const string &j, int ico) : abstr_emp(fn,ln,j)
{
    inchargeof = ico;
}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e)
{
    inchargeof = ico;
}

manager::manager(const manager &m) : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout<<"Number of abstr_emps managed: "<<inchargeof<<std::endl;
}

static int getNum();

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout<<"Enter the number of abstr_emps managed:";
    inchargeof=getNum();
}

// fink functions

fink::fink() : abstr_emp()
{
    reportsto = "none";
}

fink::fink(const string &fn, const string &ln, const string &j, const string &rpo) : abstr_emp(fn,ln,j)
{
    reportsto = rpo;
}

fink::fink(const abstr_emp &e, const string &rpo) : abstr_emp(e)
{
    reportsto = rpo;
}

fink::fink(const fink &e) : abstr_emp(e)
{
    reportsto = e.reportsto;
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout<<"Reports to: "<<reportsto<<std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout<<"To whom fink reports:";
    getline(std::cin,reportsto);
}

// highfink functions

highfink::highfink() : abstr_emp(),manager(),fink() {}

highfink::highfink(const string &fn, const string &ln, const string &j,
                   const string &rpo, int ico) : abstr_emp(fn,ln,j),
                   manager(fn,ln,j,ico),fink(fn,ln,j,rpo) {}

highfink::highfink(const abstr_emp &e, const string &rpo, int ico) : abstr_emp(e),manager(e,ico),fink(e,rpo) {}
highfink::highfink(const manager &m, const string &rpo) : abstr_emp(m),manager(m),fink(m,rpo) {}
highfink::highfink(const fink &f, int ico) : abstr_emp(f),manager(f,ico),fink(f) {}
highfink::highfink(const highfink &h) : abstr_emp(h),manager(h),fink(h) {}

void highfink::ShowAll() const
{
    std::cout<<(const abstr_emp &)(*this);
    std::cout<<"Number of abstr_emps managed: "<<this->InChargeOf()<<std::endl;
    std::cout<<"Reports to: "<<this->ReportsTo()<<std::endl;
}

void highfink::SetAll()
{
    manager::SetAll();
    std::cout<<"To whom management fink reports:";
    getline(std::cin,ReportsTo());
}


// static functions
int getNum()
{
    int num;
    using std::cin;
    using std::cout;
    while(!(cin>>num)||num<=0)
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
        cout<<"Wrong input!Again:";
    }
    while(cin.get()!='\n')
        continue;
    return num;
}
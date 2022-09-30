#include <iostream>
using namespace std;

const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[],int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[],int n);

int main()
{
    cout<<"Enter class size: ";
    int class_size;
    cin>>class_size;
    while(cin.get()!='\n')
        continue;
    student *ptr_stu=new student[class_size];
    int entered=getinfo(ptr_stu,class_size);
    for(int i=0;i<entered;i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu,entered);
    delete []ptr_stu;
    cout<<"Done.\n";
    return 0;
}

int getinfo(student pa[],int n)
{
    using std::cout;
    int i=0;
    char input[SLEN];
    do{
        cout<<"#"<<i+1<<endl;
        cout<<"Student's name:";
        cin.getline(pa[i].fullname,SLEN);
        if(pa[i].fullname[0]=='\0')
            break;
        cout<<"Student's hobby:";
        cin.getline(pa[i].hobby,SLEN);
        cout<<"The ooplevel:";
        cin.getline(input,SLEN);
        pa[i].ooplevel=strtol(input,NULL,10);
        i++;
    }while(i<n);
    return i;
}

void display1(student st)
{
    using std::cout;
    using std::endl;
    cout<<"NAME: "<<st.fullname<<"  HOBBY: "
        <<st.hobby<<"  LEVEL: "<<st.ooplevel<<endl;
}

void display2(const student *ps)
{
    using std::cout;
    using std::endl;
    cout<<"NAME: "<<ps->fullname<<"  HOBBY: "
        <<ps->hobby<<"  LEVEL: "<<ps->ooplevel<<endl;
}

void display3(const student pa[],int n)
{
    using std::cout;
    using std::endl;
    for(int i=0;i<n;i++)
    {
        cout<<"#"<<i+1<<endl;
        cout<<"NAME: "<<pa[i].fullname<<"\tHOBBY: "
            <<pa[i].hobby<<"\tLEVEL: "<<pa[i].ooplevel<<endl;
    }
}

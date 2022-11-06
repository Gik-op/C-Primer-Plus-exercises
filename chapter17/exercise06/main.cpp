#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#include "emp.h"

int main()
{
    const int SIZE = 10;
    int classtype;
    int origin_num = 0;
    abstr_emp *pc[SIZE];

    char ch;
    const char * file = "staff.txt";

/* open the file */
    ifstream fin;
    fin.open(file,ios_base::in|ios_base::out);

    if(!fin.is_open())
    {
        cerr << "Can't open " << file << " file for input.\n";
        exit(EXIT_FAILURE);
    }
    /* Not First open */
    if(fin.peek() != EOF)
    {
        cout << "Here are the contents of the "
             << file << " file:\n";
        int i=0;
        //  read and show the data
        while ((fin >> classtype).get(ch))
        {
            abstr_emp *temp;
            switch(classtype)
            {
                case Employee: temp=new employee;break;
                case Manager: temp=new manager;break;
                case Fink: temp=new fink;break;
                case Highfink: temp=new highfink;break;
            }
            temp->ReadAll(fin);
            temp->ShowAll();
            delete temp;
            i++;
        }
        origin_num = i;
    }

/* add new data */
    ofstream add(file, ios::out | ios::app);
    if (!add.is_open())
    {
        cerr << "Can't open " << file << " file for add.\n";
        exit(EXIT_FAILURE);
    }
    add.seekp(ios_base::end); // move to the end, prepare to add
    int ct;
    for(ct=0;ct<SIZE-origin_num;ct++)
    {
        string choice;
        cout << "Enter the staff category(s to stop):\n";
        cout << "e)employee        m)manager\n"
                "f)fink            h)highfink\n";
        getline(cin,choice); // here has a problem
        while(!strchr("sSeEmMhHfF",choice[0]))
        {
            cout<<"Invalid input.Again:";
            getline(cin,choice);
        }
        switch(choice[0])
        {
            case'e':
            case'E': pc[ct] = new employee;pc[ct]->SetAll();break;
            case'm':
            case'M': pc[ct] = new manager;pc[ct]->SetAll();break;
            case'f':
            case'F': pc[ct] = new fink;pc[ct]->SetAll();break;
            case'h':
            case'H': pc[ct] = new highfink;pc[ct]->SetAll();
            default:break;
        }
        if(choice[0]=='s'||choice[0]=='S')
            break;
    }
    for(int i=0;i<ct;i++)
    {
        pc[i]->WriteAll(add);
        delete pc[i];
    }
    add.close();

/* show revised file */
    fin.clear(); // Remember to change the bit into goodbit
    fin.seekg(0);
    cout << "Here are the contents of the "
         << file << " file:\n";
    //  read and show the data
    while ((fin >> classtype).get(ch))
    {
        abstr_emp *one;
        switch(classtype)
        {
            case Employee: one=new employee;break;
            case Manager: one=new manager;break;
            case Fink: one=new fink;break;
            case Highfink: one=new highfink;break;
        }
        one->ReadAll(fin);
        one->ShowAll();
        delete one;
    }
    fin.close();

    cout << "Done.\n";
    return 0;
}
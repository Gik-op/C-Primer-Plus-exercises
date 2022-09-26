#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct {
    string name;
    double money;
}donors;

int main()
{
    ifstream fin;
    fin.open("List.txt");
    int number,count=0;
    (fin>>number).get();
    auto them=new donors[number]();
    for(int i=0;i<number;i++)
    {
        getline(fin,them[i].name);
        (fin>>them[i].money).get();
    }
    cout<<"Grand Patrons:\n";
    for(int i=0;i<number;i++)
    {
        if(them[i].money>10000)
        {
            cout<<"#"<<count+1<<": "<<them[i].name<<" "<<them[i].money<<endl;
            count++;
        }
    }
    if(count==0)
        cout<<"None\n";
    count=0;
    cout<<"\nPatrons:\n";
    for(int i=0;i<number;i++)
    {
        if(them[i].money<=10000)
        {
            cout<<"#"<<count+1<<": "<<them[i].name<<" "<<them[i].money<<endl;
            count++;
        }
    }
    if(count==0)
        cout<<"None\n";
    delete []them;
    fin.close();
    return 0;
}

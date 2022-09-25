#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string name;
    double money;
}donors;

int main()
{
    int number,count=0;
    cout<<"Please enter the number of donors:";
    (cin>>number).get();
    auto them=new donors[number]();
    for(int i=0;i<number;i++)
    {
        cout<<"#"<<i+1<<":\n";
        cout<<"Name:";
        getline(cin,them[i].name);
        cout<<"Donation:";
        (cin>>them[i].money).get();
    }
    cout<<"\nGrand Patrons:\n";
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
    return 0;
}

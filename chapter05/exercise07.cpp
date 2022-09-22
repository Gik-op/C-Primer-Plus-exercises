#include <iostream>
#include <string>

using namespace std;

struct CAR{
    string Company;
    int car_madeYear;
};

int main()
{
    int car_num;
    string input;
    cout<<"How many cars do you wish to catalog?";
    (cin>>car_num).get();
    CAR *cars=new CAR[car_num];
    for(int index=0;index<car_num;index++)
    {
        cout<<"Car #"<<index+1<<endl;
        cout<<"Please enter the make:";
        getline(cin,cars[index].Company);
        cout<<"Please enter the year made:";
        (cin>>cars[index].car_madeYear).get();
    }
    cout<<"Here is your collection:"<<endl;
    for(int i=0;i<car_num;i++)
        cout<<cars[i].car_madeYear<<" "<<cars[i].Company<<endl;
    delete []cars;
    return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

const int MAX=256;

typedef struct{
    char brand[MAX];
    double weight;
    int calorie;
}CandyBar;

void setCB(CandyBar &name,char brd[]="Millennium Munch",double weight=2.85,int cal=350);
void showCB(CandyBar &name);

int main()
{
    using namespace std;
    CandyBar myCandy;
    char input[MAX],num[MAX];
    double weig;
    int calo;
    cout<<"Please enter the brand:";
    cin.getline(input,MAX);
    /*while(input[0]=='\0')
    {
        cout<<"Input again:";
        cin.getline(input,MAX);
    }*/
    cout<<"Please enter the weight:";
    cin.getline(num,MAX);
    weig=strtol(num,NULL,10);
    cout<<"Please enter the calorie:";
    cin.getline(num,MAX);
    calo=strtol(num,NULL,10);
    if(input[0]=='\0'||weig==0||calo==0)
        setCB(myCandy);
    else
        setCB(myCandy,input,weig,calo);
    showCB(myCandy);
    return 0;
}

void setCB(CandyBar &name,char brd[],double weight,int cal)
{
    strcpy(name.brand,brd);
    name.weight=weight;
    name.calorie=cal;
}

void showCB(CandyBar &name)
{
    using std::cout;
    using std::endl;
    cout<<"Brand of the candy: "<<name.brand<<endl;
    cout<<"The weight: "<<name.weight<<endl;
    cout<<"The calorie: "<<name.calorie<<endl;
}

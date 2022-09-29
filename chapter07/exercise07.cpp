#include <iostream>

const int Max=5;

using namespace std;

double * fill_array(double *ar);
void Show_array(const double *ar,const double *end);
void revalue(double r,double *ar,double *end);

int main()
{
    double properties[Max];
    double *tail=fill_array(properties);
    Show_array(properties,tail);
    if(tail)
    {
        cout<<"Enter revaluation factor: ";
        double factor;
        while(!(cin>>factor))
        {
            cin.clear();
            while(cin.get()!='\n')
                continue;
            cout<<"Bad input;Please enter a number: ";
        }
        revalue(factor,properties,tail);
        Show_array(properties,tail);
    }
    cout<<"Done.\n";
    cin.get();
    cin.get();
    return 0;
}

double * fill_array(double *ar)
{
    using namespace std;
    double temp;
    int i=0;
    while(1)
    {
        cout<<"Enter value #"<<++i<<": ";
        cin>>temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get()!='\n')
                continue;
            cout<<"Bad input; input process terminated.\n";
            break;
        }
        else if(temp<0)
            break;
        *(ar++)=temp;
    }
    return ar-1;
}

void Show_array(const double *ar,const double *end)
{
    using namespace std;
    int i=0;
    while(ar<=end)
    {
        cout<<"Property #"<<++i<<": $";
        cout<<*(ar++)<<endl;
    }
}

void revalue(double r,double *ar,double *end)
{
    while(ar<=end)
        *(ar++)*=r;
}

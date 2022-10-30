#include <iostream>
#include <fstream>

int main(int argc,char **argv)
{
    using namespace std;
    if(argc==1)
        cout<<("No enough parameters!\n");
    else
    {
        ofstream fout;
        fout.open(argv[1]);
        if(!fout.is_open())
            cout<<"Can't open the "<<argv[1]<<" file!\n";
        else
        {
            char ch;
            cout<<"Please input something:\n";
            while(!cin.eof())
            {
                cin.get(ch);
                fout.put(ch);
            }
        }
    }
    cout<<"Done.\n";
    cin.get();
    return 0;
}

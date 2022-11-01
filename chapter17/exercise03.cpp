#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
    using namespace std;
    if(argc<3)
    {
        cout<<"No enough parameters!\n";
    }
    else
    {
        ifstream fin(argv[1]);
        ofstream fout(argv[2]);
        if(!fin.is_open())
        {
            cout<<"Can't open the file "<<argv[1]<<".\n";
            fin.close();
            exit(EXIT_FAILURE);
        }
        if(!fout.is_open())
        {
            cout<<"Can't open the file "<<argv[2]<<".\n";
            fout.close();
            exit(EXIT_FAILURE);
        }
        char ch;
        cout << "Begin to copy.\n";
        while(fin >> ch)
            fout << ch;
        fin.close();
        fout.close();
        cout<<"Done!\n";
    }
    return 0;
}

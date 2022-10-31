#include <iostream>
#include <fstream>

// Can't run

int main(int argc, char ** argv)
{
    using namespace std;
    char *source,*target;
    if(argc<3)
    {
        cout<<"No enough parameters!\n";
        exit(1);
    }
    //  这里存在问题，似乎无法运行出来
    source=argv[1];
    target=argv[2];
    ifstream fin;
    ofstream fout;
    fin.open(source);
    if(!fin.is_open())
    {
        cout<<"Can't open the file "<<source<<".\n";
        exit(EXIT_FAILURE);
    }
    fout.open(target);
    if(!fout.is_open())
    {
        cout<<"Can't open the file "<<target<<".\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    while(fin.get(ch))
        fout.put(ch);
    fin.close();
    fout.close();
    cout<<"Done!\n";
    return 0;
}

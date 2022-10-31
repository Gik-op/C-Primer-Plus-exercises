#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    ifstream fin_1,fin_2;
    ofstream fout;
    string source1,source2,target;
    cout << "Please enter a name for the first source file:";
    getline(cin,source1);
    fin_1.open(source1.c_str());
    if(!fin_1.is_open())
        cout<<"Can't open the file "<<source1<<".\n";

    cout << "Please enter a name for the second source file:";
    getline(cin,source2);
    fin_2.open(source2.c_str());
    if(!fin_2.is_open())
        cout<<"Can't open the file "<<source2<<".\n";

    cout << "Please enter a name for the target file:";
    getline(cin,target);
    fout.open(target.c_str());
    if(!fout.is_open())
        cout<<"Can't open the file "<<source1<<".\n";

    while(!fin_1.eof()&&!fin_2.eof())
    {
        string line1,line2,final_line;
        getline(fin_1,line1);
        getline(fin_2,line2);
        final_line = line1.append(" ") + line2;
        fout << final_line << endl;
    }
    if(!fin_1.eof())    // 最后一行行首多了一个空格
    {
        string line;
        getline(fin_1,line);
        fout << line << endl;
    }
    if(!fin_2.eof())
    {
        string line;
        getline(fin_2,line);
        fout << line << endl;
    }

    fin_1.close();
    fin_2.close();
    fout.close();
    cout << "Done.\n";
    return 0;
}

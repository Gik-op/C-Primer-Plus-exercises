#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

inline void ShowStr(const std::string &s) { std::cout<<s<<std::endl;}
class Store
{
private:
    std::ofstream os;
public:
    explicit Store(std::ofstream &o) : os(o) { }
    void operator()(const std::string &s)
    {
        size_t len = s.length();
        os.write((char *)&len,sizeof(std::size_t));
        os.write(s.data(),len);
    }
};

void GetStrs(std::ifstream &fin,std::vector<std::string> &vec);

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    //acquire strings
    cout << "Enter strings(empty line to quit):\n";
    while(getline(cin,temp)&&temp[0]!='\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(),vostr.end(),ShowStr);

    //store in a file
    ofstream fout("strings.dat",ios_base::out|ios_base::binary);
    for_each(vostr.begin(),vostr.end(),Store(fout));

    //recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Couldn't open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin,vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(),vistr.end(), ShowStr);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void GetStrs(std::ifstream &fin,std::vector<std::string> &vec)
{
    using std::string;
    while(fin.peek()!=EOF)
    {
        char len[1];
        string tempStr;
        fin.read(len,sizeof(std::size_t));
        for(int i=0;i<(*len-'0');i++)
        {
            char temp[1];
            fin.read(temp,sizeof(char));
            tempStr.push_back(*temp);
        }
        vec.push_back(tempStr);
    }
}
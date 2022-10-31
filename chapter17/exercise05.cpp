#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

void createList(std::list<std::string> &se, std::ifstream &fin);

int main()
{
    using namespace std;
    list<string> Mat_fri;
    list<string> Pat_fri;
    list<string> MergeTwo;

    ifstream Mat_f,Pat_f;
    ofstream Merge_f;

    Merge_f.open("matnpat.dat");
    if(Merge_f.is_open())
    {
        Mat_f.open("mat.dat");
        if(Mat_f.is_open())
            createList(Mat_fri,Mat_f);
        else
            exit(EXIT_FAILURE);
        Mat_fri.sort();

        Pat_f.open("pat.dat");
        if(Pat_f.is_open())
            createList(Pat_fri,Pat_f);
        else
            exit(EXIT_FAILURE);
        Pat_fri.sort();

        set_union(Mat_fri.begin(),Mat_fri.end(),Pat_fri.begin(),Pat_fri.end(),insert_iterator<list<string>>(MergeTwo,MergeTwo.begin()));
        for(auto & ptr : MergeTwo)
            Merge_f << ptr << endl;
        cout << "Done!"<< endl;
    }
    else
        cout << "Can't open the file.\n";
    return 0;
}

void createList(std::list<std::string> &se,std::ifstream &fin)
{
    std::string name;
    while(getline(fin,name)&&name[0]!='\0')
        se.push_back(name);
}
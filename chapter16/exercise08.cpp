#include <iostream>
#include <list>
#include <algorithm>

void createList(std::list<std::string> &se);
void showList(const std::list<std::string> &se);


class Show
{
public:
    void operator()(const std::string& val)
    {
        std::cout << val << std::endl;
    }
};

int main()
{
    using namespace std;
    list<string> Mat_fri;
    list<string> Pat_fri;
    list<string> MergeTwo;
    std::cout<<"# Input one name in a line #\n";
    cout<<"Mat's friends:\n";
    createList(Mat_fri);
    showList(Mat_fri);
    Mat_fri.sort();
    cout<<"Pat's friends:\n";
    createList(Pat_fri);
    showList(Pat_fri);
    Pat_fri.sort();
    set_union(Mat_fri.begin(),Mat_fri.end(),Pat_fri.begin(),Pat_fri.end(),insert_iterator<list<string>>(MergeTwo,MergeTwo.begin()));
    cout<<"The final list of friends:\n";
    for_each(MergeTwo.begin(),MergeTwo.end(),Show());
    cout << "Done!"<< endl;
    return 0;
}

void createList(std::list<std::string> &se)
{
   using std::cout;
   using std::cin;
   std::string name;
   while(getline(cin,name)&&name[0]!='\0')
       se.push_back(name);
}

void showList(const std::list<std::string> &se)
{
    for(const std::string &item : se)
        std::cout<<item<<std::endl;
    std::cout<<std::endl;
}
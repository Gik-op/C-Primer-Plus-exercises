#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

inline void wrongInput() { std::cin.clear();while(std::cin.get()!='\n') continue;std::cout<<"Wrong input!Again:"; }
inline void eatline() { while(std::cin.get()!='\n') continue;}
vector<int> Lotto(int,int);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    int all,sek;
    std::string choice;
    vector<int> winners;
    while(true)
    {
        cout<<"Please enter the number of the dot:";
        while(!(cin>>all))
            wrongInput();
        cout<<"Please enter the number you want to select:";
        while(!(cin>>sek))
            wrongInput();
        winners = Lotto(all,sek);
        for(int & winner : winners)
            cout<<winner<<" ";
        cout<<endl;
        eatline();
        cout<<"Next game?(y/n):";
        getline(cin,choice);
        if(choice[0]!='y'&&choice[0]!='Y')
            break;
    }
    cout<<"Done.\n";
    return 0;
}

vector<int> Lotto(int all,int seek)
{
    using std::vector;
    vector<int> rand_all,rand_select;
    for(int i=0;i<all;i++)
        rand_all.push_back(i+1);
    random_shuffle(rand_all.begin(),rand_all.end());
    for(int i=0;i<seek;i++)
        rand_select.push_back(rand_all[i]);
    return rand_select;
}
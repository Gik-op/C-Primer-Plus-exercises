#include <iostream>
#include <fstream>

using namespace std;

#define CHAR(X) ((X)>1?"characters":"character")

int main()
{
    int count=0;
    ifstream fin;
    fin.open("song_1.txt");
    while((fin.get())!=EOF)
        count++;
    cout<<"The file has "<<count<<" "<<CHAR(count);
    fin.close();
    return 0;
}

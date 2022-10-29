#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <algorithm>

int main()
{
    using namespace std;
    long size=100000000;
    vector<int> vi0(size);
    srand(time(nullptr));
    for(int &i:vi0)
        i = rand();
    vector<int> vi(vi0);
    list<int> li(size);
    li.assign(vi0.begin(),vi0.end());

    // test 1
    cout << "The result for vector.sort():";
    clock_t start_v = clock();
    std::sort(vi.begin(), vi.end());
    clock_t end_v = clock();
    cout << (double)(end_v-start_v)/CLOCKS_PER_SEC << endl;

    cout << "The result for list.sort():";
    clock_t start_l = clock();
    li.sort();
    clock_t end_l = clock();
    cout << (double)(end_l-start_l)/CLOCKS_PER_SEC << endl;

    // test 2
    li.assign(vi0.begin(),vi0.end());
    cout << "The result for list->vector,vector.sort(),vector->list:";
    clock_t start = clock();
    vi.assign(li.begin(),li.end());
    std::sort(vi.begin(), vi.end());
    li.assign(vi.begin(),vi.end());
    clock_t end = clock();
    cout << (double)(end-start)/CLOCKS_PER_SEC << endl;

    std::cout << "Done!" << std::endl;
    return 0;
}

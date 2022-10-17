#ifndef EXERCISE02_WINE_H
#define EXERCISE02_WINE_H

#include <string>
#include <valarray>
#include "pair.h"

using namespace std;

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine : private PairArray

{
private:
    string label;
    int years;
public:
    Wine();
    Wine(const char *l,int y,const int yr[],const int bot[]);
    Wine(const char *l,int y);
    ~Wine() = default;
    void GetBottles();
    void Show();
    string & Label() { return label;}
    int sum() {return PairArray::second().sum();}
};

#endif //EXERCISE02_WINE_H

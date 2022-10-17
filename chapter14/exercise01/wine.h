#ifndef EXERCISE01_WINE_H
#define EXERCISE01_WINE_H

#include <string>
#include <valarray>
#include "pair.h"

using namespace std;

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine
{
private:
    string label;
    int years;
    PairArray yrs_bots;
public:
    Wine();
    Wine(const char *l,int y,const int yr[],const int bot[]);
    Wine(const char *l,int y);
    ~Wine() = default;
    void GetBottles();
    void Show();
    string & Label() { return label;}
    int sum() {return yrs_bots.second().sum();}
};

#endif //EXERCISE01_WINE_H

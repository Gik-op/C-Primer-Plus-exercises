#ifndef EXERCISE01_GOLF_H
#define EXERCISE01_GOLF_H

const int Len=14;
struct golf{
    char fullname[Len];
    int handicap;
};

void setgolf(golf &g,const char *name,int hc);
int setgolf(golf &g);
void handicap(golf &g,int hc);
void showgolf(const golf &g);

#endif //EXERCISE01_GOLF_H

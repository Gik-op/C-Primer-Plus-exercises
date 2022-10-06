#ifndef EXERCISE07_PLORG_H
#define EXERCISE07_PLORG_H

class Plorg
{
private:
    enum{size=19};
    char name[size];
    int CI;
public:
    Plorg();
    Plorg(char *str,int ci=50);
    ~Plorg();
    void setCI(int ci);
    void showPlorg();
};

#endif //EXERCISE07_PLORG_H

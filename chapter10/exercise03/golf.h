#ifndef EXERCISE03_GOLF_H
#define EXERCISE03_GOLF_H

class GOLF
{
private:
    enum {Len=14};
    char fullname[Len];
    int hand;
public:
    GOLF();
    GOLF(const char *name,int hc);
    ~GOLF();
    int setgolf();
    void handicap(int hc);
    void showgolf() const;

};

#endif //EXERCISE03_GOLF_H

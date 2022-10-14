#ifndef EXERCISE01_CLASSIC_H
#define EXERCISE01_CLASSIC_H

// base class
class Cd
{
private:
    enum{mem=50,size=20};
    char performers[mem];
    char label[size];
    int selections;
    double playtime;
public:
    Cd(char *s1,char *s2,int n,double x);
    Cd(const Cd &d);
    Cd();
    ~Cd();
    virtual void Report() const;  //reports all CD data
    Cd & operator=(const Cd &d);
};

// derived class
class Classic : public Cd
{
private:
    enum{len=20};
    char master[len];
public:
    Classic(char *s1,char *s2,char *s3,int n,double x);
    Classic(const Cd &d,char *s);
    Classic(const Classic &c);
    Classic();
    ~Classic();
    void Report() const override;
    Classic & operator=(const Classic &c);
};

#endif //EXERCISE01_CLASSIC_H

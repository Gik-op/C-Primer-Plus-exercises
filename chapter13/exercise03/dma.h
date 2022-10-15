#ifndef EXERCISE03_DMA_H
#define EXERCISE03_DMA_H

#include <iostream>

class DMA
{
private:
    char * label;
    int rating;
public:
    explicit DMA(const char * l = "null", int r = 0);
    DMA(const DMA & dm);
    virtual ~DMA();
    DMA & operator=(const DMA &dm);
    virtual void View() const =0;
};

//  Base Class Using DMA
class baseDMA : public DMA
{
public:
    explicit baseDMA(const char * l = "null", int r = 0) : DMA(l,r) {}
    baseDMA(const baseDMA & rs) = default;
    baseDMA & operator=(const baseDMA & rs);
    void View() const override;
};

// derived class without DMA
class lacksDMA :public DMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    explicit lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const DMA & dm);
    void View() const override;
};

// derived class with DMA
class hasDMA :public DMA
{
private:
    char * style;
public:
    explicit hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const DMA & dm);
    hasDMA(const hasDMA & hs);
    ~hasDMA() override;
    hasDMA & operator=(const hasDMA & rs);
    void View() const override;
};

#endif //EXERCISE03_DMA_H

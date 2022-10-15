#include "dma.h"
#include <cstring>

// ABC DMA methods
DMA::DMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA &dm)
{
    label = new char[std::strlen(dm.label) + 1];
    std::strcpy(label, dm.label);
    rating = dm.rating;
}

DMA::~DMA()
{
    delete []label;
}

DMA & DMA::operator=(const DMA &dm)
{
    if (this == &dm)
        return *this;
    delete [] label;
    label = new char[std::strlen(dm.label) + 1];
    std::strcpy(label, dm.label);
    rating = dm.rating;
    return *this;
}

void DMA::View() const
{
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

// baseDMA methods

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    DMA::operator=(rs);
    return *this;
}

void baseDMA::View() const
{
    DMA::View();
}

// lacksDMA methods

lacksDMA::lacksDMA(const char * c, const char * l, int r)
        : DMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const DMA & dm)
        : DMA(dm)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
    DMA::View();
    std::cout << "Color: " << color << std::endl;
}

// hasDMA methods

hasDMA::hasDMA(const char * s, const char * l, int r)
        : DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMA & dm)
        : DMA(dm)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
        : DMA(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    DMA::operator=(hs);
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

void hasDMA::View() const
{
    DMA::View();
    std::cout << "Style: " << style << std::endl;
}
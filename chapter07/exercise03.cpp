#include <iostream>

typedef struct {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
}BOX;

void showBox(BOX);
void setBox(BOX *);

int main()
{
    BOX box={"Hello world",24,18,36};
    std::cout << "Hello, let's see the box." << std::endl;
    setBox(&box);
    showBox(box);
    return 0;
}

void showBox(BOX box)
{
    std::cout<<"maker: "<<box.maker<<std::endl;
    std::cout<<"height: "<<box.height<<std::endl;
    std::cout<<"width: "<<box.width<<std::endl;
    std::cout<<"length: "<<box.length<<std::endl;
    std::cout<<"volume: "<<box.volume<<std::endl;
}

void setBox(BOX *box)
{
    box->volume=box->height*box->width*box->length;
}

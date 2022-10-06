#ifndef EXERCISE6_MOVE_H
#define EXERCISE6_MOVE_H

class Move
{
private:
    double x;
    double y;
public:
    Move(double a=0,double b=0);
    ~Move();
    void showMove() const;
    Move add(const Move &m) const;
    void reset(double a=0,double b=0);
};

#endif //EXERCISE6_MOVE_H

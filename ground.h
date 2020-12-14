#ifndef GROUND_H
#define GROUND_H
#include "sprite.h"

class Ground : public Sprite
{
public:
    Ground();
    Ground(int);
    void setOrigin(double x, double y) override;
    void setPosition(double x, double y) override;
    int getHighestY();
    int getLeftX();
    int getRightX();
};

#endif // GROUND_H

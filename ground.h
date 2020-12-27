#ifndef GROUND_H
#define GROUND_H
#include "sprite.h"

class Ground : public Sprite
{
public:
    Ground();
    Ground(int);
    void setPosition(double x, double y) override;
};

#endif // GROUND_H

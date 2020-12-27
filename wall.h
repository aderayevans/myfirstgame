#ifndef WALL_H
#define WALL_H

#include "ground.h"

class Wall : public Ground
{
public:
    Wall();
    void setPosition(double x, double y) override;

};

#endif // WALL_H

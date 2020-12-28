#include "wall.h"

Wall::Wall()
{
    setTexture(":/images/backgrounds/stoneWall.png", 1, 2);
}

void Wall::setPosition(double x, double y)
{
    Sprite::setPosition(x, y);
    Sprite::setHitBox(QRectF(x + 15, y + 30, getWidth() - 15, getHeight()));
}

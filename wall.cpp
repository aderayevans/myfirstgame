#include "wall.h"

Wall::Wall()
{
    setTexture("D://Users//Downloads//ToshizoGameAsset//stoneWall.png", 1, 2);
}

void Wall::setOrigin(double x, double y)
{
    Sprite::setOrigin(x, y);
    Sprite::setLimitArea(x, y, x + getWidth(), y + getHeight());
    Sprite::setHitBox(x + 15, y + 30, x + getWidth() - 15, y + getHeight());
}

void Wall::setPosition(double x, double y)
{
    Sprite::setPosition(x, y);
    Sprite::setLimitArea(x, y, x + getWidth(), y + getHeight());
    Sprite::setHitBox(x + 15, y + 30, x + getWidth() - 15, y + getHeight());
}

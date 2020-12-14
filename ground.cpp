#include "ground.h"
#include <iostream>

Ground::Ground()
{
    setTexture("D://Users//Downloads//ToshizoGameAsset//snowTexture1.png", 1, 2);
}

Ground::Ground(int choice)
{
    switch(choice)
    {
    case 1:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowTexture1.png", 1, 2);
        break;
    case 2:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowTexture2.png", 1, 2);
        break;
    case 3:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowTexture3.png", 1, 2);
        break;
    case 4:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowTexture4.png", 1, 2);
        break;
    case 5:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowMiniTexture1.png", 1, 1);
        break;
    case 6:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowMiniTexture2.png", 1, 1);
        break;
    case 7:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowMiniTexture3.png", 1, 1);
        break;
    case 8:
        setTexture("D://Users//Downloads//ToshizoGameAsset//snowMiniTexture4.png", 1, 1);
        break;
    }
}

void Ground::setOrigin(double x, double y)
{
    Sprite::setOrigin(x, y);
    Sprite::setLimitArea(x, y, x + getWidth(), y + getHeight());
    Sprite::setHitBox(x, y + 15, x + getWidth(), y + getHeight());
}

void Ground::setPosition(double x, double y)
{
    Sprite::setPosition(x, y);
    Sprite::setLimitArea(x, y, x + getWidth(), y + getHeight());
    Sprite::setHitBox(x, y + 15, x + getWidth(), y + getHeight());
}

int Ground::getHighestY()
{
    return getPointHitBox(1).y();
}

int Ground::getLeftX()
{
    return getPointHitBox(1).x();
}

int Ground::getRightX()
{
    return getPointHitBox(4).x();
}

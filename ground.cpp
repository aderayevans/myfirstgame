#include "ground.h"
#include <iostream>

Ground::Ground()
{
    setTexture("D://Games//Toshizo//snowTexture1.png", 1, 2);
}

Ground::Ground(int choice)
{
    switch(choice)
    {
    case 1:
        setTexture("D://Games//Toshizo//snowTexture1.png", 1, 2);
        break;
    case 2:
        setTexture("D://Games//Toshizo//snowTexture2.png", 1, 2);
        break;
    case 3:
        setTexture("D://Games//Toshizo//snowTexture3.png", 1, 2);
        break;
    case 4:
        setTexture("D://Games//Toshizo//snowTexture4.png", 1, 2);
        break;
    case 5:
        setTexture("D://Games//Toshizo//snowMiniTexture1.png", 1, 1);
        break;
    case 6:
        setTexture("D://Games//Toshizo//snowMiniTexture2.png", 1, 1);
        break;
    case 7:
        setTexture("D://Games//Toshizo//snowMiniTexture3.png", 1, 1);
        break;
    case 8:
        setTexture("D://Games//Toshizo//snowMiniTexture4.png", 1, 1);
        break;
    }
}

void Ground::setPosition(double x, double y)
{
    Sprite::setPosition(x, y);
    Sprite::setHitBox(QRectF(x, y + 15, getWidth(), getHeight()));
}

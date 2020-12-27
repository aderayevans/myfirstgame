#include "ground.h"
#include <iostream>

Ground::Ground()
{
    setTexture(":/images/backgrounds/snowTexture1.png", 1, 2);
}

Ground::Ground(int choice)
{
    switch(choice)
    {
    case 1:
        setTexture(":/images/backgrounds/snowTexture1.png", 1, 2);
        break;
    case 2:
        setTexture(":/images/backgrounds/snowTexture2.png", 1, 2);
        break;
    case 3:
        setTexture(":/images/backgrounds/snowTexture3.png", 1, 2);
        break;
    case 4:
        setTexture(":/images/backgrounds/snowTexture4.png", 1, 2);
        break;
    case 5:
        setTexture(":/images/backgrounds/snowMiniTexture1.png", 1, 1);
        break;
    case 6:
        setTexture(":/images/backgrounds/snowMiniTexture2.png", 1, 1);
        break;
    case 7:
        setTexture(":/images/backgrounds/snowMiniTexture3.png", 1, 1);
        break;
    case 8:
        setTexture(":/images/backgrounds/snowMiniTexture4.png", 1, 1);
        break;
    }
}

void Ground::setPosition(double x, double y)
{
    Sprite::setPosition(x, y);
    Sprite::setHitBox(QRectF(x, y + 15, getWidth(), getHeight()));
}

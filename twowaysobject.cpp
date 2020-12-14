#include "twowaysobject.h"

TwoWaysObject::TwoWaysObject()
{
}

void TwoWaysObject::setTexture(const char * xpm, const char * otherXpm, int totalPicture, int scale)
{
    firstSprite.setTexture(xpm, totalPicture, scale);
    secondSprite.setTexture(otherXpm, totalPicture, scale);
}

void TwoWaysObject::setSpeed(double speed)
{
    firstSprite.setSpeed(speed);
    secondSprite.setSpeed(speed);
}

void TwoWaysObject::setOrigin(double x, double y)
{
    firstSprite.setOrigin(x, y);
    secondSprite.setOrigin(x, y);
}

void TwoWaysObject::setPosition(double x, double y)
{
    firstSprite.setPosition(x, y);
    secondSprite.setPosition(x, y);
}

void TwoWaysObject::setLimitArea(double x1, double y1, double x2, double y2)
{
    x2 -= getWidth();
    y1 += getHeight();
    firstSprite.setLimitArea(x1, y1, x2, y2);
    secondSprite.setLimitArea(x1, y1, x2, y2);
}

void TwoWaysObject::setDirection(Direction di)
{
    direct = di;
}

void TwoWaysObject::setClock()
{
    switch (direct)
    {
    case rightLeft:
        if (secondSprite.getPosition().x() <= secondSprite.getLimitArea(1).x())
        {
            setDirection(leftRight);
            break;
        }
        else
        {
            setPosition(secondSprite.getPosition().x() - secondSprite.getSpeed(), secondSprite.getPosition().y());
            break;
        }
    default:
        if (firstSprite.getPosition().x() >= firstSprite.getLimitArea(3).x())
        {
            setDirection(rightLeft);
            break;
        }
        else
        {
            setPosition(firstSprite.getPosition().x() + firstSprite.getSpeed(), firstSprite.getPosition().y());
            break;
        }
    }
}

double TwoWaysObject::getHeight()
{
    return firstSprite.getHeight();
}

double TwoWaysObject::getWidth()
{
    return firstSprite.getWidth();
}

QPointF TwoWaysObject::getLimitArea(int number)
{
    return firstSprite.getLimitArea(number);
}

QRectF TwoWaysObject::getSource()
{
    switch (direct)
    {
    case rightLeft:
        return secondSprite.getSource();
    default:
        return firstSprite.getSource();
    }
}

QRectF TwoWaysObject::getTarget()
{
    switch (direct)
    {
    case rightLeft:
        return secondSprite.getTarget();
    default:
        return firstSprite.getTarget();
    }
}

QPixmap TwoWaysObject::getTexture()
{
    switch (direct)
    {
    case rightLeft:
        return secondSprite.getTexture();
    default:
        return firstSprite.getTexture();
    }
}

#include "sprite.h"

#include <iostream>

Sprite::Sprite()
    : totalPicture(1), clock(0)
{
}

Sprite::Sprite(const QPixmap &pixmap, int totalPicture, int scale)
{
    texture = pixmap;
    texture = texture.scaled(texture.width()/scale, texture.height()/scale);
    width = texture.width() / totalPicture;
    height = texture.height();
    this->totalPicture = totalPicture;
}

Sprite::Sprite(const char * xpm, int totalPicture, int scale)
{
    texture.load(xpm);
    texture = texture.scaled(texture.width()/scale, texture.height()/scale);
    width = texture.width() / totalPicture;
    height = texture.height();
    this->totalPicture = totalPicture;
}

void Sprite::setTexture(const QPixmap &pixmap, int totalPicture, int scale)
{
    texture = pixmap;
    texture = texture.scaled(texture.width()/scale, texture.height()/scale);
    width = texture.width() / totalPicture;
    height = texture.height();
    this->totalPicture = totalPicture;
}

void Sprite::setTexture(const char * xpm, int totalPicture, int scale)
{
    texture.load(xpm);
    texture = texture.scaled(texture.width()/scale, texture.height()/scale);
    width = texture.width() / totalPicture;
    height = texture.height();
    this->totalPicture = totalPicture;
}

void Sprite::setSpeed(double s)
{
    speed = s;
}

void Sprite::setClock(int c)
{
    clock = c;
}

void Sprite::setOrigin(double x, double y)
{
    position = QPointF(x, y);
    setHitBox(x, y, x + width, y + height);
}

void Sprite::setPosition(double x, double y)
{
    position = QPointF(x, y);
    setHitBox(x, y, x + width, y + height);
}

void Sprite::setHitBox(double x1, double y1, double x2, double y2)
{
    pointLeftAbove = QPointF(x1, y1);
    pointLeftBelow = QPointF(x1, y2);
    pointRightAbove = QPointF(x2, y1);
    pointRightBelow = QPointF(x2, y2);
}

void Sprite::setSource(QRectF source)
{
    this->source = source;
}

void Sprite::setTarget(QRectF target)
{
    this->target = target;
}

void Sprite::setLimitArea(double x1, double y1, double x2, double y2)
{
    /*
    1(x1, y1).--------y1--------.(x2, y1)3
            |                  |
            |                  |
            |                  |
    2(x1, y2).--------y2--------.(x2, y2)4
    */
    limitLeftAbove = QPointF(x1, y1);
    limitLeftBelow = QPointF(x1, y2);
    limitRightAbove = QPointF(x2, y1);
    limitRightBelow = QPointF(x2, y2);
}

void Sprite::setVisionArea(double x1, double y1, double x2, double y2)
{
    /*
    1(x1, y1).--------y1--------.(x2, y1)3
            |                  |
            |                  |
            |                  |
    2(x1, y2).--------y2--------.(x2, y2)4
    */
    visionLeftAbove = QPointF(x1, y1);
    visionLeftBelow = QPointF(x1, y2);
    visionRightAbove = QPointF(x2, y1);
    visionRightBelow = QPointF(x2, y2);
}

QPointF Sprite::getPointHitBox(int number)
{
    switch(number)
    {
    case 1:
        return pointLeftAbove;
        break;
    case 2:
        return pointLeftBelow;
        break;
    case 3:
        return pointRightAbove;
        break;
    default:    //case 4:
        return pointRightBelow;
        break;
    }
}

QPointF Sprite::getVisionArea(int number)
{
    switch(number)
    {
    case 1:
        return visionLeftAbove;
        break;
    case 2:
        return visionLeftBelow;
        break;
    case 3:
        return visionRightAbove;
        break;
    default:    //case 4:
        return visionRightBelow;
        break;
    }
}

QPointF Sprite::getLimitArea(int number)
{
    switch(number)
    {
    case 1:
        return limitLeftAbove;
        break;
    case 2:
        return limitLeftBelow;
        break;
    case 3:
        return limitRightAbove;
        break;
    default:    //case 4:
        return limitRightBelow;
        break;
    }
}

int Sprite::getTotalPicture()
{
    return totalPicture;
}
double Sprite::getSpeed()
{
    return speed;
}

double Sprite::getHeight()
{
    return height;
}

double Sprite::getWidth()
{
    return width;
}

QPointF Sprite::getPosition()
{
    return position;
}

QRectF Sprite::getSource()
{

    return QRectF(width*(double)(clock % (totalPicture)), 0, width, height);
}

QRectF Sprite::getTarget()
{
    return QRectF(position.x(), position.y(), width, height);
}

QPixmap Sprite::getTexture()
{
    return texture;
}

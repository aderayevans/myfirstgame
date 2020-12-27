#include "sprite.h"
#include <QDebug>
#include <iostream>

Sprite::Sprite()
    : totalPicture(1), clock(0)
{
}

Sprite::~Sprite(){}

void Sprite::operator = (const Sprite &A)
{
    texture = A.texture;
    width = A.width;
    height = A.height;
    totalPicture = A.totalPicture;
    position = A.position;
    hitBox = A.hitBox;
    limitArea = A.limitArea;
    visionArea = A.visionArea;
    attackArea = A.attackArea;
    speed = A.speed;
    duration = A.duration;
    direct = A.direct;
    frame = A.frame;
    clock = A.clock;
    lifetime = A.lifetime;
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

void Sprite::setFrame(int f)
{
    frame = f;
}

void Sprite::setClock()
{
    if (!stop)
    {
        if (clock > duration)
        {
            frame++;
            clock = 0;
        }
        if (frame == totalPicture)
        {
            frame = 0;
        }
        clock++;
    }
    lifetime++;
}

void Sprite::setDuration(int d)
{
    duration = d;
}

void Sprite::setDirection(Direction d)
{
    direct = d;
}

void Sprite::setPosition(double x, double y)
{
    position = QPointF(x, y);
    setHitBox(QRectF(x, y, width, height));
}

void Sprite::setSource(QRectF source)
{
    this->source = source;
}

void Sprite::setTarget(QRectF target)
{
    this->target = target;
}

void Sprite::setHitBox(QRectF q)
{
    hitBox = q;
}

void Sprite::setLimitArea(QRectF q)
{
    limitArea = q;
}

void Sprite::setVisionArea(QRectF q)
{
    visionArea = q;
}

void Sprite::setAttackArea(QRectF q)
{
    attackArea = q;
}

QRectF Sprite::getHitBox()
{
    return hitBox;
}

QRectF Sprite::getVisionArea()
{
    return visionArea;
}

QRectF Sprite::getLimitArea()
{
    return limitArea;
}

QRectF Sprite::getAttackArea()
{
    return attackArea;
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

Direction Sprite::getDirection()
{
    return direct;
}

int Sprite::getDuration()
{
    return duration;
}

int Sprite::getFrame()
{
    return frame;
}

int Sprite::getLifetime()
{
    return lifetime;
}

void Sprite::stopFrame()
{
    stop = true;
}

void Sprite::goOn()
{
    stop = false;
}

QRectF Sprite::getTarget()
{
    return QRectF(position.x(), position.y(), width, height);
}

QPixmap Sprite::getTexture()
{
    return texture;
}

QRectF Sprite::getSource()
{
    return QRectF(width*(double)(frame), 0, width, height);
}

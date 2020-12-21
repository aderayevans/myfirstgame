#include "kong.h"
#include <iostream>

Kong::Kong()
{
    setState(Walking);
    setFullHealth(1000);
    setHealth(getFullHealth());
    setTexture();
}

void Kong::setTexture()
{
    walkSprite.setTexture("D://Games//Toshizo//implementRunningKong.png", 6, scale);
    walkSprite.setSpeed(speed);                                                       // for moving
    attackSprite.setTexture("D://Games//Toshizo//implementAttackKong.png", 6, scale);

    walkSprite2.setTexture("D://Games//Toshizo//flippedRunningKong.png", 6, scale);
    walkSprite2.setSpeed(speed);                                                       // for moving
    attackSprite2.setTexture("D://Games//Toshizo//flippedAttackKong.png", 6, scale);
}

void Kong::setPosition(double x, double y)
{
    NPC::setPosition(x, y);
    setVisionArea(x - 200, y - 200, x + 200, y + 200);
    walkSprite.setPosition(x, y);
    attackSprite.setPosition(x, y);

    walkSprite2.setPosition(x, y);
    attackSprite2.setPosition(x, y);

    setHitBox(x, y, x + getWidth(), y + getHeight());
}

void Kong::setLimitArea(double x1, double y1, double x2, double y2)
{
    walkSprite.setLimitArea(x1, y1, x2, y2);
}

void Kong::setVisionArea(double x1, double y1, double x2, double y2)
{
    x2 += getWidth();
    y2 += getHeight();
    walkSprite.setVisionArea(x1, y1, x2, y2);
}

void Kong::setHitBox(double x1, double y1, double x2, double y2)
{
    walkSprite.setHitBox(x1, y1, x2, y2);
}

QPointF Kong::getLimitArea(int number)
{
    return walkSprite.getLimitArea(number);
}

QPointF Kong::getVisionArea(int number)
{
    return walkSprite.getVisionArea(number);
}

QPointF Kong::getPointHitBox(int number)
{
    return walkSprite.getPointHitBox(number);
}

double Kong::getHeight()
{
    return walkSprite.getHeight();
}

double Kong::getWidth()
{
    return walkSprite.getWidth() - 50;
}

double Kong::getSpeed()
{
    switch (getState()) {
    default:    //case Run:
        return walkSprite.getSpeed();;
        break;
    }
}

void Kong::setClock()
{
    clock++;
    switch (getState())
    {
    case Walking:

        if (walkClock > walkSlowTime)
        {
            walkPicture++;
            walkClock = 0;
        }
        walkClock++;
        switch (getDirection()) {
        case rightLeft:
            if (getPosition().x() < getLimitArea(1).x())
            {
                setPosition(getLimitArea(1).x(), getPosition().y());
                setDirection(leftRight);
            }
            else
            {
                setPosition(getPosition().x() - speed, getPosition().y());
            }
            walkSprite2.setClock(walkPicture);
            break;
        default:    //case leftRight:
            if (getPosition().x() + getWidth() > getLimitArea(3).x())
            {
                setPosition(getLimitArea(3).x() - getWidth(), getPosition().y());
                setDirection(rightLeft);
            }
            else
            {
                setPosition(getPosition().x() + speed, getPosition().y());
            }
            walkSprite.setClock(walkPicture);
            break;
        }
        break;
    case Attacking:
        switch (getDirection())
        {
        case rightLeft:
            attackSprite2.setClock(clock);
            break;
        default:    //case leftRight:
            attackSprite.setClock(clock);
            break;
        }
        break;
    }
}

QRectF Kong::getTarget()
{
    switch (getState()) {
    case Walking:
        switch (getDirection()) {
        case rightLeft:
            return walkSprite2.getTarget();
            break;
        default:    //case leftRight:
            return walkSprite.getTarget();
            break;
        }
    case Attacking:
        switch (getDirection()) {
        case rightLeft:
            return attackSprite2.getTarget();
            break;
        default:    //case leftRight:
            return attackSprite.getTarget();
            break;
        }
    }
}

QRectF Kong::getSource()
{
    switch (getState()) {
    case Walking:
        switch (getDirection()) {
        case rightLeft:
            return walkSprite2.getSource();
            break;
        default:    //case leftRight:
            return walkSprite.getSource();
            break;
        }
    case Attacking:
        switch (getDirection()) {
        case rightLeft:
            return attackSprite2.getSource();
            break;
        default:    //case leftRight:
            return attackSprite.getSource();
            break;
        }
    }
}

QPixmap Kong::getTexture()
{
    switch (getState()) {
    case Walking:
        switch (getDirection()) {
        case rightLeft:
            return walkSprite2.getTexture();
            break;
        default:    //case leftRight:
            return walkSprite.getTexture();
            break;
        }
    case Attacking:
        switch (getDirection()) {
        case rightLeft:
            return attackSprite2.getTexture();
            break;
        default:    //case leftRight:
            return attackSprite.getTexture();
            break;
        }
    }
}

#include "wraith.h"
#include <iostream>

Wraith::Wraith()
{
    setState(Walking);
    setDirection(leftRight);
    setFullHealth(1000);
    setHealth(getFullHealth());
    setTexture();
}

void Wraith::setTexture()
{
    walkSprite.setTexture("D://Games//Toshizo//Wraith_Moving_Forward.png", 18, scale);
    walkSprite.setSpeed(speed);                                                       // for moving
    idleSprite.setTexture("D://Games//Toshizo//implementAttackingWraith.png", 2, scale);
    castingSprite.setTexture("D://Games//Toshizo//Wraith_Casting_Spells.png", 18, scale);

    walkSprite2.setTexture("D://Games//Toshizo//Wraith_Moving_Forward_2.png", 1, scale);
    walkSprite2.setSpeed(speed);                                                       // for moving
    idleSprite2.setTexture("D://Games//Toshizo//implementAttackingWraith.png", 2, scale);
    castingSprite2.setTexture("D://Games//Toshizo//Wraith_Casting_Spells_2.png", 18, scale);
}

void Wraith::setPosition(double x, double y)
{
    NPC::setPosition(x, y);
    setVisionArea(x - 200, y - 200, x + 200, y + 200);
    walkSprite.setPosition(x, y);
    castingSprite.setPosition(x, y);
    idleSprite.setPosition(x, y);

    walkSprite2.setPosition(x, y);
    castingSprite2.setPosition(x, y);
    idleSprite2.setPosition(x, y);

    setHitBox(x, y, x + getWidth(), y + getHeight());
}

void Wraith::setLimitArea(double x1, double y1, double x2, double y2)
{
    walkSprite.setLimitArea(x1, y1, x2, y2);
}

void Wraith::setVisionArea(double x1, double y1, double x2, double y2)
{
    x2 += getWidth();
    y2 += getHeight();
    walkSprite.setVisionArea(x1, y1, x2, y2);
}

void Wraith::setHitBox(double x1, double y1, double x2, double y2)
{
    walkSprite.setHitBox(x1, y1, x2, y2);
}

QPointF Wraith::getLimitArea(int number)
{
    return walkSprite.getLimitArea(number);
}

QPointF Wraith::getVisionArea(int number)
{
    return walkSprite.getVisionArea(number);
}

QPointF Wraith::getPointHitBox(int number)
{
    return walkSprite.getPointHitBox(number);
}

double Wraith::getHeight()
{
    return walkSprite.getHeight();
}

double Wraith::getWidth()
{
    return walkSprite.getWidth();
}

double Wraith::getSpeed()
{
    switch (getState()) {
    default:    //case Run:
        return walkSprite.getSpeed();;
        break;
    }
}

void Wraith::setClock()
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
    case Casting:
    {
        if (castingClock > castingSlowTime)
        {
            castingPicture++;
        }
        castingClock++;
        switch (getDirection())
        {
        case rightLeft:
            castingSprite2.setClock(castingPicture);
            break;
        default:    //case leftRight:
            castingSprite.setClock(castingPicture);
            break;
        }
        break;
    }
    case Idle:
        switch (getDirection())
        {
        case rightLeft:
            idleSprite2.setClock(clock);
            break;
        default:    //case leftRight:
            idleSprite.setClock(clock);
            break;
        }
        break;
    }
}

QRectF Wraith::getTarget()
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
    case Casting:
        switch (getDirection()) {
        case rightLeft:
            return castingSprite2.getTarget();
            break;
        default:    //case leftRight:
            return castingSprite.getTarget();
            break;
        }
    //default:
    case Idle:
        switch (getDirection()) {
        case rightLeft:
            return idleSprite2.getTarget();
            break;
        default:    //case leftRight:
            return idleSprite.getTarget();
            break;
        }
    }
}

QRectF Wraith::getSource()
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
    case Casting:
        switch (getDirection()) {
        case rightLeft:
            return castingSprite2.getSource();
            break;
        default:    //case leftRight:
            return castingSprite.getSource();
            break;
        }
    //default:
    case Idle:
        switch (getDirection()) {
        case rightLeft:
            return idleSprite2.getSource();
            break;
        default:    //case leftRight:
            return idleSprite.getSource();
            break;
        }
    }
}

QPixmap Wraith::getTexture()
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
    case Casting:
        switch (getDirection()) {
        case rightLeft:
            return castingSprite2.getTexture();
            break;
        default:    //case leftRight:
            return castingSprite.getTexture();
            break;
        }
    //default:
    case Idle:
        switch (getDirection()) {
        case rightLeft:
            return idleSprite2.getTexture();
            break;
        default:    //case leftRight:
            return idleSprite.getTexture();
            break;
        }
    }
}

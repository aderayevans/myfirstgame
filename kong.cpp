#include "kong.h"
#include <iostream>
#include <QDebug>

Kong::Kong()
{
    setState(Walking);
    setFullHealth(1000);
    setHealth(getFullHealth());
    setTexture();
}

void Kong::setTexture()
{
    walkSprite.setTexture(":/images/npcs/implementRunningKong.png", 6, scale);
    walkSprite.setSpeed(speed);                                                       // for moving
    attackSprite.setTexture(":/images/npcs/implementAttackKong.png", 6, scale);

    walkSprite2.setTexture(":/images/npcs/flippedRunningKong.png", 6, scale);
    walkSprite2.setSpeed(speed);                                                       // for moving
    attackSprite2.setTexture(":/images/npcs/flippedAttackKong.png", 6, scale);
}

void Kong::setPosition(double x, double y)
{
    NPC::setPosition(x, y);
    if (getDirection() == leftRight)
    {
        setVisionArea(QRectF(x, y, 1000, getHeight()));
        setAttackArea(QRect(x, y, getWidth() + 70, getHeight()));
    }
    else
    {
        setVisionArea(QRectF(x + getWidth() - 1000, y, 1000, getHeight()));
        setAttackArea(QRect(x - 70, y, getWidth() + 70, getHeight()));
    }
    walkSprite.setPosition(x - 5, y - 5);
    attackSprite.setPosition(x - 30, y - 30);

    walkSprite2.setPosition(x - 25, y - 5);
    attackSprite2.setPosition(x - 60, y - 30);

    setHitBox(QRectF(x, y, getWidth(), getHeight()));
}

void Kong::setLimitArea(QRectF q)
{
    walkSprite.setLimitArea(q);
}

void Kong::setVisionArea(QRectF q)
{
    walkSprite.setVisionArea(q);
}

void Kong::setAttackArea(QRectF q)
{
    walkSprite.setAttackArea(q);
}

void Kong::setHitBox(QRectF q)
{
    walkSprite.setHitBox(q);
}

QRectF Kong::getLimitArea()
{
    return walkSprite.getLimitArea();
}

QRectF Kong::getVisionArea()
{
    return walkSprite.getVisionArea();
}

QRectF Kong::getAttackArea()
{
    return walkSprite.getAttackArea();
}

QRectF Kong::getHitBox()
{
    return walkSprite.getHitBox();
}

double Kong::getHeight()
{
    return walkSprite.getHeight();
}

double Kong::getWidth()
{
    return walkSprite.getWidth() - 50;
}

void Kong::setSpeed(double s)
{
    walkSprite.setSpeed(s);
}

void Kong::isSeeingSomethingSus()
{
    setSpeed(maxSpeed);
    seeingSus = true;
}

void Kong::isBeingAttacked(double damage)
{
    setHealth(getLeftHealth() - damage);
    caution = true;
}

double Kong::getSpeed()
{
    switch (getState()) {
    default:    //case Run:
        return walkSprite.getSpeed();
        break;
    }
}

double Kong::getDamage()
{
    return damage;
}

void Kong::setClock()
{
    clock++;
    switch (getState())
    {
    case Walking:
        booleanNormalAttack = false;
        if (walkClock > walkSlowTime)
        {
            if (caution && walkPicture == 2 && !seeingSus)
            {
                if (getDirection() == leftRight)
                {
                    setDirection(rightLeft);
                }
                else
                {
                    setDirection(leftRight);
                }
                caution--;
            }
            walkPicture++;
            walkClock = 0;
        }
        if (walkPicture == walkSprite.getTotalPicture())
        {
            walkPicture = 0;
        }
        walkClock++;
        switch (getDirection()) {
        case rightLeft:
            if (getPosition().x() < getLimitArea().topLeft().x())
            {
                setPosition(getLimitArea().topLeft().x(), getPosition().y());
                setDirection(leftRight);
            }
            else
            {
                setPosition(getPosition().x() - getSpeed(), getPosition().y());
            }
            walkSprite2.setFrame(walkPicture);
            break;
        default:    //case leftRight:
            if (getPosition().x() + getWidth() > getLimitArea().topRight().x())
            {
                setPosition(getLimitArea().topRight().x() - getWidth(), getPosition().y());
                setDirection(rightLeft);
            }
            else
            {
                setPosition(getPosition().x() + getSpeed(), getPosition().y());
            }
            walkSprite.setFrame(walkPicture);
            break;
        }
        walkSprite.setSpeed(speed);
        seeingSus = false;
        break;
    case Attacking:
        walkPicture = 0;
        caution = false;
        if (attackClock > attackSlowTime)
        {
            attackPicture++;
            attackClock = 0;
        }
        if (attackPicture == attackSprite.getTotalPicture())
        {
            attackPicture = 0;
            setState(Walking);
        }
        attackClock++;
        switch (getDirection())
        {
        case rightLeft:
            attackSprite2.setFrame(attackPicture);
            break;
        default:    //case leftRight:
            attackSprite.setFrame(attackPicture);
            break;
        }
        if (attackPicture > 1 && attackPicture < 5)
        {
            booleanNormalAttack = true;
        }
        else
        {
            booleanNormalAttack = false;
        }
        caution = maxCautionTime;
        seeingSus = false;
        break;
    }
}

std::vector<QRectF> Kong::getRedCollisions()
{
    std::vector<QRectF> temps;
    temps.push_back(getHitBox());
    if (booleanNormalAttack)
    {
        temps.push_back(getAttackArea());
    }
    return temps;
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

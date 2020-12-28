#include "wraith.h"
#include <iostream>

Wraith::Wraith()
{
    setState(Walking);
    setDirection(leftRight);
    setFullHealth(500);
    setHealth(getFullHealth());
    setTexture();
    setName("Poor soul");
    dialog.append("Stop hitting me T.T");
}

bool Wraith::isAlly()
{
    return false;
}

void Wraith::setTexture()
{
    walkSprite.setTexture(":/images/npcs/Wraith_Moving_Forward.png", 5, scale);
    walkSprite.setSpeed(speed);                                                       // for moving
    idleSprite.setTexture(":/images/npcs/Wraith_Idle.png", 4, scale);
    hurtSprite.setTexture(":/images/npcs/Wraith_Hurt.png", 4, scale);
    attackingSprite.setTexture(":/images/npcs/Wraith_Casting_Spells.png", 18, scale);

    walkSprite2.setTexture(":/images/npcs/Wraith_Moving_Forward_2.png", 5, scale);
    walkSprite2.setSpeed(speed);                                                       // for moving
    idleSprite2.setTexture(":/images/npcs/Wraith_Idle_2.png", 4, scale);
    hurtSprite2.setTexture(":/images/npcs/Wraith_Hurt_2.png", 4, scale);
    attackingSprite2.setTexture(":/images/npcs/Wraith_Casting_Spells_2.png", 18, scale);
}

void Wraith::setPosition(double x, double y)
{
    NPC::setPosition(x, y);
    if (getDirection() == leftRight)
    {
        //setVisionArea(QRectF(x, 0, 1000, 800));
        //setAttackArea(QRect(x, y - 200, getWidth() + 800, 800));
        setVisionArea(QRectF(0, 0, 0, 0));
        setAttackArea(QRectF(0, 0, 0, 0));
    }
    else
    {
        //setVisionArea(QRectF(x + getWidth() - 1000, 0, 1000, 800));
        //setAttackArea(QRect(x - 800, y - 200, getWidth() + 800, 800));
        setVisionArea(QRectF(0, 0, 0, 0));
        setAttackArea(QRectF(0, 0, 0, 0));
    }
    walkSprite.setPosition(x, y);
    attackingSprite.setPosition(x, y);
    hurtSprite.setPosition(x, y);
    idleSprite.setPosition(x, y);

    walkSprite2.setPosition(x, y);
    attackingSprite2.setPosition(x, y);
    hurtSprite2.setPosition(x, y);
    idleSprite2.setPosition(x, y);

    setHitBox(QRectF(x, y, getWidth(), getHeight()));
}

void Wraith::setLimitArea(QRectF q)
{
    walkSprite.setLimitArea(q);
}

void Wraith::setVisionArea(QRectF q)
{
    walkSprite.setVisionArea(q);
}

void Wraith::setAttackArea(QRectF q)
{
    walkSprite.setAttackArea(q);
}

void Wraith::setHitBox(QRectF q)
{
    walkSprite.setHitBox(q);
}

QRectF Wraith::getLimitArea()
{
    return walkSprite.getLimitArea();
}

QRectF Wraith::getVisionArea()
{
    return walkSprite.getVisionArea();
}

QRectF Wraith::getAttackArea()
{
    return walkSprite.getAttackArea();
}

QRectF Wraith::getHitBox()
{
    return walkSprite.getHitBox();
}

double Wraith::getHeight()
{
    return walkSprite.getHeight();
}

double Wraith::getWidth()
{
    return walkSprite.getWidth();
}

void Wraith::setSpeed(double s)
{
    walkSprite.setSpeed(s);
}

void Wraith::isSeeingSomethingSus()
{
    walkSprite.setSpeed(maxSpeed);
}

void Wraith::isBeingAttacked(double damage)
{
    setHealth(getLeftHealth() - damage);
    setState(Hurt);
    caution = true;
}

bool Wraith::isDisappeared()
{
    return true;
}

double Wraith::getSpeed()
{
    switch (getState()) {
    default:    //case Run:
        return walkSprite.getSpeed();;
        break;
    }
}

double Wraith::getDamage()
{
    return damage;
}

void Wraith::setClock()
{
    switch (getState())
    {
    case Walking:
        if (walkClock > walkSlowTime)
        {
            walkFrame++;
            walkClock = 0;
        }
        if (walkFrame == walkSprite.getTotalFrame())
        {
            walkFrame = 0;
        }
        walkClock++;
        switch (getDirection()) {
        case rightLeft:
            if (getPosition().x() < getLimitArea().topLeft().x())
            {
                setState(Idle);
                setPosition(getLimitArea().topLeft().x(), getPosition().y());
            }
            else
            {
                setPosition(getPosition().x() - getSpeed(), getPosition().y());
            }
            walkSprite2.setFrame(walkFrame);
            break;
        default:    //case leftRight:
            if (getPosition().x() + getWidth() > getLimitArea().topRight().x())
            {
                setState(Idle);
                setPosition(getLimitArea().topRight().x() - getWidth(), getPosition().y());
            }
            else
            {
                setPosition(getPosition().x() + getSpeed(), getPosition().y());
            }
            walkSprite.setFrame(walkFrame);
            break;
        }
        walkSprite.setSpeed(speed);
        break;
    case Attacking:
    {
        if (attackClock > attackSlowTime)
        {
            attackFrame++;
            attackClock = 0;
        }
        if (attackFrame >= attackingSprite.getTotalFrame())
        {
            attackFrame = 0;
            if (attackingSkillTime > maxAttackingSkillTime)
            {
                setState(Walking);
            }
            attackingSkillTime++;
        }
        attackClock++;
        switch (getDirection())
        {
        case rightLeft:
            attackingSprite2.setFrame(attackFrame);
            break;
        default:    //case leftRight:
            attackingSprite.setFrame(attackFrame);
            break;
        }
        break;
    }
    case Idle:
        if (idleClock > idleSlowTime)
        {
            idleFrame++;
            idleClock = 0;
        }
        if (idleFrame == idleSprite.getTotalFrame())
        {
            idleFrame = 0;
        }
        idleClock++;
        idleTime++;
        switch (getDirection())
        {
        case rightLeft:
            if (idleTime > idleMaxTime)
            {
                idleTime = 0;
                setDirection(leftRight);
                setState(Walking);
            }
            idleSprite2.setFrame(idleFrame);
            break;
        default:    //case leftRight:
            if (idleTime > idleMaxTime)
            {
                idleTime = 0;
                setDirection(rightLeft);
                setState(Walking);
            }
            idleSprite.setFrame(idleFrame);
            break;
        }
        break;
    case Hurt:
        if (hurtClock > hurtSlowTime)
        {
            hurtFrame++;
            hurtClock = 0;
        }
        if (hurtFrame == hurtSprite.getTotalFrame())
        {
            hurtFrame = 0;
            setState(Walking);
        }
        hurtClock++;
        switch (getDirection())
        {
        case rightLeft:
            hurtSprite2.setFrame(hurtFrame);
            break;
        default:    //case leftRight:
            hurtSprite.setFrame(hurtFrame);
            break;
        }
        break;
    }
}

std::vector<QRectF> Wraith::getRedCollisions()
{
    std::vector<QRectF> temps;
    temps.push_back(getHitBox());
    if (booleanNormalAttack)
    {
        //temps.push_back(getAttackArea());
    }
    return temps;
}

Sprite Wraith::getSprite()
{
    switch (getState()) {
    case Walking:
        switch (getDirection()) {
        case rightLeft:
            return walkSprite2;
            break;
        default:    //case leftRight:
            return walkSprite;
            break;
        }
    case Attacking:
        switch (getDirection()) {
        case rightLeft:
            return attackingSprite2;
            break;
        default:    //case leftRight:
            return attackingSprite;
            break;
        }
    //default:
    case Idle:
        switch (getDirection()) {
        case rightLeft:
            return idleSprite2;
            break;
        default:    //case leftRight:
            return idleSprite;
            break;
        }
    case Hurt:
        switch (getDirection()) {
        case rightLeft:
            return hurtSprite2;
            break;
        default:    //case leftRight:
            return hurtSprite;
            break;
        }
    }
}

bool Wraith::isSpeaking()
{
    return caution;
}
QString Wraith::getDialog()
{
    return dialog;
}

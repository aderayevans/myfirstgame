#include "ally.h"
#include <QDebug>

Ally::Ally()
{
    setState(Idle);
    setFullHealth(1000);
    setHealth(0);
    setTexture();
    dialog.append("Hello");
}

Ally::Ally(int choice)
{
    setState(Idle);
    setFullHealth(1000);
    switch (choice)
    {
    case 1:
    {
        setName("???");
        setHealth(0);
        idleSprite.setTexture(":/images/npcs/idlePinkSamurai.png", 1, scale);
        sprite.setTexture(":/images/npcs/pinkSamurai.png", 3, scale);
        dialog.append("Help me, I can't breath");
        longDialog1.append("Thanks for saving my life");
        longDialog2.append("... oh i got to go, my brother is waiting, see ya");
        break;
    }
    case 2:
    {
        setName("???");
        setHealth(300);
        idleSprite.setTexture(":/images/npcs/idleBlueSamurai.png", 2, scale);
        sprite.setTexture(":/images/npcs/blueSamurai.png", 3, scale);
        dialog.append("Such a beautiful place");
        longDialog1.append("Stop right there young boy, this island is full of beast");
        longDialog2.append("Haha want to be a samurai, you look weaker than you thought");
        break;
    }
    case 3:
    {
        setName("???");
        setHealth(300);
        idleSprite.setTexture(":/images/npcs/idleRedSamurai.png", 2, scale);
        sprite.setTexture(":/images/npcs/redSamurai.png", 3, scale);
        dialog.append("...");
        longDialog1.append("...");
        longDialog2.append("...");
        break;
    }
    }
}

void Ally::setTexture()
{
    idleSprite.setTexture("D://Games//Toshizo//pinkSamurai.png", 3, scale);
    sprite.setTexture("D://Games//Toshizo//pinkSamurai.png", 3, scale);
}

bool Ally::isAlly()
{
    return true;
}

void Ally::setPosition(double x, double y)
{
    NPC::setPosition(x, y);
    sprite.setPosition(x, y);
    idleSprite.setPosition(x, y);
    setHitBox(QRectF(x + 50, y + 30, getWidth(), getHeight()));
    setVisionArea(QRectF(x, y, getWidth(), getHeight()));
    setAttackArea(QRectF(x, y, getWidth(), getHeight()));
}

void Ally::setHitBox(QRectF r)
{
    sprite.setHitBox(r);
}

void Ally::setClock()
{
    switch(getState())
    {
    case Idle:
        speak = true;
        if (idleClock > idleSlowTime)
        {
            idleSprite.setClock();
            idleClock = 0;
        }
        idleClock++;
        break;
    case Talking:
        speak = false;
        setHealth(getFullHealth());
        if (talkingClock > talkingSlowTime)
        {
            talkingFrame = 1 - talkingFrame;
            talkingClock = 0;
        }
        if (talkingTime > talkingMaxTime)
        {
            setState(Disappear);
        }
        talkingClock++;
        talkingTime++;
        sprite.setFrame(talkingFrame);
        break;
    case Disappear:
        disappearClock++;
        sprite.setFrame(2);
        break;
    }
}

bool Ally::isDisappeared()
{
    return disappearClock == disappearTime;
}

QRectF Ally::getHitBox()
{
    return sprite.getHitBox();
}

Sprite Ally::getSprite()
{
    switch (getState())
    {
    case Idle:
        return idleSprite;
    default:
        return sprite;
    }
    return sprite;
}

double Ally::getWidth()
{
    return sprite.getWidth()/2;
}

double Ally::getHeight()
{
    return sprite.getHeight();
}

void Ally::setLimitArea(QRectF q)
{
    sprite.setLimitArea(q);
}

void Ally::setVisionArea(QRectF q)
{
    sprite.setVisionArea(q);
}

void Ally::setAttackArea(QRectF q)
{
    sprite.setAttackArea(q);
}

QRectF Ally::getLimitArea()
{
    return sprite.getLimitArea();
}

QRectF Ally::getVisionArea()
{
    return sprite.getVisionArea();
}

QRectF Ally::getAttackArea()
{
    return sprite.getAttackArea();
}

void Ally::setSpeed(double s)
{
    sprite.setSpeed(s);
}

void Ally::isSeeingSomethingSus()
{
    if (getState() == Disappear);
    else setState(Talking);
}

void Ally::isBeingAttacked(double damage)
{
}

double Ally::getSpeed()
{
    sprite.getSpeed();
}

double Ally::getDamage()
{
    return 0;
}

std::vector<QRectF> Ally::getRedCollisions()
{
    std::vector<QRectF> temps;
    return temps;
}

bool Ally::isSpeaking()
{
    return speak;
}
QString Ally::getDialog()
{
    return dialog;
}

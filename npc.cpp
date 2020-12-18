#include "npc.h"
#include <iostream>

NPC::NPC()
{
    setTexture();
}

void NPC::setDirection(Direction direct)
{
    this->direct = direct;
}

void NPC::setTexture()
{
    walkSprite.setTexture("D://Users//Downloads//NPCGameAsset//implementRunningNPC.png", 5, scale);
    walkSprite.setSpeed(speed);                                                       // for moving
    idleSprite.setTexture("D://Users//Downloads//NPCGameAsset//implementAttackingNPC.png", 2, scale);
    castingSprite.setTexture("D://Games//Toshizo//Wraith_Casting_Spells.png", 18, scale);

    walkSprite2.setTexture("D://Users//Downloads//NPCGameAsset//implementRunningNPC.png", 5, scale);
    walkSprite2.setSpeed(speed);                                                       // for moving
    idleSprite2.setTexture("D://Users//Downloads//NPCGameAsset//implementAttackingNPC.png", 2, scale);
    castingSprite2.setTexture("D://Games//Toshizo//Wraith_Casting_Spells_2.png", 18, scale);
}

void NPC::setState(NPC_State s)
{
    state = s;
}

void NPC::setPosition(double x, double y)
{
    position = QPointF(x, y);
    walkSprite.setPosition(x, y);
    castingSprite.setPosition(x, y);
    idleSprite.setPosition(x, y);

    walkSprite2.setPosition(x, y);
    castingSprite2.setPosition(x, y);
    idleSprite2.setPosition(2, y);

    setHitBox(x, y, x + getWidth(), y + getHeight());
}

void NPC::setOrigin(double x, double y)
{
    setPosition(x, y);
}

void NPC::setLimitArea(double x1, double y1, double x2, double y2)
{
    x2 -= getWidth();
    y1 += getHeight();
    walkSprite.setLimitArea(x1, y1, x2, y2);
}

void NPC::setHitBox(double x1, double y1, double x2, double y2)
{
    walkSprite.setHitBox(x1, y1, x2, y2);
}

QPointF NPC::getLimitArea(int number)
{
    return walkSprite.getLimitArea(number);
}

QPointF NPC::getPointHitBox(int number)
{
    return walkSprite.getPointHitBox(number);
}

NPC_State NPC::getState()
{
    return state;
}

double NPC::getHeight()
{
    return walkSprite.getHeight();
}

double NPC::getWidth()
{
    return walkSprite.getWidth() - 50;
}

double NPC::getSpeed()
{
    switch (state) {
    default:    //case Run:
        return walkSprite.getSpeed();;
        break;
    }
}

void NPC::setClock()
{
    clock++;
    switch (state)
    {
    case Walking:
        //runTime++;
        switch (direct) {
        case rightLeft:
            walkSprite2.setClock(clock);
            break;
        default:    //case leftRight:
            walkSprite.setClock(clock);
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
        switch (direct)
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
        switch (direct)
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

QPointF NPC::getPosition()
{
    return position;
}

QPointF NPC::getLowestPoint()
{
    return QPointF(position.x() + getWidth()/2, position.y() + getHeight());
}

int NPC::getFullHealth()
{
    return fullHealth;
}
int NPC::getLeftHealth()
{
    return leftHealth;
}
QRectF NPC::getTarget()
{
    switch (state) {
    case Walking:
        switch (direct) {
        case rightLeft:
            return walkSprite2.getTarget();
            break;
        default:    //case leftRight:
            return walkSprite.getTarget();
            break;
        }
    case Casting:
        switch (direct) {
        case rightLeft:
            return castingSprite2.getTarget();
            break;
        default:    //case leftRight:
            return castingSprite.getTarget();
            break;
        }
    //default:
    case Idle:
        switch (direct) {
        case rightLeft:
            return idleSprite2.getTarget();
            break;
        default:    //case leftRight:
            return idleSprite.getTarget();
            break;
        }
    }
}

QRectF NPC::getSource()
{
    switch (state) {
    case Walking:
        switch (direct) {
        case rightLeft:
            return walkSprite2.getSource();
            break;
        default:    //case leftRight:
            return walkSprite.getSource();
            break;
        }
    case Casting:
        switch (direct) {
        case rightLeft:
            return castingSprite2.getSource();
            break;
        default:    //case leftRight:
            return castingSprite.getSource();
            break;
        }
    //default:
    case Idle:
        switch (direct) {
        case rightLeft:
            return idleSprite2.getSource();
            break;
        default:    //case leftRight:
            return idleSprite.getSource();
            break;
        }
    }
}

QPixmap NPC::getTexture()
{
    switch (state) {
    case Walking:
        switch (direct) {
        case rightLeft:
            return walkSprite2.getTexture();
            break;
        default:    //case leftRight:
            return walkSprite.getTexture();
            break;
        }
    case Casting:
        switch (direct) {
        case rightLeft:
            return castingSprite2.getTexture();
            break;
        default:    //case leftRight:
            return castingSprite.getTexture();
            break;
        }
    //default:
    case Idle:
        switch (direct) {
        case rightLeft:
            return idleSprite2.getTexture();
            break;
        default:    //case leftRight:
            return idleSprite.getTexture();
            break;
        }
    }
}

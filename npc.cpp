#include "npc.h"
#include <iostream>

NPC::NPC() {}

NPC::~NPC(){}

bool NPC::isAlly() {}

void NPC::setTexture() {}

void NPC::setPosition(double x, double y)
{
    position = QPointF(x, y);
}

void NPC::setLimitArea(QRectF q) {}

void NPC::setVisionArea(QRectF q) {}

void NPC::setAttackArea(QRectF q) {}

void NPC::setHitBox(QRectF q) {}

QRectF NPC::getLimitArea() {}

QRectF NPC::getVisionArea() {}

QRectF NPC::getAttackArea() {}

QRectF NPC::getHitBox() {}

double NPC::getHeight() {}

double NPC::getWidth() {}

void NPC::setSpeed(double s){}

void NPC::isSeeingSomethingSus(){}

void NPC::isBeingAttacked(double damage) {}

bool NPC::isDisappeared() {}

std::vector<QRectF> NPC::getRedCollisions() {}

double NPC::getSpeed(){}

void NPC::setClock(){}

Sprite NPC::getSprite() {}

double NPC::getDamage() {}

bool NPC::isSpeaking() {}

QString NPC::getDialog() {}

void NPC::setDirection(Direction direct)
{
    this->direct = direct;
}

void NPC::setState(NPC_State s)
{
    state = s;
}

NPC_State NPC::getState()
{
    return state;
}

Direction NPC::getDirection()
{
    return direct;
}

void NPC::setHealth(double h)
{
    leftHealth = h;
}
void NPC::setFullHealth(double h)
{
    fullHealth = h;
}

QPointF NPC::getPosition()
{
    return position;
}

QPointF NPC::getLowestPoint()
{
    return QPointF(position.x() + getWidth()/2, position.y() + getHeight());
}

double NPC::getFullHealth()
{
    return fullHealth;
}
double NPC::getLeftHealth()
{
    return leftHealth;
}

QString NPC::getName()
{
    return name;
}

void NPC::setName(QString n)
{
    name = n;
}

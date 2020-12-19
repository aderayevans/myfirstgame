#include "npc.h"
#include <iostream>

NPC::NPC()
{
}

void NPC::setDirection(Direction direct)
{
    this->direct = direct;
}

void NPC::setTexture()
{
}

void NPC::setState(NPC_State s)
{
    state = s;
}

void NPC::setPosition(double x, double y)
{
    position = QPointF(x, y);
}

void NPC::setOrigin(double x, double y)
{
    setPosition(x, y);
}

void NPC::setLimitArea(double x1, double y1, double x2, double y2)
{
}

void NPC::setVisionArea(double x1, double y1, double x2, double y2)
{
}

void NPC::setHitBox(double x1, double y1, double x2, double y2)
{
}

QPointF NPC::getLimitArea(int number)
{
}

QPointF NPC::getVisionArea(int number)
{
}

QPointF NPC::getPointHitBox(int number)
{
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
void NPC::setMaxHealth(double h)
{
    maxHealth = h;
}

double NPC::getHeight()
{
}

double NPC::getWidth()
{
}

double NPC::getSpeed()
{
}

void NPC::setClock()
{
}

QPointF NPC::getPosition()
{
    return position;
}

QPointF NPC::getLowestPoint()
{
    return QPointF(position.x() + getWidth()/2, position.y() + getHeight());
}

double NPC::getMaxHealth()
{
    return maxHealth;
}
double NPC::getLeftHealth()
{
    return leftHealth;
}
QRectF NPC::getTarget()
{
}

QRectF NPC::getSource()
{
}

QPixmap NPC::getTexture()
{
}

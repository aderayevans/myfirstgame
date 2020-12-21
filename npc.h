#ifndef NPC_H
#define NPC_H
#include "sprite.h"

enum NPC_State { Attacking, Walking, Casting, Dying, Hurt, Idle };
class NPC
{
public:
    NPC();
    virtual void setTexture();
    virtual void setPosition(double, double);
    virtual void setLimitArea(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
    virtual void setVisionArea(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
    virtual void setHitBox(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
    virtual void setClock();
    virtual double getSpeed();
    virtual QPointF getLimitArea(int);
    virtual QPointF getVisionArea(int);
    virtual QPointF getPointHitBox(int);
    virtual QRectF getTarget();
    virtual QRectF getSource();
    virtual QPixmap getTexture();
    virtual double getWidth();
    virtual double getHeight();
    void setState(NPC_State);
    void setDirection(Direction);
    void setOrigin(double, double);
    void setHealth(double);
    void setFullHealth(double);
    QPointF getPosition();
    NPC_State getState();
    Direction getDirection();
    QPointF getLowestPoint();
    double getFullHealth();
    double getLeftHealth();

private:
    NPC_State state;
    Direction direct = rightLeft;
    QPointF position;
    double fullHealth;
    double leftHealth;
};

#endif // NPC_H

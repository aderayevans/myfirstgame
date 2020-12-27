#ifndef NPC_H
#define NPC_H
#include "sprite.h"

enum NPC_State { Attacking, Walking, Hurt, Idle };
class NPC
{
public:
    NPC();
    virtual ~NPC();
    virtual void setTexture();
    virtual void setPosition(double, double);
    virtual void setLimitArea(QRectF);
    virtual void setVisionArea(QRectF);
    virtual void setAttackArea(QRectF);
    virtual void setHitBox(QRectF);
    virtual void setClock();
    virtual void setSpeed(double);
    virtual double getSpeed();
    virtual void isSeeingSomethingSus();
    virtual void isBeingAttacked(double damage);
    virtual QRectF getLimitArea();
    virtual QRectF getVisionArea();
    virtual QRectF getAttackArea();
    virtual QRectF getHitBox();
    virtual QRectF getTarget();
    virtual QRectF getSource();
    virtual std::vector<QRectF> getRedCollisions();
    virtual QPixmap getTexture();
    virtual double getWidth();
    virtual double getHeight();
    virtual double getDamage();
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

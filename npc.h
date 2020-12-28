#ifndef NPC_H
#define NPC_H
#include "sprite.h"

enum NPC_State { Attacking, Walking, Hurt, Idle, Talking, Disappear };
class NPC
{
public:
    NPC();
    virtual ~NPC();
    virtual bool isAlly();
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
    virtual bool isDisappeared();
    virtual QRectF getLimitArea();
    virtual QRectF getVisionArea();
    virtual QRectF getAttackArea();
    virtual QRectF getHitBox();
    virtual std::vector<QRectF> getRedCollisions();
    virtual Sprite getSprite();
    virtual double getWidth();
    virtual double getHeight();
    virtual double getDamage();
    virtual bool isSpeaking();
    virtual QString getDialog();
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
    QString getName();
    void setName(QString);
private:
    QString name;
    NPC_State state;
    Direction direct = rightLeft;
    QPointF position;
    double fullHealth;
    double leftHealth;
};

#endif // NPC_H

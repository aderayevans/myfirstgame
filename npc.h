#ifndef NPC_H
#define NPC_H
#include "sprite.h"

enum NPC_State { Walking, Casting, Dying, Hurt, Idle };
class NPC
{
public:
    NPC();
    void setTexture();
    void setState(NPC_State);
    void setDirection(Direction);
    void setPosition(double, double);
    void setOrigin(double, double);
    void setLimitArea(double, double, double, double);
    void setHitBox(double, double, double, double);
    void setClock();
    double getSpeed();
    QPointF getLimitArea(int);
    QPointF getPointHitBox(int);
    QPointF getPosition();
    QRectF getTarget();
    QRectF getSource();
    QPixmap getTexture();
    NPC_State getState();
    double getWidth();
    double getHeight();
    QPointF getLowestPoint();
    int getFullHealth();
    int getLeftHealth();

    Sprite walkSprite;
    Sprite walkSprite2;
    Sprite idleSprite;
    Sprite idleSprite2;
    Sprite castingSprite;
    Sprite castingSprite2;
    NPC_State state = Casting;
    Direction direct = rightLeft;
    QPointF position;
    int clock = 0;
    int castingClock = 0;
    int castingPicture = 0;
    int castingSlowTime = 2;
    //int attackPicture = 0;
    //int attackClock = 0;
    //int attackSlowTime = 2;
    //int runTime = 0;

    int fallingRangeEachTimeID = 30;
    int speed = 10;
    int scale = 3;
    int fullHealth = 1000;
    int leftHealth = 10;
};

#endif // NPC_H

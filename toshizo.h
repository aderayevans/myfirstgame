#ifndef TOSHIZO_H
#define TOSHIZO_H
#include "sprite.h"

enum State { Stand, Run, Jump, Fall, Attack, JumpAttack, Buff };
class Toshizo
{
public:
    Toshizo();
    void setTexture();
    void setState(State);
    void setDirection(Direction);
    void setPosition(double, double);
    void setOrigin(double, double);
    void setLimitArea(double, double, double, double);
    void setHitBox(double, double, double, double);
    void setDoubleJump();
    bool doubleJumped();
    void setClock();
    double getSpeed();
    QPointF getLimitArea(int);
    QPointF getPointHitBox(int);
    QPointF getPosition();
    QRectF getTarget();
    QRectF getSource();
    QPixmap getTexture();
    State getState();
    double getWidth();
    double getHeight();
    QPointF getLowestPoint();
    int getFullHealth();
    int getLeftHealth();
    int getFullEnergy();
    int getLeftEnergy();

    Sprite standSprite, buffedStandSprite;
    Sprite standSprite2, buffedStandSprite2;
    Sprite runSprite;
    Sprite runSprite2;
    Sprite jumpSprite;
    Sprite jumpSprite2;
    Sprite attackSprite, buffedAttackSprite;
    Sprite attackSprite2, buffedAttackSprite2;
    Sprite jumpAttackSprite, buffedJumpAttackSprite;
    Sprite jumpAttackSprite2, buffedJumpAttackSprite2;
    Sprite buffSprite;
    Sprite buffSprite2;
    State state = Stand;
    Direction direct = leftRight;
    QPointF position;
    int clock = 0;
    int jumpPicture = 0;
    int standPicture = 0;
    int attackPicture = 0;
    int jumpAttackPicture = 0;
    int buffPicture = 0;
    int jumpClock = 0;
    int standClock = 0;
    int attackClock = 0;
    int jumpAttackClock = 0;
    int buffClock = 0;
    int standSlowTime = 2;
    int attackSlowTime = 2;
    int jumpAttackSlowTime = 0;
    int buffSlowTime = 10;
    int runTime = 0;
    int buffTime = 100000000; //0
    int maxBuffTime = 100000000;//30*5; //30s
    int jumpLimitTime = 7;
    int goCrazyTime = 15;
    bool doubleJump = false;
    bool buffed = true; //false

    int boostHigh = 0;
    int boostSpeed = 0;
    int buffedSkillRange = 50;
    int jumpRangeEachTimeID = 30;
    int fallingRangeEachTimeID = 30;
    int maxBoost = 10;
    int speed = 10;
    int scale = 1;
    int fullHealth = 1000;
    int leftHealth = 10;
    int fullEnergy = 1000;
    int leftEnergy = 500;
};

#endif // TOSHIZO_H

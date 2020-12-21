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
    void setLimitArea(double x1, double y1, double x2, double y2);
    void setHitBox(double x1, double y1, double x2, double y2);
    void setDoubleJump();
    void setHealth(double);
    bool doubleJumped();
    bool isBuffed();
    bool isHacked();
    void hackON();
    void hackOFF();
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
    double getFullHealth();
    double getLeftHealth();
    double getFullEnergy();
    double getLeftEnergy();
private:
    Sprite standSprite, buffedStandSprite, hurtingStandSprite, buffedHurtingStandSprite;
    Sprite standSprite2, buffedStandSprite2, hurtingStandSprite2, buffedHurtingStandSprite2;
    Sprite runSprite, hurtingRunSprite;
    Sprite runSprite2, hurtingRunSprite2;
    Sprite jumpSprite, hurtingJumpSprite;
    Sprite jumpSprite2, hurtingJumpSprite2;
    Sprite attackSprite, buffedAttackSprite, hurtingAttackSprite, buffedHurtingAttackSprite;
    Sprite attackSprite2, buffedAttackSprite2, hurtingAttackSprite2, buffedHurtingAttackSprite2;
    Sprite jumpAttackSprite, buffedJumpAttackSprite;
    Sprite jumpAttackSprite2, buffedJumpAttackSprite2;
    Sprite buffSprite, hurtingBuffSprite;
    Sprite buffSprite2, hurtingBuffSprite2;
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
    int jumpAttackSlowTime = 2;
    int buffSlowTime = 10;
    int runTime = 0;
    int flyTime = 0;
    int onSkyTime_forNotBuffedJumpAttack = 3;
    int maxFlyTime = 7;
    int hackedFlyTime = 60*5;
    int maxBuffTime = 30*5; //5s
    int jumpLimitTime = 6;
    int boostTime = 15;
    bool doubleJump = false;
    int buffed = 0;
    int hurted = 0;
    int maxHurtTime = 15;
    bool hacked = false;
    bool immortal = false;
    int boostHigh = 0;
    int boostSpeed = 0;
    int buffedSkillRange = 50;
    int jumpRangeEachTimeID = 30;
    int fallingRangeEachTimeID = 30;
    int maxBoost = 10;
    int speed = 10;
    int scale = 1;
    double fullHealth = 1000;
    double leftHealth = 1000;
    double fullEnergy = 1000;
    double leftEnergy = 500;
};

#endif // TOSHIZO_H

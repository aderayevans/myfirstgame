#ifndef TOSHIZO_H
#define TOSHIZO_H
#include <QPainter>
#include "sprite.h"
#include "collision.h"

enum State { Stand, Run, Jump, Fall, Attack, JumpAttack, Buff, Dying };
class Toshizo
{
public:
    Toshizo();
    void setTexture();
    void setState(State);
    void setDirection(Direction);
    void setPosition(double, double);
    void setHitBox(QRectF);
    void setDoubleJump();
    void setHealth(double);
    void setEnergy(double);
    bool doubleJumped();
    bool isBuffed();
    bool isHack();
    void hackON();
    void hackOFF();
    void setClock();
    double getSpeed();
    QPointF getPosition();
    QRectF getHitBox();
    Sprite getSprite();
    std::vector<Sprite*> getSprites();
    std::vector<Collision> getBlueCollisions();
    State getState();
    double getDamage();
    double getWidth();
    double getHeight();
    QPointF getLowestPoint();
    Direction getDirection();
    double getFullHealth();
    double getLeftHealth();
    double getFullEnergy();
    double getLeftEnergy();
    void draw(QPainter &);
    void setHealthPotionNumber(int);
    void setEnergyPotionNumber(int);
    int getHealthPotionNumber();
    int getEnergyPotionNumber();
    Sprite getAvatar();
    void useHealthPotion();
    void useEnergyPotion();
    void useSkill1();
    void useSkill2();
    void useSkill3();
private:
    State state = Stand;
    Direction direct = leftRight;
    QPointF position;
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
    Sprite dyingSprite;
    Sprite avatar;
    Sprite tornadoPattern, darkBallPattern, rasenganPattern, rasenganPattern2;
    std::vector<Sprite> tornados, darkBalls, rasengans;
    std::vector<Collision> collisions;
    int cooldownSkill1 = 30*2;
    int cooldownSkill2 = 30*2;
    int cooldownSkill3 = 30*2;
    int countdownSkill1 = 0;
    int countdownSkill2 = 0;
    int countdownSkill3 = 0;
    int lifetimeSkill1 = 30;
    int lifetimeSkill2 = 30;
    double tornadoDamage = 50;
    double darkBallDamage = 80;
    double rasenganDamage = 100;
    int buffRequiredEnergy = 100;
    int skill1RequiredEnergy = 100;
    int skill2RequiredEnergy = 100;
    int skill3RequiredEnergy = 100;
    int healthPotionNumber = 0;
    int energyPotionNumber = 0;
    int jumpFrame = 0;
    int standFrame = 0;
    int attackFrame = 0;
    int jumpAttackFrame = 0;
    int buffFrame = 0;
    int jumpClock = 0;
    int standClock = 0;
    int attackClock = 0;
    int jumpAttackClock = 0;
    int buffClock = 0;
    int standSlowTime = 2;
    int attackSlowTime = 2;
    int jumpAttackSlowTime = 2;
    int buffSlowTime = 8;
    int runTime = 0;
    int flyTime = 0;
    int onSkyTime_forNotBuffedJumpAttack = 3;
    int maxFlyTime = 7;
    int hackFlyTime = 60*5;
    int maxBuffTime = 30*5; //5s
    int jumpLimitTime = 6;
    int boostTime = 15;
    int buffed = 0;
    int hurt = 0;
    int maxHurtTime = 15;
    int boostHigh = 0;
    int boostSpeed = 0;
    int buffedSkillRange = 50;
    int jumpRangeEachTimeID = 20;
    int fallingRangeEachTimeID = 30;
    int maxBoost = 10;
    int speed = 10;
    int scale = 1;
    double damage = 20;
    double buffedDamage = 100;
    double maxDamage = 10000;
    bool hack = false;
    bool immortal = false;
    bool doubleJump = false;
    double fullHealth = 1000;
    double leftHealth = 600;
    double fullEnergy = 1000;
    double leftEnergy = 0;
};

#endif // TOSHIZO_H

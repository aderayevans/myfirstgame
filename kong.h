#ifndef KONG_H
#define KONG_H
#include "npc.h"

class Kong : public NPC
{
public:
    Kong();
    bool isAlly() override;
    void setTexture() override;
    void setPosition(double, double) override;
    void setLimitArea(QRectF) override;
    void setVisionArea(QRectF) override;
    void setAttackArea(QRectF) override;
    void setHitBox(QRectF) override;
    void setClock() override;
    void setSpeed(double) override;
    double getSpeed() override;
    void isSeeingSomethingSus() override;
    void isBeingAttacked(double damage) override;
    bool isDisappeared() override;
    QRectF getLimitArea() override;
    QRectF getVisionArea() override;
    QRectF getAttackArea() override;
    QRectF getHitBox() override;
    std::vector<QRectF> getRedCollisions() override;
    Sprite getSprite() override;
    double getWidth() override;
    double getHeight() override;
    double getDamage() override;
    bool isSpeaking() override;
    QString getDialog() override;
private:
    Sprite walkSprite;
    Sprite walkSprite2;
    Sprite idleSprite;
    Sprite idleSprite2;
    Sprite attackSprite;
    Sprite attackSprite2;
    int clock = 0;
    int attackClock = 0;
    int attackFrame = 0;
    int attackSlowTime = 2;
    int walkClock = 0;
    int walkFrame = 0;
    int walkSlowTime = 2;
    int caution = 0;
    int maxCautionTime = 3;
    bool booleanNormalAttack = false;
    bool seeingSus = false;
    int fallingRangeEachTimeID = 30;
    int speed = 5;
    int maxSpeed = 15;
    int scale = 1;
    double damage = 100;
    QString dialog;
};

#endif // KONG_H

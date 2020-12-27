#ifndef KONG_H
#define KONG_H
#include "npc.h"

class Kong : public NPC
{
public:
    Kong();
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
    QRectF getLimitArea() override;
    QRectF getVisionArea() override;
    QRectF getAttackArea() override;
    QRectF getHitBox() override;
    QRectF getTarget() override;
    QRectF getSource() override;
    std::vector<QRectF> getRedCollisions() override;
    QPixmap getTexture() override;
    double getWidth() override;
    double getHeight() override;
    double getDamage() override;
private:
    Sprite walkSprite;
    Sprite walkSprite2;
    Sprite idleSprite;
    Sprite idleSprite2;
    Sprite attackSprite;
    Sprite attackSprite2;
    int clock = 0;
    int attackClock = 0;
    int attackPicture = 0;
    int attackSlowTime = 2;
    int walkClock = 0;
    int walkPicture = 0;
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
};

#endif // KONG_H

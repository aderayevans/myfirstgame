#ifndef WRAITH_H
#define WRAITH_H
#include "npc.h"

class Wraith : public NPC
{
public:
    Wraith();
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
    Sprite hurtSprite;
    Sprite hurtSprite2;
    Sprite attackingSprite;
    Sprite attackingSprite2;
    int attackClock = 0;
    int attackPicture = 0;
    int attackSlowTime = 2;
    int walkClock = 0;
    int walkPicture = 0;
    int walkSlowTime = 5;
    int idleClock = 0;
    int idlePicture = 0;
    int idleSlowTime = 7;
    int idleTime = 0;
    int idleMaxTime = 30*5;
    int hurtClock = 0;
    int hurtPicture = 0;
    int hurtSlowTime = 5;
    int attackingSkillTime = 0;
    int maxAttackingSkillTime = 5;
    bool caution = false;
    bool booleanNormalAttack = false;
    int fallingRangeEachTimeID = 30;
    int speed = 5;
    int maxSpeed = 15;
    int scale = 3;
    double damage = 0;
};

#endif // WRAITH_H

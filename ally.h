#ifndef ALLY_H
#define ALLY_H
#include "npc.h"


class Ally : public NPC
{
public:
    Ally();
    Ally(int);
    void setTexture() override;
    bool isAlly() override;
    void setPosition(double, double) override;
    void setHitBox(QRectF) override;
    void setClock() override;
    QRectF getHitBox() override;
    Sprite getSprite() override;
    double getWidth() override;
    double getHeight() override;

    void setLimitArea(QRectF) override;
    void setVisionArea(QRectF) override;
    void setAttackArea(QRectF) override;
    void setSpeed(double) override;
    double getSpeed() override;
    void isSeeingSomethingSus() override;
    void isBeingAttacked(double damage) override;
    QRectF getLimitArea() override;
    QRectF getVisionArea() override;
    QRectF getAttackArea() override;
    std::vector<QRectF> getRedCollisions() override;
    double getDamage() override;
    bool isDisappeared() override;
    bool isSpeaking() override;
    QString getDialog() override;
private:
    Sprite idleSprite, sprite;

    int idleClock = 0;
    int idleSlowTime = 10;

    int talkingClock = 0;
    int talkingFrame = 0;
    int talkingSlowTime = 10;
    int talkingTime = 0;
    int talkingMaxTime = 50;
    int disappearClock = 0;
    int disappearTime = 10;

    int scale = 1;
    bool speak = false;
    QString dialog;
    QString longDialog1, longDialog2;
};

#endif // ALLY_H

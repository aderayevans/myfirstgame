#ifndef KONG_H
#define KONG_H
#include "npc.h"

class Kong : public NPC
{
public:
    Kong();
    void setTexture() override;
    void setPosition(double, double) override;
    void setLimitArea(double x1, double y1, double x2, double y2) override;
    void setVisionArea(double x1, double y1, double x2, double y2) override;
    void setHitBox(double x1, double y1, double x2, double y2) override;
    void setClock() override;
    double getSpeed() override;
    QPointF getLimitArea(int) override;
    QPointF getVisionArea(int) override;
    QPointF getPointHitBox(int) override;
    QRectF getTarget() override;
    QRectF getSource() override;
    QPixmap getTexture() override;
    double getWidth() override;
    double getHeight() override;
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

    int fallingRangeEachTimeID = 30;
    int speed = 5;
    int scale = 1;
};

#endif // KONG_H
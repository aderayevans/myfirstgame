#ifndef TWOWAYSOBJECT_H
#define TWOWAYSOBJECT_H

#include "sprite.h"

class TwoWaysObject
{
public:
    TwoWaysObject();

    void setTexture(const char * xpm, const char * otherXpm, int totalPicture = 1, int scale = 1);
    void setSpeed(double);
    void setDirection(Direction);
    void setOrigin(double, double);
    void setPosition(double, double);
    void setLimitArea(double, double, double, double);
    void setClock();
    double getWidth();
    double getHeight();
    QPointF getLimitArea(int);
    QRectF getSource();
    QRectF getTarget();
    QPixmap getTexture();

    Sprite firstSprite;
    Sprite secondSprite;
    Direction direct = leftRight;
};

#endif // TWOWAYSOBJECT_H

#ifndef SPRITE_H
#define SPRITE_H
#include <QPixmap>
#include <QRectF>
#include <QWidget>

enum Direction { leftRight, rightLeft };
class Sprite
{
public:
    Sprite();
    Sprite(const QPixmap &pixmap, int totalPicture = 1, int scale = 1);
    Sprite(const char * xpm, int totalPicture = 1, int scale = 1);
    void setTexture(const QPixmap &pixmap, int totalPicture = 1, int scale = 1);
    void setTexture(const char * xpm, int totalPicture = 1, int scale = 1);
    virtual void setPosition(double, double);
    virtual void setOrigin(double, double);
    void setTarget();
    void setSource();
    void setSpeed(double);
    void setClock(int);
    void setSource(QRectF source);
    void setTarget(QRectF target);
    void setLimitArea(double x1, double y1, double x2, double y2);
    void setVisionArea(double x1, double y1, double x2, double y2);
    void setHitBox(double x1, double y1, double x2, double y2);
    QPointF getLimitArea(int);
    QPointF getVisionArea(int);
    QPointF getPointHitBox(int);
    int getTotalPicture();
    double getSpeed();
    double getWidth();
    double getHeight();
    QPointF getPosition();
    QRectF getSource();
    QRectF getTarget();
    QPixmap getTexture();

private:
    QPixmap texture;
    double width, height;
    int totalPicture;
    QPointF position;
    QRectF target, source;
    double speed;
    int clock;
    QPointF pointLeftBelow, pointLeftAbove, pointRightBelow, pointRightAbove;
    QPointF limitLeftBelow, limitLeftAbove, limitRightBelow, limitRightAbove;
    QPointF visionLeftBelow, visionLeftAbove, visionRightBelow, visionRightAbove;
};

#endif // SPRITE_H

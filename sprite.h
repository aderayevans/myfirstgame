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
    ~Sprite();
    Sprite(const QPixmap &pixmap, int totalPicture = 1, int scale = 1);
    void operator = (const Sprite &A);
    Sprite(const char * xpm, int totalPicture = 1, int scale = 1);
    void setTexture(const QPixmap &pixmap, int totalPicture = 1, int scale = 1);
    void setTexture(const char * xpm, int totalPicture = 1, int scale = 1);
    virtual void setPosition(double, double);
    void setTarget();
    void setSource();
    void setSpeed(double);
    void setClock();
    void setFrame(int);
    void setDuration(int);
    void setDirection(Direction);
    void setSource(QRectF source);
    void setTarget(QRectF target);
    void setLimitArea(QRectF);
    void setVisionArea(QRectF);
    void setHitBox(QRectF);
    void setAttackArea(QRectF);
    QRectF getLimitArea();
    QRectF getVisionArea();
    QRectF getHitBox();
    QRectF getAttackArea();
    int getTotalPicture();
    double getSpeed();
    double getWidth();
    double getHeight();
    QPointF getPosition();
    QRectF getSource();
    QRectF getTarget();
    QPixmap getTexture();
    Direction getDirection();
    int getDuration();
    int getFrame();
    int getLifetime();
    void stopFrame();
    void goOn();
private:
    QPixmap texture;
    double width, height;
    int totalPicture;
    QPointF position;
    QRectF target, source;
    QRectF hitBox, limitArea, visionArea, attackArea;
    double speed;
    int clock = 0;
    int duration = 0;
    int frame = 0;
    Direction direct;
    bool stop = false;
    int lifetime = 0;
};

#endif // SPRITE_H

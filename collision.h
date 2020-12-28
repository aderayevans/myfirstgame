#ifndef COLLISION_H
#define COLLISION_H
#include <QRectF>

struct Collision
{
    QRectF box;
    double damage;
    bool white;

    Collision() : box(QRectF(0, 0, 0, 0)), damage(0), white(false)
    {

    }

    Collision(QRectF b, double d, bool white) : box(b), damage(d), white(white)
    {
    }
};

#endif // COLLISION_H

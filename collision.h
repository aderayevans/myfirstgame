#ifndef COLLISION_H
#define COLLISION_H
#include <QRectF>

struct Collision
{
    QRectF box;
    double damage;

    Collision() : box(QRectF(0, 0, 0, 0)), damage(0)
    {

    }

    Collision(QRectF b, double d) : box(b), damage(d)
    {
    }
};

#endif // COLLISION_H

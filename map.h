#ifndef MAP_H
#define MAP_H
#include <QPainter>
#include "wall.h"
#include "ground.h"
#include "sprite.h"
#include "npc.h"


class Map
{
public:
    Map();
    void setClock();
    void draw(QPainter &);
    void move(double);
    void clip();
    void convert();
    void setViewPort(double, double);
    std::vector<Ground> getGrounds();
    std::vector<Wall> getWalls();
    QPoint getMapLimit(int);

    double xwMax = 1366, ywMax = 768, xwMin = 0, ywMin = 0, xvMax, xvMin, yvMax, yvMin;
    double width, height;
    int clock = 0;
    Sprite backgrounds[9];
    int bgLayers = 8;
    int cloud = 1;
    std::vector<Ground> grounds, currentGrounds;
    std::vector<Wall> walls, currentWalls;
    std::vector<NPC> wraiths;
    QPoint mapLimitPoint1, mapLimitPoint2;
};

#endif // MAP_H

#ifndef MAP_H
#define MAP_H
#include <QPainter>
#include "wall.h"
#include "ground.h"
#include "sprite.h"
#include "collision.h"
#include "npc.h"
#include "kong.h"
#include "wraith.h"
#include "ally.h"


class Map
{
public:
    Map();
    void setClock();
    void draw(QPainter &);
    void move(double);
    void clip();
    void convert();
    void updateRedCollisions();
    void deleteNPCAt(int locate);
    void deleteHealthAt(int locate);
    void deleteEnergyAt(int locate);
    void setViewPort(double, double);
    void generateDirtAt(QPointF);
    std::vector<Ground> getGrounds();
    std::vector<Wall> getWalls();
    std::vector<NPC *> getNPCs();
    std::vector<Sprite *> getHealthPotions();
    std::vector<Sprite *> getEnergyPotions();
    std::vector<Collision> getRedCollisions();
    QPointF getMapLimit(int);
    QPointF getCurrentMapPoint(int);
    void getPlayerSprites(std::vector<Sprite*>);
private:
    double xwMax = 1366, ywMax = 768, xwMin = 0, ywMin = 0, xvMax, xvMin, yvMax, yvMin;
    double width, height;
    int clock = 0;
    Sprite backgrounds[9];
    int bgLayers = 8;
    int cloud = 1;
    std::vector<Ground> grounds, currentGrounds;
    std::vector<Wall> walls, currentWalls;
    std::vector<NPC *> NPCs;
    QPointF mapLimitPointLeft, mapLimitPointRight,
            mapCurrentPointLeft, mapCurrentPointRight,
            pseudoLimitPointLeft, pseudoLimitPointRight;
    std::vector<QPointF> pseudoPoints;
    std::vector<Collision> redCollisions;

    std::vector<Sprite *> energyPotions, healthPotions;
    std::vector<Sprite> snowmans, snowtrees, signboards, bodyExplosions;
    Sprite dirtPattern, explosion1Pattern, dirt;
    bool booleanDirt = false;
    std::vector<Sprite*> playerSprites;

};

#endif // MAP_H

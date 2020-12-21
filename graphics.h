#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include "sprite.h"
#include "toshizo.h"
#include "ground.h"
#include "wall.h"
#include "map.h"
#include <vector>

enum SideOfBox { Left, Right, Outside };
class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void initial();
    void youDie();
    bool isGround();
    void checkCollision();
    bool checkCollision(SideOfBox option, QPointF leftAbove, QPointF leftBelow, QPointF rightAbove, QPointF rightBelow);
    SideOfBox checkCollision(QPointF leftAbove, QPointF leftBelow, QPointF rightAbove, QPointF rightBelow);
    bool checkCollision(QPointF point, double xMin, double xMax, double yMin, double yMax);
    void checkWall();
    void checkRedCollision();
    void checkMoveMap();
    void drawHealthbar(QPainter &);
    void drawText(QPainter &, QRectF, QColor, int, QString);
    void drawHUD(QPainter &);   //Heads-up display

    QPointF BD;
    double huong = 0;
    const int UNIT = 20;
    const double PI = 3.14159265358979323846;
    double timerId;
    int clock = 0;
    bool rightIsPressed = false;
    bool leftIsPressed = false;
    bool spaceIsPressed = false;
    bool enterIsPressed = false;
    bool cIsPressed = false;
    bool zIsPressed = false;
    bool hIsPressed = false;

    bool allKeysReleased = false;
    bool acceptInput = false;
    bool paused = true;
    bool initialed = false;
    bool dying = false;
    Toshizo player;
    std::vector<Ground> grounds;
    std::vector<Wall> walls;
    Map map;
    Sprite timeCircle;
    int point;
signals:
};

#endif // GRAPHICS_H

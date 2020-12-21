#include "graphics.h"
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <QDebug>
#define max(x,y) x>y?x:y

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    startTimer(33);
}

void graphics::timerEvent(QTimerEvent *event)
{
    if (!paused)
    {
        clock += 1;
        if (rightIsPressed)
        {
            player.setPosition(player.getPosition().x() + player.getSpeed(), player.getPosition().y());
        }
        if (leftIsPressed)
        {
            player.setPosition(player.getPosition().x() - player.getSpeed(), player.getPosition().y());
        }
    }
    //qDebug() << "Timer ID:" << event->timerId();
    repaint();
}

void graphics::keyPressEvent(QKeyEvent *event)
{
    allKeysReleased = false;
    if (!acceptInput)
    {
        if (event->key() == Qt::Key_Return)
        {
            enterIsPressed = true;
            paused = false;
            dying = false;
        }
    }
    else if (player.getState() == JumpAttack && player.isBuffed())
    {
        if (event->key() == Qt::Key_Down)
        {
            player.setState(Stand);
        }
    }
    else
    {
        switch (event->key())
        {
        case (Qt::Key_Right):
            player.setDirection(leftRight);
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Run);
            }
            rightIsPressed = true;
            break;
        case (Qt::Key_Left):
            player.setDirection(rightLeft);
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Run);
            }
            leftIsPressed = true;
            break;
        case (Qt::Key_Space):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Jump);
            }
            else if (player.getState() == Fall && !player.doubleJumped())
            {
                player.setDoubleJump();
                player.setState(Jump);
            }
            spaceIsPressed = true; //double jump //upgrade later
            break;
        case (Qt::Key_C):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                if (player.getState() != Attack)
                {
                    player.setState(Attack);
                    cIsPressed = true;
                }
            }
            else if ((player.getState() == Jump || player.getState() == Fall) && player.getState() != JumpAttack)
            {
                player.setState(JumpAttack);
                cIsPressed = true;
            }
            break;
        case (Qt::Key_Z):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Buff);
                zIsPressed = true;
            }
            break;
        case (Qt::Key_H):
            if (player.isHacked()) player.hackOFF();
            else player.hackON();
            hIsPressed = true;
            break;
        }
    }
}

void graphics::keyReleaseEvent(QKeyEvent *event)
{
    if (player.getState() == JumpAttack && player.isBuffed());
    else
    {
        switch (event->key())
        {
        case (Qt::Key_Right):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Stand);
            }
            rightIsPressed = false;
            break;
        case (Qt::Key_Left):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Stand);
            }
            leftIsPressed = false;
            break;
        case (Qt::Key_Down):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Stand);
            }
            break;
        case (Qt::Key_Space):
            if (player.getState() == JumpAttack) break;
            spaceIsPressed = false;
            break;
        case (Qt::Key_Return):
            if (player.getState() == JumpAttack) break;
            enterIsPressed = false;
            break;
        case (Qt::Key_C):
            if (player.getState() == JumpAttack) break;
            cIsPressed = false;
            break;
        case (Qt::Key_Z):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Stand);
            }
            zIsPressed = false;
            break;
        case (Qt::Key_H):
            hIsPressed = false;
            break;
        }
        if (!spaceIsPressed && !rightIsPressed && !leftIsPressed && !enterIsPressed && !cIsPressed && !zIsPressed && !hIsPressed)
        {
            allKeysReleased = true;
        }
    }
}

void graphics::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (!clock)     //only paintEvent know window height and width
    {
        srand((int)time(0) * 10);
        painter.setBrush(QColor(0, 255, 255));
        painter.drawRect(geometry());
    }

    if (clock) //draw map
    {
        map.setClock();
        player.setClock();
        map.draw(painter);
        drawHUD(painter);
    }

    if (paused && !dying)
    {
        drawText(painter, QRectF(width()/2 - 200, height()/2, width(), height()), Qt::black, 32, "Press Enter to start");
    }
    else if (paused && dying)
    {
        drawText(painter, QRectF(width()/2 - 200, height()/2 - 100, width(), height()), Qt::red, 32, "You died");
        drawText(painter, QRectF(width()/2 - 200, height()/2, width(), height()), Qt::red, 32, "Press Enter to restart");
    }
    else if (!initialed)    //initialize
    {
        acceptInput = true;
        initial();
    }
    else if (!paused)   //game running
    {
        checkCollision();
        if (player.getLeftHealth() <= 0) youDie();
        painter.drawRect(player.getPointHitBox(1).x(), player.getPointHitBox(3).y(),
                         player.getPointHitBox(4).x() - player.getPointHitBox(2).x(),
                         player.getPointHitBox(4).y() - player.getPointHitBox(3).y());//delete this
        painter.drawPixmap(player.getTarget(), player.getTexture(), player.getSource());    //draw character
    }
}

void graphics::initial()
{
    initialed = true;
    clock = 0;
    //qDebug() << width() << "; " << height();
    map = Map();
    map.setViewPort(width(), height());
    grounds = map.getGrounds();
    walls = map.getWalls();

    player = Toshizo();
    player.setOrigin(200, height() - 400 - player.getHeight());
    player.setLimitArea(100, 0, width() - 100, height());

    timeCircle.setTexture("D://Games//Toshizo//timeCircle.png", 17, 1);
    timeCircle.setOrigin(width()/2, 20);
}

void graphics::youDie()
{
    dying = true;
    acceptInput = false;
    paused = true;
    initialed = false;
}

void graphics::checkCollision()
{
    if (player.getState() != Jump && player.getState() != JumpAttack)
    {
        if (isGround())
        {
            if (player.getState() == Fall) player.setState(Stand);
        }
        else player.setState(Fall);
    }
    checkWall();
    checkMoveMap();
    checkRedCollision();

    if (player.getPosition().y() > player.getLimitArea(2).y())
    {
        youDie();
    }

}

void graphics::checkRedCollision()
{
    for (unsigned int i = 0; i < map.getRedCollisions().size(); i++)
    {
        if ((checkCollision(player.getPointHitBox(1),
                           map.getRedCollisions()[i].x(),
                           map.getRedCollisions()[i].x() + map.getRedCollisions()[i].width(),
                           map.getRedCollisions()[i].y(),
                           map.getRedCollisions()[i].y() + map.getRedCollisions()[i].height()))
            ||
            (checkCollision(player.getPointHitBox(2),
                                       map.getRedCollisions()[i].x(),
                                       map.getRedCollisions()[i].x() + map.getRedCollisions()[i].width(),
                                       map.getRedCollisions()[i].y(),
                                       map.getRedCollisions()[i].y() + map.getRedCollisions()[i].height()))
            ||
            (checkCollision(player.getPointHitBox(3),
                                       map.getRedCollisions()[i].x(),
                                       map.getRedCollisions()[i].x() + map.getRedCollisions()[i].width(),
                                       map.getRedCollisions()[i].y(),
                                       map.getRedCollisions()[i].y() + map.getRedCollisions()[i].height()))
            ||
            (checkCollision(player.getPointHitBox(4),
                                       map.getRedCollisions()[i].x(),
                                       map.getRedCollisions()[i].x() + map.getRedCollisions()[i].width(),
                                       map.getRedCollisions()[i].y(),
                                       map.getRedCollisions()[i].y() + map.getRedCollisions()[i].height()))
            ||
            (checkCollision(QPointF(map.getRedCollisions()[i].x(),
                                    map.getRedCollisions()[i].y()),
                                       player.getPointHitBox(1).x(),
                                       player.getPointHitBox(3).x(),
                                       player.getPointHitBox(1).y(),
                                       player.getPointHitBox(2).y()))
            ||
            (checkCollision(QPointF(map.getRedCollisions()[i].x(),
                                    map.getRedCollisions()[i].y() + map.getRedCollisions()[i].height()),
                                        player.getPointHitBox(1).x(),
                                        player.getPointHitBox(3).x(),
                                        player.getPointHitBox(1).y(),
                                        player.getPointHitBox(2).y()))
            ||
            (checkCollision(QPointF(map.getRedCollisions()[i].x() + map.getRedCollisions()[i].width(),
                                    map.getRedCollisions()[i].y()),
                                        player.getPointHitBox(1).x(),
                                        player.getPointHitBox(3).x(),
                                        player.getPointHitBox(1).y(),
                                        player.getPointHitBox(2).y()))
                ||
            (checkCollision(QPointF(map.getRedCollisions()[i].x() + map.getRedCollisions()[i].width(),
                                    map.getRedCollisions()[i].y() + map.getRedCollisions()[i].height()),
                                        player.getPointHitBox(1).x(),
                                        player.getPointHitBox(3).x(),
                                        player.getPointHitBox(1).y(),
                                        player.getPointHitBox(2).y())))

        {
            player.setHealth(player.getLeftHealth() - 100);
        }

    }
}

bool graphics::checkCollision(SideOfBox option, QPointF leftAbove, QPointF leftBelow, QPointF rightAbove, QPointF rightBelow)
{
    return option == checkCollision(leftAbove, leftBelow, rightAbove, rightBelow);
}
/*
1(x1, y1).--------y1--------.(x2, y1)3
        |                  |
        |                  |
        |                  |
2(x1, y2).--------y2--------.(x2, y2)4
*/
SideOfBox graphics::checkCollision(QPointF leftAbove, QPointF leftBelow, QPointF rightAbove, QPointF rightBelow)
{
    if (checkCollision(player.getPointHitBox(3), leftBelow.x(), rightBelow.x(), rightAbove.y(), leftBelow.y()) ||
        checkCollision(player.getPointHitBox(4), leftBelow.x(), rightBelow.x(), rightAbove.y(), leftBelow.y())
        )
    {
        return Left;
    }
    else if (checkCollision(player.getPointHitBox(1), leftBelow.x(), rightBelow.x(), leftAbove.y(), leftBelow.y()) ||
        checkCollision(player.getPointHitBox(2), leftBelow.x(), rightBelow.x(), leftAbove.y(), leftBelow.y())
        )
    {
        return Right;
    }
    return Outside;
}

bool graphics::checkCollision(QPointF point, double xMin, double xMax, double yMin, double yMax)
{
    if (point.x() < xMin || point.x() > xMax ||
        point.y() < yMin || point.y() > yMax)
    {
        return false;   //outside
    }
    //0000
    return true;
}

bool graphics::isGround()
{
    for (unsigned int i = 0; i < grounds.size(); i++)
    {
        if (checkCollision(player.getLowestPoint(),
                           grounds[i].getPointHitBox(1).x(),
                           grounds[i].getPointHitBox(3).x(),
                           grounds[i].getPointHitBox(1).y() - 30,
                           grounds[i].getPointHitBox(1).y()))
        {
            player.setPosition(player.getPosition().x(), grounds[i].getHighestY() - player.getHeight());
            return true;
        }
    }
    return false;
}

void graphics::checkWall()
{
    for (unsigned int i = 0; i < walls.size(); i++)
    {
        if (checkCollision(Left, walls[i].getPointHitBox(1), walls[i].getPointHitBox(2),
                       walls[i].getPointHitBox(3), walls[i].getPointHitBox(4)))
        {
            player.setPosition(walls[i].getLeftX() - player.getWidth(), player.getPosition().y());
        }
        else if (checkCollision(Right, walls[i].getPointHitBox(1), walls[i].getPointHitBox(2),
                       walls[i].getPointHitBox(3), walls[i].getPointHitBox(4)))
        {
            player.setPosition(walls[i].getRightX() + player.getSpeed(), player.getPosition().y());
        }
    }
}

void graphics::checkMoveMap()
{
    if ((player.getPosition().x() > width()/2 && map.getCurrentMapPoint(2).x() < map.getMapLimit(2).x()) ||
        (player.getPosition().x() < width()/2 && map.getCurrentMapPoint(1).x() > map.getMapLimit(1).x()))
    {
        map.move(width()/2 - player.getPosition().x());
        grounds = map.getGrounds();
        walls = map.getWalls();
        player.setPosition(width()/2, player.getPosition().y());
    }
}

void graphics::drawHealthbar(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::green);
    painter.drawRect(player.getPosition().x(), player.getPosition().y() - 14,
                     (player.getWidth())*((double)player.getLeftHealth()
                                          / player.getFullHealth()), 5);
    for (unsigned int i = 0; i < map.getNPCs().size(); i++)
    {
        painter.drawRect(map.getNPCs()[i]->getPosition().x(),map.getNPCs()[i]->getPosition().y() - 14,
                         (map.getNPCs()[i]->getWidth())*((double)map.getNPCs()[i]->getLeftHealth()
                                                         / map.getNPCs()[i]->getFullHealth()), 5);
    }

    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::black);
    painter.drawRect(player.getPosition().x(), player.getPosition().y() - 14,
                     (player.getWidth()), 5);

    for (unsigned int i = 0; i < map.getNPCs().size(); i++)
    {
        painter.drawRect(map.getNPCs()[i]->getPosition().x(),map.getNPCs()[i]->getPosition().y() - 14,
                         (map.getNPCs()[i]->getWidth()), 5);
    }

}

void graphics::drawText(QPainter &painter, QRectF rect, QColor color, int size, QString text)
{
    //QBrush brush = QColor(rand() % 256, rand() % 256, rand() % 256);
    painter.setRenderHint(QPainter::TextAntialiasing);
    QFont font;
    font.setFamily("Roboto medium");
    font.setPointSize(size);
    font.setStyleHint(QFont::Helvetica, QFont::PreferAntialias);

    painter.setPen(color);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignLeft , text);
}

void graphics::drawHUD(QPainter &painter)
{
    drawText(painter, QRectF(width() - 100, 10, width(), height()), Qt::black, 12, "Point: ");
    drawText(painter, QRectF(width() - 50, 10, width(), height()), Qt::black, 12, QString::number(point));

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    double health = max(0, 300*((double)player.getLeftHealth() / player.getFullHealth()));
    painter.drawRect(5, 5, health, 20);
    painter.setBrush(Qt::blue);
    double energy = max(0, 300*((double)player.getLeftEnergy() / player.getFullEnergy()));
    painter.drawRect(5, 30, energy, 20);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::black);
    painter.drawRect(5, 5, 300, 20);
    painter.drawRect(5, 30, 300, 20);

    drawHealthbar(painter);

    if (player.isBuffed())
    {
        timeCircle.setClock(clock);
        painter.drawPixmap(timeCircle.getTarget(), timeCircle.getTexture(), timeCircle.getSource());
    }
}

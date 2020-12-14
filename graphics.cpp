#include "graphics.h"
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <QDebug>

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
    else
    {
        switch (event->key())
        {
        case (Qt::Key_Right):
            player.setDirection(leftRight);
            if (player.getState() != Jump && player.getState() != Fall)
            {
                player.setState(Run);
            }
            rightIsPressed = true;
            break;
        case (Qt::Key_Left):
            player.setDirection(rightLeft);
            if (player.getState() != Jump && player.getState() != Fall)
            {
                player.setState(Run);
            }
            leftIsPressed = true;
            break;
        case (Qt::Key_Down):
            if (player.getState() != Jump && player.getState() != Fall)
            {
                player.setState(Stand);
            }
            break;
        case (Qt::Key_Space):
            if (player.getState() != Jump && player.getState() != Fall)
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
            if (player.getState() != Jump && player.getState() != Fall)
            {
                if (player.getState() != Attack)
                {
                    player.setState(Attack);
                    cIsPressed = true;
                }
            }
            break;
        case (Qt::Key_Z):
            if (player.getState() != Jump && player.getState() != Fall)
            {
                player.setState(Buff);
                zIsPressed = true;
            }
            break;
        }
    }
}

void graphics::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case (Qt::Key_Right):
        if (player.getState() != Jump && player.getState() != Fall)
        {
            player.setState(Stand);
        }
        rightIsPressed = false;
        break;
    case (Qt::Key_Left):
        if (player.getState() != Jump && player.getState() != Fall)
        {
            player.setState(Stand);
        }
        leftIsPressed = false;
        break;
    case (Qt::Key_Down):
        if (player.getState() != Jump && player.getState() != Fall)
        {
            player.setState(Stand);
        }
        break;
    case (Qt::Key_Space):
        spaceIsPressed = false;
        break;
    case (Qt::Key_Return):
        enterIsPressed = false;
        break;
    case (Qt::Key_C):
        cIsPressed = false;
        break;
    case (Qt::Key_Z):
        if (player.getState() != Jump && player.getState() != Fall)
        {
            player.setState(Stand);
        }
        zIsPressed = false;
        break;
    }
    if (!spaceIsPressed && !rightIsPressed && !leftIsPressed && !enterIsPressed && !cIsPressed && !zIsPressed)
    {
        allKeysReleased = true;
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
    else if (!initialed)
    {
        acceptInput = true;
        initial();
    }
    else if (!paused)
    {
        player.setClock();

        if (player.getState() != Jump)
        {
            if (!isGround(player.getLowestPoint()))
            {
                player.setState(Fall);
            }
            else if (player.getState() == Fall) player.setState(Stand);
        }

        checkWall();

        if (player.getPosition().x() > width()/2 && map.getMapLimit(2).x() != width())
        {
            map.move(-player.getSpeed());
            groundArray = map.getGrounds();
            wallArray = map.getWalls();
            player.setPosition(width()/2, player.getPosition().y());
        }
        else if (player.getPosition().x() < width()/2 && map.getMapLimit(1).x() != 0)
        {
            map.move(player.getSpeed());
            groundArray = map.getGrounds();
            wallArray = map.getWalls();
            player.setPosition(width()/2, player.getPosition().y());
        }
        else if (player.getPosition().y() > player.getLimitArea(2).y())
        {
            goto hell;
        }
        painter.drawRect(player.getPointHitBox(1).x(), player.getPointHitBox(1).y(), player.getWidth(), player.getHeight());//delete this
        painter.drawPixmap(player.getTarget(), player.getTexture(), player.getSource());
        drawHealthbar(painter);

    }
    if (false)
    {
hell:        youDie();
    }
}

void graphics::initial()
{
    initialed = true;
    clock = 0;
    //qDebug() << width() << "; " << height();
    map = Map();
    map.setViewPort(width(), height());
    groundArray = map.getGrounds();
    wallArray = map.getWalls();

    player.setOrigin(200, height() - 400 - player.getHeight());
    player.setLimitArea(100, 0, width() - 100, height());
}

void graphics::youDie()
{
    dying = true;
    acceptInput = false;
    paused = true;
    initialed = false;
}

bool graphics::isGround(QPointF lowestPoint)
{
    for (unsigned int j = 0; j < groundArray.size(); j++)
    {
        if (lowestPoint.x() < groundArray[j].getPointHitBox(1).x()
                || lowestPoint.x() > groundArray[j].getPointHitBox(3).x())
            continue;
        if (lowestPoint.y() < groundArray[j].getPointHitBox(1).y() - 30
                || lowestPoint.y() > groundArray[j].getPointHitBox(1).y())
            continue;
        player.setPosition(player.getPosition().x(), groundArray[j].getHighestY() - player.getHeight());
        return true;
    }
    return false;
}

void graphics::checkWall()
{
    for (unsigned int j = 0; j < wallArray.size(); j++)
    {
        if ((player.getPointHitBox(3).y() > wallArray[j].getPointHitBox(1).y()
                && player.getPointHitBox(3).y() < wallArray[j].getPointHitBox(2).y())
                ||
                (player.getPointHitBox(4).y() > wallArray[j].getPointHitBox(1).y()
                && player.getPointHitBox(4).y() < wallArray[j].getPointHitBox(2).y())
                ||
                (player.getPointHitBox(3).y() < wallArray[j].getPointHitBox(1).y()
                && player.getPointHitBox(4).y() > wallArray[j].getPointHitBox(2).y())
                ||
                (player.getPointHitBox(3).y() > wallArray[j].getPointHitBox(1).y()
                && player.getPointHitBox(4).y() < wallArray[j].getPointHitBox(2).y()))
        {
            if (player.getPointHitBox(3).x() > wallArray[j].getPointHitBox(1).x()
                    && player.getPointHitBox(3).x() < wallArray[j].getPointHitBox(3).x())
            {
                player.setPosition(wallArray[j].getLeftX() - player.getWidth(), player.getPosition().y());
            }
        }
        if ((player.getPointHitBox(1).y() > wallArray[j].getPointHitBox(3).y()
                  && player.getPointHitBox(1).y() < wallArray[j].getPointHitBox(4).y())
                  ||
                  (player.getPointHitBox(2).y() > wallArray[j].getPointHitBox(3).y()
                  && player.getPointHitBox(2).y() < wallArray[j].getPointHitBox(4).y())
                  ||
                  (player.getPointHitBox(1).y() < wallArray[j].getPointHitBox(3).y()
                  && player.getPointHitBox(2).y() > wallArray[j].getPointHitBox(4).y())
                  ||
                  (player.getPointHitBox(1).y() > wallArray[j].getPointHitBox(3).y()
                  && player.getPointHitBox(2).y() < wallArray[j].getPointHitBox(4).y()))
        {
            if (player.getPointHitBox(1).x() < wallArray[j].getPointHitBox(3).x()
                    && player.getPointHitBox(1).x() > wallArray[j].getPointHitBox(1).x())
            {
                player.setPosition(wallArray[j].getRightX(), player.getPosition().y());
            }
        }
    }
}

void graphics::drawHealthbar(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::green);
    painter.drawRect(player.getPosition().x(),
                     player.getPosition().y() - 14,
                     (player.getWidth())*((double)player.getLeftHealth() / player.getFullHealth()),
                     5);


    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::black);
    painter.drawRect(player.getPosition().x(),
                     player.getPosition().y() - 14,
                     (player.getWidth()),
                     5);

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
    double health = 300*((double)player.getLeftHealth() / player.getFullHealth());
    painter.drawRect(5, 5, health, 20);
    painter.setBrush(Qt::blue);
    double energy = 300*((double)player.getLeftEnergy() / player.getFullEnergy());
    painter.drawRect(5, 30, energy, 20);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::black);
    painter.drawRect(5, 5, 300, 20);
    painter.drawRect(5, 30, 300, 20);
}

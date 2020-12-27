#include "graphics.h"
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <QDebug>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    startTimer(33);
    background.setTexture(":/images/backgrounds/firstBg.png", 1, 1);
    background.setPosition(0, 0);

    energyPotionIcon.setTexture(":/images/icons/energyPotion.png", 1, 10);
    healthPotionIcon.setTexture(":/images/icons/heartPotion.png", 1, 9);
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
    if (!acceptInput)
    {
        if (event->key() == Qt::Key_Return)
        {
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
            break;
        case (Qt::Key_C):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                if (player.getState() != Attack)
                {
                    player.setState(Attack);
                }
            }
            else if ((player.getState() == Jump || player.getState() == Fall) && player.getState() != JumpAttack)
            {
                player.setState(JumpAttack);
            }
            break;
        case (Qt::Key_Z):
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Buff);
            }
            break;
        case (Qt::Key_H):
            if (player.isHacked()) player.hackOFF();
            else player.hackON();
            break;
        case (Qt::Key_1):
            player.useHealthPotion();
            break;
        case (Qt::Key_2):
            player.useEnergyPotion();
            break;
        case (Qt::Key_3):
            player.useSkill1();
            break;
        case (Qt::Key_4):
            player.useSkill2();
            break;
        case (Qt::Key_5):
            player.useSkill3();
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
        case (Qt::Key_Z):   //hold 16 * 33miliseconds
            if (player.getState() != Jump && player.getState() != Fall && player.getState() != JumpAttack)
            {
                player.setState(Stand);
            }
            break;
        }
    }
}

void graphics::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (!clock)     //only paintEvent know window height and width
    {
        painter.drawPixmap(background.getTarget(), background.getTexture(), background.getSource());
    }

    if (clock) //draw map
    {
        map.draw(painter);
    }

    if (paused && !dying)
    {
        drawText(painter, QRectF(width()/2 - 200, height()/2 + 200, width(), height()), Qt::cyan, 32, "Press Enter to start");
    }
    else if (paused && dying)
    {
        //draw the dead body
        player.draw(painter);;
        //make sure the dead body will stay still in the ground
        checkCollision();

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
        player.draw(painter);
        map.getPlayerSprites(player.getSprites());
        drawHUD(painter);
        checkCollision();
        if (player.getLeftHealth() <= 0) youDie();
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
    player.setPosition(200, height() - 400 - player.getHeight());

    timeCircle.setTexture(":/images/backgrounds/timeCircle.png", 17, 1);
    timeCircle.setPosition(width()/2, 20);
}

void graphics::youDie()
{
    player.setState(Dying);
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
        else if (player.getState() == Dying)
        {
            player.setPosition(player.getPosition().x(), player.getPosition().y() + fallingRangeEachTimeID);
        }
        else player.setState(Fall);
    }
    checkWall();
    checkMoveMap();
    checkVision();
    checkRedCollision();
    checkBlueCollision();
    checkPotionsCollision();

    if (player.getPosition().y() > height())
    {
        youDie();
    }

}

void graphics::checkBlueCollision()
{
    for (unsigned int i = 0; i < map.getNPCs().size(); i++)
    {
//        if (player.getBlueCollisions().size() > 0)
//            qDebug() << player.getBlueCollisions().size();
        for (unsigned int j = 0; j < player.getBlueCollisions().size(); j++)
        {
            if (player.getBlueCollisions()[j].box.intersects(map.getNPCs()[i]->getHitBox()))
            {
                if (map.getNPCs()[i]->getDirection() == player.getDirection())
                {
                    map.getNPCs()[i]->isBeingAttacked(player.getBlueCollisions()[j].damage * 2);
                }
                else
                {
                    map.getNPCs()[i]->isBeingAttacked(player.getBlueCollisions()[j].damage);
                }
                if (map.getNPCs()[i]->getLeftHealth() <= 0)
                {
                    map.deleteNPCAt(i);
                }
            }
        }
    }
}

void graphics::checkPotionsCollision()
{
    for (unsigned int i = 0; i < map.getEnergyPotions().size(); i++)
    {
        if (player.getHitBox().intersects(map.getEnergyPotions()[i]->getHitBox()))
        {
            //player.setEnergy(min(player.getLeftEnergy() + 500, player.getFullEnergy()));
            player.setEnergyPotionNumber(player.getEnergyPotionNumber() + 1);
            map.deleteEnergyAt(i);
        }
    }
    for (unsigned int i = 0; i < map.getHealthPotions().size(); i++)
    {
        if (player.getHitBox().intersects(map.getHealthPotions()[i]->getHitBox()))
        {
            //player.setHealth(min(player.getLeftHealth() + 500, player.getFullHealth()));
            player.setHealthPotionNumber(player.getHealthPotionNumber() + 1);
            map.deleteHealthAt(i);
        }
    }
}

void graphics::checkRedCollision()
{
    for (unsigned int i = 0; i < map.getRedCollisions().size(); i++)
    {
        if (player.getHitBox().intersects(map.getRedCollisions()[i].box))
        {
            player.setHealth(max(0, player.getLeftHealth() - map.getRedCollisions()[i].damage));
        }
    }
}

void graphics::checkVision()
{
    if (player.getState() != Dying)
    {
        for (unsigned int i = 0; i < map.getNPCs().size(); i++)
        {
            if (player.getHitBox().intersects(map.getNPCs()[i]->getVisionArea()))
            {
                map.getNPCs()[i]->isSeeingSomethingSus();
            }
            if (player.getHitBox().intersects(map.getNPCs()[i]->getAttackArea()))
            {
                map.getNPCs()[i]->setState(Attacking);
            }
        }
    }
}

bool graphics::isGround()
{
    for (unsigned int i = 0; i < map.getEnergyPotions().size(); i++)
    {
        for (unsigned int j = 0; j < grounds.size(); j++)
        {
            if (QRectF(grounds[j].getHitBox().topLeft().x(), grounds[j].getHitBox().topLeft().y(),
                       grounds[j].getHitBox().width(), 30).contains(
                        QPointF((map.getEnergyPotions()[i]->getHitBox().bottomLeft().x()
                                + map.getEnergyPotions()[i]->getHitBox().bottomRight().x()) / 2
                                , map.getEnergyPotions()[i]->getHitBox().bottomLeft().y())))
            {
                goto next;
            }
        }
        map.getEnergyPotions()[i]->setPosition(map.getEnergyPotions()[i]->getPosition().x(),
                                               map.getEnergyPotions()[i]->getPosition().y() + fallingRangeEachTimeID);
next:   continue;
    }
    for (unsigned int i = 0; i < map.getHealthPotions().size(); i++)
    {
        for (unsigned int j = 0; j < grounds.size(); j++)
        {
            if (QRectF(grounds[j].getHitBox().topLeft().x(), grounds[j].getHitBox().topLeft().y(),
                       grounds[j].getHitBox().width(), 30).contains(
                        QPointF((map.getHealthPotions()[i]->getHitBox().bottomLeft().x()
                                + map.getHealthPotions()[i]->getHitBox().bottomRight().x()) / 2
                                , map.getHealthPotions()[i]->getHitBox().bottomLeft().y())))
            {
                goto next2;
            }
        }
        map.getHealthPotions()[i]->setPosition(map.getHealthPotions()[i]->getPosition().x(),
                                               map.getHealthPotions()[i]->getPosition().y() + fallingRangeEachTimeID);
next2:   continue;
    }
    for (unsigned int i = 0; i < grounds.size(); i++)
    {
        if (QRectF(grounds[i].getHitBox().topLeft().x(), grounds[i].getHitBox().topLeft().y(),
                   grounds[i].getHitBox().width(), 30).contains(player.getLowestPoint()))
        {
            if (player.getSpeed() >= 10)
            {
                if (onLandTime >= maxOnLandTime)
                {
                    if (player.getDirection() == leftRight)
                    {
                        map.generateDirtAt(player.getHitBox().bottomLeft());
                    }
                    else
                    {
                        map.generateDirtAt(player.getHitBox().bottomRight());
                    }
                }
                onLandTime++;
            }
            else
            {
                onLandTime = 0;
            }
            //map.generateDirtAt(player.getHitBox().bottomLeft());
            player.setPosition(player.getPosition().x(), grounds[i].getHitBox().topLeft().y() - player.getHeight());
            return true;
        }
    }
    return false;
}

void graphics::checkWall()
{
    for (unsigned int i = 0; i < walls.size(); i++)
    {
        if (walls[i].getHitBox().contains(player.getHitBox().topRight())
                || walls[i].getHitBox().contains(player.getHitBox().bottomRight()))
        {
            player.setPosition(walls[i].getHitBox().topLeft().x() - player.getWidth(), player.getPosition().y());
        }
        else if (walls[i].getHitBox().contains(player.getHitBox().topLeft())
                 || walls[i].getHitBox().contains(player.getHitBox().bottomLeft()))
        {
            player.setPosition(walls[i].getHitBox().topRight().x() + player.getSpeed(), player.getPosition().y());
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
    painter.setBrush(Qt::white);
    painter.setPen(Qt::black);
    painter.drawRect(player.getPosition().x(), player.getPosition().y() - 14,
                     player.getWidth(), 5);

    for (unsigned int i = 0; i < map.getNPCs().size(); i++)
    {
        painter.drawRect(map.getNPCs()[i]->getPosition().x(), map.getNPCs()[i]->getPosition().y() - 14,
                         (map.getNPCs()[i]->getWidth()), 5);
    }

    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);
    painter.drawRect(player.getPosition().x(), player.getPosition().y() - 14,
                     player.getWidth()*((double)player.getLeftHealth()
                                          / player.getFullHealth()), 5);
    for (unsigned int i = 0; i < map.getNPCs().size(); i++)
    {
        painter.drawRect(map.getNPCs()[i]->getPosition().x(), map.getNPCs()[i]->getPosition().y() - 14,
                         (map.getNPCs()[i]->getWidth())*((double)map.getNPCs()[i]->getLeftHealth()
                                                         / map.getNPCs()[i]->getFullHealth()), 5);
    }

    painter.setBrush(Qt::NoBrush);
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
        timeCircle.setClock();
        painter.drawPixmap(timeCircle.getTarget(), timeCircle.getTexture(), timeCircle.getSource());
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(60, 70, 70, 100);
    painter.drawRect(20, 180, 70, 100);
    painter.drawRect(100, 180, 70, 100);
    painter.setBrush(Qt::black);
    painter.drawRect(65, 75, 60, 90);
    painter.drawRect(25, 185, 60, 90);
    painter.drawRect(105, 185, 60, 90);

    painter.drawPixmap(player.getAvatar().getTarget(),
                       player.getAvatar().getTexture(),
                       player.getAvatar().getSource()); // draw Avatar Character
    healthPotionIcon.setPosition(35, 205);
    if (player.getHealthPotionNumber() > 0)
    {
        painter.drawPixmap(healthPotionIcon.getTarget(),
                           healthPotionIcon.getTexture(),
                           healthPotionIcon.getSource());
    }
    painter.setBrush(Qt::white);
    painter.drawEllipse(QRectF(70, 185 + 80, 20, 20));
    drawText(painter, QRectF(75, 185 + 80, 100, 100), Qt::darkCyan, 12, QString::number(player.getHealthPotionNumber()));
    energyPotionIcon.setPosition(120, 205);
    if (player.getEnergyPotionNumber() > 0)
    {
        painter.drawPixmap(energyPotionIcon.getTarget(),
                           energyPotionIcon.getTexture(),
                           energyPotionIcon.getSource());
    }
    painter.drawEllipse(QRectF(150, 185 + 80, 20, 20));
    drawText(painter, QRectF(155, 185 + 80, 100, 100), Qt::darkCyan, 12, QString::number(player.getEnergyPotionNumber()));
}

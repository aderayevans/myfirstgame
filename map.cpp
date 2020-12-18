#include "map.h"

#include <QDebug>

Map::Map()
{
    mapLimitPoint1.setX(0);
    mapLimitPoint1.setY(0);
    mapLimitPoint2.setX(8000);
    mapLimitPoint2.setY(0);

    backgrounds[0].setTexture("D://Games//Toshizo//bgLayer0.png", 1, 1);
    backgrounds[1].setTexture("D://Games//Toshizo//bgLayer1.png", 1, 1);
    backgrounds[2].setTexture("D://Games//Toshizo//bgLayer2.png", 1, 1);
    backgrounds[3].setTexture("D://Games//Toshizo//bgLayer3.png", 1, 1);
    backgrounds[4].setTexture("D://Games//Toshizo//bgLayer4.png", 1, 1);
    backgrounds[5].setTexture("D://Games//Toshizo//bgLayer5.png", 1, 1);
    backgrounds[6].setTexture("D://Games//Toshizo//bgLayer6.png", 1, 1);
    backgrounds[7].setTexture("D://Games//Toshizo//bgLayer7.png", 1, 1);
    for (int i = 0; i < bgLayers; i++)
    {
        backgrounds[i].setOrigin(0, 0);
    }

    Ground ground01, ground02, ground03, ground04, ground05, g[100];
    ground01 = Ground(7);
    ground01.setOrigin(150, 610);
    ground02 = Ground(6);
    ground02.setOrigin(350, 560);
    ground03 = Ground(5);
    ground03.setOrigin(720, 460);
    ground04 = Ground(4);
    ground04.setOrigin(920, 360);
    ground05 = Ground(8);
    ground05.setOrigin(1600, 260);
    grounds.push_back(ground01);
    grounds.push_back(ground02);
    grounds.push_back(ground03);
    grounds.push_back(ground04);
    grounds.push_back(ground05);
    for (int i = 0; i < 50; i++)
    {
        g[i] = Ground(1);
        g[i].setOrigin((g[i].getWidth() - 2)*i, 710);
        grounds.push_back(g[i]);
    }


    Wall wall01, wall02;
    wall01.setOrigin(70, 100);
    wall02.setOrigin(70, 431);
    walls.push_back(wall01);
    walls.push_back(wall02);

    //NPC
    NPC wraith01;
    wraith01.setOrigin(2000, 300);
    wraiths.push_back(wraith01);
}

void Map::setClock()
{
    backgrounds[3].setPosition(backgrounds[3].getPosition().x() - 1, backgrounds[3].getPosition().y());
    backgrounds[4].setPosition(backgrounds[4].getPosition().x() + 1.5, backgrounds[4].getPosition().y());
    backgrounds[5].setPosition(backgrounds[5].getPosition().x() + 2, backgrounds[5].getPosition().y());

    clock++;
    if (clock % 6 == 0) cloud = -cloud;

    for (unsigned int i = 0; i < wraiths.size(); i++)
    {
        wraiths[i].setClock();
    }
}

void Map::draw(QPainter &painter)
{
    for (int i = 0; i < bgLayers - 2; i++)
    {
        if (backgrounds[i].getPosition().x() >= width)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setOrigin(backgrounds[i].getPosition().x() - backgrounds[i].getWidth() + 1, backgrounds[i].getPosition().y());
            backgrounds[i] = tempBg;
        }
        else if (backgrounds[i].getPosition().x() + backgrounds[i].getWidth() <= 0)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setOrigin(backgrounds[i].getPosition().x() + backgrounds[i].getWidth() - 1, backgrounds[i].getPosition().y());
            backgrounds[i] = tempBg;
        }
        else if (backgrounds[i].getPosition().x() > 0)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setOrigin(backgrounds[i].getPosition().x() - backgrounds[i].getWidth() + 1, backgrounds[i].getPosition().y());
            painter.drawPixmap(tempBg.getTarget(), tempBg.getTexture(), tempBg.getSource());
        }
        else if (backgrounds[i].getPosition().x() < 0)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setOrigin(backgrounds[i].getPosition().x() + backgrounds[i].getWidth() - 1, backgrounds[i].getPosition().y());
            painter.drawPixmap(tempBg.getTarget(), tempBg.getTexture(), tempBg.getSource());
        }
        painter.drawPixmap(backgrounds[i].getTarget(), backgrounds[i].getTexture(), backgrounds[i].getSource());
    }


    if (cloud == 1)
    {
        painter.drawPixmap(backgrounds[6].getTarget(), backgrounds[6].getTexture(), backgrounds[6].getSource());
    }
    else
    {
        painter.drawPixmap(backgrounds[7].getTarget(), backgrounds[7].getTexture(), backgrounds[7].getSource());
    }

    for (unsigned int i = 0; i < currentGrounds.size(); i++)
    {
//        painter.drawRect(currentGrounds[i].getPointHitBox(1).x(), currentGrounds[i].getPointHitBox(1).y(),
//                         currentGrounds[i].getPointHitBox(3).x() - currentGrounds[i].getPointHitBox(1).x(),
//                         currentGrounds[i].getPointHitBox(4).y() - currentGrounds[i].getPointHitBox(3).y());//delete this
        painter.drawPixmap(currentGrounds[i].getTarget(), currentGrounds[i].getTexture(), currentGrounds[i].getSource());
    }
    for (unsigned int i = 0; i < currentWalls.size(); i++)
    {
//        painter.drawRect(currentWalls[i].getPointHitBox(1).x(), currentWalls[i].getPointHitBox(1).y(),
//                         currentWalls[i].getPointHitBox(3).x() - currentWalls[i].getPointHitBox(1).x(),
//                         currentWalls[i].getPointHitBox(4).y() - currentWalls[i].getPointHitBox(3).y());//delete this
        painter.drawPixmap(currentWalls[i].getTarget(), currentWalls[i].getTexture(), currentWalls[i].getSource());
    }
    for (unsigned int i = 0; i < wraiths.size(); i++)
    {
        painter.drawPixmap(wraiths[i].getTarget(), wraiths[i].getTexture(), wraiths[i].getSource());
//        painter.drawRect(wraiths[i].getPointHitBox(1).x(), wraiths[i].getPointHitBox(1).y(),
//                         wraiths[i].getPointHitBox(3).x() - wraiths[i].getPointHitBox(1).x(),
//                         wraiths[i].getPointHitBox(4).y() - wraiths[i].getPointHitBox(3).y());//delete this
    }
}

void Map::move(double tx)
{
    mapLimitPoint1.setX(mapLimitPoint1.x() + tx);
    mapLimitPoint2.setX(mapLimitPoint2.x() + tx);

    backgrounds[1].setPosition(backgrounds[1].getPosition().x() + tx / 100, backgrounds[1].getPosition().y());
    backgrounds[2].setPosition(backgrounds[2].getPosition().x() + tx / 10, backgrounds[2].getPosition().y());

    for (unsigned int i = 0; i < grounds.size(); i++)
    {
        grounds[i].setPosition(grounds[i].getPosition().x() + tx, grounds[i].getPosition().y());
    }
    for (unsigned int i = 0; i < walls.size(); i++)
    {
        walls[i].setPosition(walls[i].getPosition().x() + tx, walls[i].getPosition().y());
    }
    for (unsigned int i = 0; i < wraiths.size(); i++)
    {
        wraiths[i].setPosition(wraiths[i].getPosition().x() + tx, wraiths[i].getPosition().y());
    }

    clip();
}

void Map::clip()
{
    std::vector<Ground> temp_grounds;
    std::vector<Wall> temp_walls;

    for (unsigned int i = 0; i < grounds.size(); i++)
    {
        if (grounds[i].getLimitArea(1).x() > xvMax || grounds[i].getLimitArea(3).x() < xvMin) continue;
        temp_grounds.push_back(grounds[i]);
    }
    for (unsigned int i = 0; i < walls.size(); i++)
    {
        if (walls[i].getLimitArea(1).x() > xvMax || walls[i].getLimitArea(3).x() < xvMin) continue;
        temp_walls.push_back(walls[i]);
    }
    currentGrounds = temp_grounds;
    currentWalls = temp_walls;
}

void Map::convert()
{
    xvMin = 0;
    xvMax = width;
    yvMin = 0;
    yvMax = height;
}

void Map::setViewPort(double width, double height)
{
    this->width = width;
    this->height = height;
    convert();
    clip();
}

std::vector<Ground> Map::getGrounds()
{
    return currentGrounds;
}

std::vector<Wall> Map::getWalls()
{
    return currentWalls;
}

QPoint Map::getMapLimit(int number)
{
    if (number == 1)
    {
        return mapLimitPoint1;
    }
    else
    {
        return mapLimitPoint2;
    }
}

#include "map.h"

#include <QDebug>

Map::Map()
{
    mapLimitPoint1.setX(0);
    mapLimitPoint1.setY(0);
    mapLimitPoint2.setX(8000);
    mapLimitPoint2.setY(0);

    backgrounds[0].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer0.png", 1, 1);
    backgrounds[1].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer1.png", 1, 1);
    backgrounds[2].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer2.png", 1, 1);
    backgrounds[3].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer3.png", 1, 1);
    backgrounds[4].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer4.png", 1, 1);
    backgrounds[5].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer5.png", 1, 1);
    backgrounds[6].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer6.png", 1, 1);
    backgrounds[7].setTexture("D://Users//Downloads//ToshizoGameAsset//bgLayer7.png", 1, 1);
    for (int i = 0; i < bgLayers; i++)
    {
        backgrounds[i].setOrigin(0, 0);
    }


    bee.setTexture("D://Users//Downloads//beeToRight.png", "D://Users//Downloads//bee.png", 1, 2);
    bee.setSpeed(10);
    bee.setOrigin(200, 200);
    bee.setLimitArea(200, 200, 600, 200);

    Ground ground01, ground02, ground03, ground04, ground05, g[100];
    ground01 = Ground(7);
    ground01.setOrigin(150, 610);
    ground02 = Ground(6);
    ground02.setOrigin(350, 560);
    ground03 = Ground(5);
    ground03.setOrigin(720, 460);
    ground04 = Ground(4);
    ground04.setOrigin(920, 710);
    ground05 = Ground(8);
    ground05.setOrigin(1600, 610);
    grounds.push_back(ground01);
    grounds.push_back(ground02);
    grounds.push_back(ground03);
    grounds.push_back(ground04);
    grounds.push_back(ground05);
    for (int i = 6; i < 50; i++)
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
}

void Map::setClock()
{
    backgrounds[3].setPosition(backgrounds[3].getPosition().x() - 1, backgrounds[3].getPosition().y());
    backgrounds[4].setPosition(backgrounds[4].getPosition().x() + 1.5, backgrounds[4].getPosition().y());
    backgrounds[5].setPosition(backgrounds[5].getPosition().x() + 2, backgrounds[5].getPosition().y());
    bee.setClock();
    clock++;
    if (clock % 10 == 0) cloud = -cloud;
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

    painter.drawPixmap(bee.getTarget(), bee.getTexture(), bee.getSource());
    for (unsigned int i = 0; i < currentGrounds.size(); i++)
    {
        painter.drawPixmap(currentGrounds[i].getTarget(), currentGrounds[i].getTexture(), currentGrounds[i].getSource());
    }
    for (unsigned int i = 0; i < currentWalls.size(); i++)
    {
        painter.drawPixmap(currentWalls[i].getTarget(), currentWalls[i].getTexture(), currentWalls[i].getSource());
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
    clip();
}

void Map::clip()
{
    //cur_bg = background.getTexture().copy(xvMin - background.getPointHitBox(1).x(), 0, xvMax, yvMax);
    Ground temp_ground;
    std::vector<Ground> temp_grounds;
    Wall temp_wall;
    std::vector<Wall> temp_walls;
    double range;

    for (unsigned int i = 0; i < grounds.size(); i++)
    {
        if (grounds[i].getLimitArea(1).x() > xvMax || grounds[i].getLimitArea(3).x() < xvMin) continue;
        else if (grounds[i].getLimitArea(1).x() < xvMin && grounds[i].getLimitArea(3).x() > xvMin)
        {
            temp_ground = grounds[i];
            range = xvMin - temp_ground.getLimitArea(1).x();
            temp_ground.setTexture(temp_ground.getTexture().copy(range, 0, temp_ground.getWidth() - range, temp_ground.getHeight()));
            temp_ground.setPosition(temp_ground.getPosition().x() + range, temp_ground.getPosition().y());
            temp_grounds.push_back(temp_ground);
        }
        else if (grounds[i].getLimitArea(1).x() < xvMax && grounds[i].getLimitArea(3).x() > xvMax)
        {
            temp_ground = grounds[i];
            temp_ground.setTexture(temp_ground.getTexture().copy(0, 0, temp_ground.getWidth() - (temp_ground.getLimitArea(3).x() - xvMax), temp_ground.getHeight()));
            temp_grounds.push_back(temp_ground);
        }
        else
        {
            temp_ground = grounds[i];
            temp_grounds.push_back(temp_ground);
        }
    }
    for (unsigned int i = 0; i < walls.size(); i++)
    {
        if (walls[i].getLimitArea(1).x() > xvMax || walls[i].getLimitArea(3).x() < xvMin) continue;
        else if (walls[i].getLimitArea(1).x() < xvMin && walls[i].getLimitArea(3).x() > xvMin)
        {
            temp_wall = walls[i];
            range = xvMin - temp_wall.getLimitArea(1).x();
            temp_wall.setTexture(temp_wall.getTexture().copy(range, 0, temp_wall.getWidth() - range, temp_wall.getHeight()));
            temp_wall.setPosition(temp_wall.getPosition().x() + range, temp_wall.getPosition().y());
            temp_walls.push_back(temp_wall);
        }
        else if (walls[i].getLimitArea(1).x() < xvMax && walls[i].getLimitArea(3).x() > xvMax)
        {
            temp_wall = walls[i];
            temp_wall.setTexture(temp_wall.getTexture().copy(0, 0, temp_wall.getWidth() - (temp_wall.getLimitArea(3).x() - xvMax), temp_wall.getHeight()));
            temp_walls.push_back(temp_wall);
        }
        else
        {
            temp_wall = walls[i];
            temp_walls.push_back(temp_wall);
        }
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

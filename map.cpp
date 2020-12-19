#include "map.h"

#include <QDebug>

Map::Map()
{
    mapLimitPointLeft.setX(0);
    mapLimitPointLeft.setY(0);
    mapLimitPointRight.setX(8000);
    mapLimitPointRight.setY(0);
    pseudoLimitPointLeft = mapLimitPointLeft;
    pseudoLimitPointRight = mapLimitPointRight;

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
    for (int i = 0; i < 100; i++)
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
    Wraith *wraith01 = new Wraith();
    wraith01->setOrigin(2000, 300);
    NPCs.push_back(wraith01);

    Wraith *wraith02 = new Wraith();
    wraith02->setOrigin(2500, 300);
    NPCs.push_back(wraith02);

    Kong *kong01 = new Kong();
    kong01->setOrigin(1000, 610);
    kong01->setLimitArea(200, kong01->getPosition().y(), 1200, kong01->getPosition().y() + kong01->getHeight());
    NPCs.push_back(kong01);


    //...
    for (int i = 0; i < energyPotionNum; i++)
    {
        Sprite temp;
        temp.setTexture("D://Games//Toshizo//energyPotion.png", 1, 10);
        temp.setOrigin(1000 + (100 * i), 600);
        energyPotions.push_back(temp);
    }
    for (int i = 0; i < healthPotionNum; i++)
    {
        Sprite temp;
        temp.setTexture("D://Games//Toshizo//healthPotion.png", 1, 9);
        temp.setOrigin(1250 + (100 * i), 600);
        healthPotions.push_back(temp);
    }

    magicGateY1.setTexture("D://Games//Toshizo//magicGateY.png", 12, 1);
    magicGateY1.setOrigin(1800, 400);
    magicGateY2.setTexture("D://Games//Toshizo//flippedMagicGateY.png", 12, 1);
    magicGateY2.setOrigin(1700, 200);

    magicGateX.setTexture("D://Games//Toshizo//magicGate2.png", 12, 1);
    magicGateX.setOrigin(1800, 100);

    magicGate.setTexture("D://Games//Toshizo//magicGate1.png", 20, 1);
    magicGate.setOrigin(2300, 200);

    fireBall.setTexture("D://Games//Toshizo//fireBall.png", 25, 1);
    fireBall.setOrigin(1750, 450);
    darkBall.setTexture("D://Games//Toshizo//darkBall.png", 8, 5);
    darkBall.setOrigin(1200, 450);
    tornado.setTexture("D://Games//Toshizo//water-tornado.png", 4, 1);
    tornado.setOrigin(1500, 450);

    explosion2.setTexture("D://Games//Toshizo//explosion.png", 4, 1);
    explosion2.setOrigin(2400, 450);
    //Sprite magicGate, magicGateX1, magicGateX2, magicGateY, fireBall, darkBall, posion, bum, tornado, aura, explosion2;
}

void Map::setClock()
{
    backgrounds[3].setPosition(backgrounds[3].getPosition().x() - 1, backgrounds[3].getPosition().y());
    backgrounds[4].setPosition(backgrounds[4].getPosition().x() + 1.5, backgrounds[4].getPosition().y());
    backgrounds[5].setPosition(backgrounds[5].getPosition().x() + 2, backgrounds[5].getPosition().y());

    clock++;
    if (clock % 6 == 0) cloud = -cloud;

    for (unsigned int i = 0; i < NPCs.size(); i++)
    {
        NPCs[i]->setClock();
    }

    //...
    magicGateY1.setClock(clock);
    magicGateY2.setClock(clock);
    magicGateX.setClock(clock);
    magicGate.setClock(clock);
    fireBall.setClock(clock);
    darkBall.setClock(clock);
    tornado.setClock(clock);
    explosion2.setClock(clock);
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
    for (unsigned int i = 0; i < NPCs.size(); i++)
    {
        painter.drawPixmap(NPCs[i]->getTarget(), NPCs[i]->getTexture(), NPCs[i]->getSource());
        painter.drawRect(NPCs[i]->getPointHitBox(1).x(), NPCs[i]->getPointHitBox(1).y(),
                         NPCs[i]->getPointHitBox(4).x() - NPCs[i]->getPointHitBox(2).x(),
                         NPCs[i]->getPointHitBox(4).y() - NPCs[i]->getPointHitBox(3).y());//delete this

        painter.drawRect(NPCs[i]->getVisionArea(1).x(), NPCs[i]->getVisionArea(1).y(),
                         NPCs[i]->getVisionArea(4).x() - NPCs[i]->getVisionArea(2).x(),
                         NPCs[i]->getVisionArea(4).y() - NPCs[i]->getVisionArea(3).y());//delete this

        painter.drawRect(NPCs[i]->getLimitArea(1).x(), NPCs[i]->getLimitArea(1).y(),
                         NPCs[i]->getLimitArea(4).x() - NPCs[i]->getLimitArea(2).x(),
                         NPCs[i]->getLimitArea(4).y() - NPCs[i]->getLimitArea(3).y());//delete this
    }

    //...
    for (int i = 0; i < energyPotionNum; i++)
    {
        painter.drawPixmap(energyPotions[i].getTarget(), energyPotions[i].getTexture(), energyPotions[i].getSource());
    }
    for (int i = 0; i < healthPotionNum; i++)
    {
        painter.drawPixmap(healthPotions[i].getTarget(), healthPotions[i].getTexture(), healthPotions[i].getSource());
    }

    painter.drawPixmap(magicGateY1.getTarget(), magicGateY1.getTexture(), magicGateY1.getSource());
    painter.drawPixmap(magicGateY2.getTarget(), magicGateY2.getTexture(), magicGateY2.getSource());
    painter.drawPixmap(magicGateX.getTarget(), magicGateX.getTexture(), magicGateX.getSource());
    painter.drawPixmap(magicGate.getTarget(), magicGate.getTexture(), magicGate.getSource());

    painter.drawPixmap(fireBall.getTarget(), fireBall.getTexture(), fireBall.getSource());
    painter.drawPixmap(darkBall.getTarget(), darkBall.getTexture(), darkBall.getSource());
    painter.drawPixmap(tornado.getTarget(), tornado.getTexture(), tornado.getSource());
    painter.drawPixmap(explosion2.getTarget(), explosion2.getTexture(), explosion2.getSource());
}

void Map::move(double tx)
{
    mapCurrentPointLeft.setX(mapCurrentPointLeft.x() - tx);
    mapCurrentPointRight.setX(mapCurrentPointRight.x() - tx);
    if (mapCurrentPointLeft.x() < pseudoLimitPointLeft.x())
    {
        move(- (pseudoLimitPointLeft.x() - mapCurrentPointLeft.x()));
    }
    if (mapCurrentPointRight.x() > pseudoLimitPointRight.x())
    {
        move(mapCurrentPointRight.x() - pseudoLimitPointRight.x());
    }


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
    for (unsigned int i = 0; i < NPCs.size(); i++)
    {
        NPCs[i]->setPosition(NPCs[i]->getPosition().x() + tx, NPCs[i]->getPosition().y());

        NPCs[i]->setLimitArea(NPCs[i]->getLimitArea(1).x() + tx,
                              NPCs[i]->getLimitArea(1).y(),
                              NPCs[i]->getLimitArea(4).x() + tx,
                              NPCs[i]->getLimitArea(4).y());
    }



    //...
    for (int i = 0; i < energyPotionNum; i++)
    {
        energyPotions[i].setPosition(energyPotions[i].getPosition().x() + tx, energyPotions[i].getPosition().y());
    }
    for (int i = 0; i < healthPotionNum; i++)
    {
        healthPotions[i].setPosition(healthPotions[i].getPosition().x() + tx, healthPotions[i].getPosition().y());
    }


    magicGateY1.setPosition(magicGateY1.getPosition().x() + tx, magicGateY1.getPosition().y());
    magicGateY2.setPosition(magicGateY2.getPosition().x() + tx, magicGateY2.getPosition().y());

    magicGateX.setPosition(magicGateX.getPosition().x() + tx, magicGateX.getPosition().y());

    magicGate.setPosition(magicGate.getPosition().x() + tx, magicGate.getPosition().y());


    fireBall.setPosition(fireBall.getPosition().x() + tx, fireBall.getPosition().y());
    darkBall.setPosition(darkBall.getPosition().x() + tx, darkBall.getPosition().y());
    tornado.setPosition(tornado.getPosition().x() + tx, tornado.getPosition().y());
    explosion2.setPosition(explosion2.getPosition().x() + tx, explosion2.getPosition().y());

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
    for (unsigned int i = 0; i < pseudoPoints.size(); i++)
    {
        if (pseudoPoints[i].x() <= mapCurrentPointRight.x())
        {
            pseudoLimitPointRight = pseudoPoints[i];
            pseudoLimitPointLeft = QPointF(pseudoPoints[i].x() - width, pseudoPoints[i].y());
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
    mapCurrentPointLeft = QPoint(0, 0);
    mapCurrentPointRight = QPoint(width, 0);
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

QPointF Map::getMapLimit(int number)
{
    if (number == 1)
    {
        return pseudoLimitPointLeft;
    }
    else
    {
        return pseudoLimitPointRight;
    }
}

QPointF Map::getCurrentMapPoint(int number)
{
    if (number == 1)
    {
        return mapCurrentPointLeft;
    }
    else
    {
        return mapCurrentPointRight;
    }
}

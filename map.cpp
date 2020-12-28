#include "map.h"

#include <QDebug>

Map::Map()
{
    mapLimitPointLeft.setX(0);
    mapLimitPointLeft.setY(0);
    mapLimitPointRight.setX(16000);
    mapLimitPointRight.setY(0);
    pseudoLimitPointLeft = mapLimitPointLeft;
    pseudoLimitPointRight = mapLimitPointRight;

    backgrounds[0].setTexture(":/images/backgrounds/bgLayer0.png", 1, 1);
    backgrounds[1].setTexture(":/images/backgrounds/bgLayer1.png", 1, 1);
    backgrounds[2].setTexture(":/images/backgrounds/bgLayer2.png", 1, 1);
    backgrounds[3].setTexture(":/images/backgrounds/bgLayer3.png", 1, 1);
    backgrounds[4].setTexture(":/images/backgrounds/bgLayer4.png", 1, 1);
    backgrounds[5].setTexture(":/images/backgrounds/bgLayer5.png", 1, 1);
    backgrounds[6].setTexture(":/images/backgrounds/bgLayer6.png", 1, 1);
    backgrounds[7].setTexture(":/images/backgrounds/bgLayer7.png", 1, 1);
    for (int i = 0; i < bgLayers; i++)
    {
        backgrounds[i].setPosition(0, 0);
    }
    double range = 1;
    for (int i = 0; i < 50; i++)
    {
        Ground ground01, ground02, ground03, ground04, ground05, g;
        ground01 = Ground(7);
        ground01.setPosition(150 * range, 610);
        ground02 = Ground(6);
        ground02.setPosition(350 * range, 560);
        ground03 = Ground(5);
        ground03.setPosition(720 * range, 460);
        ground04 = Ground(4);
        ground04.setPosition(920 * range, 360);
        ground05 = Ground(8);
        ground05.setPosition(1600 * range, 260);
        g = Ground(1);
        double landSpace = g.getWidth() - 2;
        g.setPosition(landSpace*i, 710);
        grounds.push_back(ground01);
        grounds.push_back(ground02);
        grounds.push_back(ground03);
        grounds.push_back(ground04);
        grounds.push_back(ground05);
        if (i % 7 == 0 && i != 0);
        else
        {
            grounds.push_back(g);
        }
        range *= 4;
    }

    Wall wall01, wall02, wall03, wall04;
    wall01.setPosition(70, 100);
    wall02.setPosition(70, 431);
    wall03.setPosition(15900, 100);
    wall04.setPosition(15900, 431);
    walls.push_back(wall01);
    walls.push_back(wall02);
    walls.push_back(wall03);
    walls.push_back(wall04);

    //NPC
    //init patterns
    Sprite snowmanPattern;
    snowmanPattern.setTexture(":/images/backgrounds/snowman.png", 1, 2);
    Sprite signboardPattern;
    signboardPattern.setTexture(":/images/backgrounds/board.png", 1, 2);
    Sprite treePattern1, treePattern2;
    treePattern1.setTexture(":/images/backgrounds/snowtree1.png", 1, 2);
    treePattern2.setTexture(":/images/backgrounds/snowtree2.png", 1, 2);

    //assign
    Sprite snowman, signboard, tree;

    //first island
    snowman = snowmanPattern;
    snowman.setPosition(300, 660);
    snowmans.push_back(snowman);

    NPC *wr01 = new Wraith();
    wr01->setPosition(500, 300);
    wr01->setLimitArea(QRectF(300, 2000, 2050 - 300, wr01->getHeight()));
    NPCs.push_back(wr01);

    NPC *blueSamurai = new Ally(2);
    blueSamurai->setPosition(2200, 565);
    NPCs.push_back(blueSamurai);

    //second island
    signboard = signboardPattern;
    signboard.setPosition(2850, 685);
    signboards.push_back(signboard);

    NPC *kong01 = new Kong();
    kong01->setPosition(3000, 610);
    kong01->setLimitArea(QRectF(2900, 610, 1600, kong01->getHeight()));
    NPCs.push_back(kong01);

    for (int i = 1; i <= 12; i++)
    {
        srand(time(0));
        Sprite tree;
        if (rand() % 2 == 0)
        {
            tree = treePattern1;
            tree.setPosition(2850 + 140*i, 635);
        }
        else
        {
            tree = treePattern2;
            tree.setPosition(2850 + 140*i, 650);
        }
        snowtrees.push_back(tree);
    }
    signboard.setPosition(4600, 685);
    signboards.push_back(signboard);

    //third island
    snowman = snowmanPattern;
    snowman.setPosition(5300, 660);
    snowmans.push_back(snowman);

    NPC *wr02 = new Wraith();
    wr02->setPosition(5500, 300);
    wr02->setLimitArea(QRectF(5300, 2000, 2050 - 200, wr01->getHeight()));
    NPCs.push_back(wr02);

    NPC *pinkSamurai = new Ally(1);
    pinkSamurai->setPosition(7000, 595);
    NPCs.push_back(pinkSamurai);

    //fourth island
    signboard = signboardPattern;
    signboard.setPosition(7650, 685);
    signboards.push_back(signboard);

    NPC *kong02 = new Kong();
    kong02->setPosition(7800, 610);
    kong02->setLimitArea(QRectF(7700, 610, 1600, kong01->getHeight()));
    NPCs.push_back(kong02);

    srand(time(0));
    for (int i = 1; i <= 12; i++)
    {
        Sprite tree;
        if (rand() % 2 == 0)
        {
            tree = treePattern1;
            tree.setPosition(7650 + 140*i, 635);
        }
        else
        {
            tree = treePattern2;
            tree.setPosition(7650 + 140*i, 650);
        }
        snowtrees.push_back(tree);
    }

    signboard.setPosition(9400, 685);
    signboards.push_back(signboard);

    //fifth island

    NPC *redSamurai = new Ally(3);
    redSamurai->setPosition(15700, 595);
    NPCs.push_back(redSamurai);
















    Sprite *energyPotionPattern = new Sprite();
    Sprite *healthPotionPattern = new Sprite();
    energyPotionPattern->setTexture(":/images/icons/energyPotion.png", 1, 10);
    energyPotionPattern->setPosition(400, 200);
    healthPotionPattern->setTexture(":/images/icons/heartPotion.png", 1, 9);
    healthPotionPattern->setPosition(950, 200);

    energyPotions.push_back(energyPotionPattern);
    healthPotions.push_back(healthPotionPattern);

    explosion1Pattern.setTexture(":/images/npcs/enemyDying.png", 4, 5);
    explosion1Pattern.setDuration(3);
    explosion1Pattern.setPosition(0, 0);

    dirtPattern.setTexture(":/images/backgrounds/dirt.png", 5, 6);
    dirtPattern.setDuration(1);
    dirtPattern.setPosition(300, 660);


    //...

//    magicGateY1.setTexture("D://Games//Toshizo//magicGateY.png", 12, 1);
//    magicGateY1.setPosition(1800, 400);
//    magicGateY2.setTexture("D://Games//Toshizo//flippedMagicGateY.png", 12, 1);
//    magicGateY2.setPosition(1700, 200);

//    magicGateX.setTexture("D://Games//Toshizo//magicGate2.png", 12, 1);
//    magicGateX.setPosition(1800, 100);

//    magicGate.setTexture("D://Games//Toshizo//magicGate1.png", 20, 1);
//    magicGate.setPosition(2300, 200);

//    fireBall.setTexture("D://Games//Toshizo//fireBall.png", 25, 1);
//    fireBall.setPosition(200, 450);
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
    updateRedCollisions();

    for (unsigned int i = 0; i < bodyExplosions.size(); i++)
    {
        bodyExplosions[i].setClock();
        if (bodyExplosions[i].getFrame() == explosion1Pattern.getTotalFrame() - 1)
        {
            bodyExplosions.erase(bodyExplosions.begin() + i);
        }
    }

    if (booleanDirt)
    {
        dirt.setClock();
        if (dirt.getFrame() == dirtPattern.getTotalFrame() - 1)
        {
            booleanDirt = false;
        }
    }

    //...

//    magicGateY1.setFrame(clock);
//    magicGateY2.setFrame(clock);
//    magicGateX.setFrame(clock);
//    magicGate.setFrame(clock);
//    fireBall.setFrame(clock);
//    fireBall.setPosition(fireBall.getPosition().x() + 10, 450);
//    if (clock % fireBall.getTotalFrame() == 0)
//    {
//        fireBall.setPosition(200, 450);
//    }
}

void Map::deleteHealthAt(int locate)
{
    Sprite *temp = healthPotions[locate];
    healthPotions.erase(healthPotions.begin() + locate);

    delete temp;
}

void Map::deleteEnergyAt(int locate)
{
    Sprite *temp = energyPotions[locate];
    energyPotions.erase(energyPotions.begin() + locate);

    delete temp;
}

void Map::deleteNPCAt(int locate)
{
    NPC *temp = NPCs[locate];
    NPCs.erase(NPCs.begin() + locate);

    if (temp->isAlly());
    else
    {
        Sprite tempBodyExplosion = explosion1Pattern;
        tempBodyExplosion.setPosition(temp->getPosition().x() - 40, temp->getPosition().y() - 50);
        bodyExplosions.push_back(tempBodyExplosion);
    }

    srand(time(0));
    if (rand() % 2 == 0)
    {
        Sprite *energyPotionPattern = new Sprite();
        energyPotionPattern->setTexture("D://Games//Toshizo//energyPotion.png", 1, 10);
        energyPotionPattern->setPosition((temp->getHitBox().topLeft().x() + temp->getHitBox().topRight().x()) / 2, temp->getPosition().y());
        energyPotions.push_back(energyPotionPattern);
    }
    else
    {
        Sprite *healthPotionPattern = new Sprite();
        healthPotionPattern->setTexture("D://Games//Toshizo//heartPotion.png", 1, 9);
        healthPotionPattern->setPosition((temp->getHitBox().topLeft().x() + temp->getHitBox().topRight().x()) / 2, temp->getPosition().y());
        healthPotions.push_back(healthPotionPattern);
    }
    delete temp;
}

void Map::generateDirtAt(QPointF p)
{
    if (!booleanDirt)
    {
        dirt = dirtPattern;
        dirt.setPosition(p.x(), p.y() - 45);
        booleanDirt = true;
    }
}

void Map::updateRedCollisions()
{
    std::vector<Collision> temp;
    for (unsigned int i = 0; i < NPCs.size(); i++)
    {
        for (unsigned int j = 0; j < NPCs[i]->getRedCollisions().size(); j++)
        {
            if (!NPCs[i]->isAlly())
            {
                temp.push_back(Collision(NPCs[i]->getRedCollisions()[j], NPCs[i]->getDamage(), false));
            }
        }
    }
    redCollisions = temp;
}

void Map::draw(QPainter &painter)
{
    setClock();
    for (int i = 0; i < bgLayers - 2; i++)
    {
        if (backgrounds[i].getPosition().x() >= width)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setPosition(backgrounds[i].getPosition().x() - backgrounds[i].getWidth() + 1, backgrounds[i].getPosition().y());
            backgrounds[i] = tempBg;
        }
        else if (backgrounds[i].getPosition().x() + backgrounds[i].getWidth() <= 0)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setPosition(backgrounds[i].getPosition().x() + backgrounds[i].getWidth() - 1, backgrounds[i].getPosition().y());
            backgrounds[i] = tempBg;
        }
        else if (backgrounds[i].getPosition().x() > 0)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setPosition(backgrounds[i].getPosition().x() - backgrounds[i].getWidth() + 1, backgrounds[i].getPosition().y());
            painter.drawPixmap(tempBg.getTarget(), tempBg.getTexture(), tempBg.getSource());
        }
        else if (backgrounds[i].getPosition().x() < 0)
        {
            Sprite tempBg;
            tempBg.setTexture(backgrounds[i].getTexture(), 1, 1);
            tempBg.setPosition(backgrounds[i].getPosition().x() + backgrounds[i].getWidth() - 1, backgrounds[i].getPosition().y());
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
        painter.drawPixmap(currentGrounds[i].getTarget(), currentGrounds[i].getTexture(), currentGrounds[i].getSource());
    }

    for (unsigned int i = 0; i < snowmans.size(); i++)
    {
        painter.drawPixmap(snowmans[i].getTarget(), snowmans[i].getTexture(), snowmans[i].getSource());
    }
    for (unsigned int i = 0; i < snowtrees.size(); i++)
    {
        painter.drawPixmap(snowtrees[i].getTarget(), snowtrees[i].getTexture(), snowtrees[i].getSource());
    }
    for (unsigned int i = 0; i < signboards.size(); i++)
    {
        painter.drawPixmap(signboards[i].getTarget(), signboards[i].getTexture(), signboards[i].getSource());
    }

    for (unsigned int i = 0; i < currentWalls.size(); i++)
    {
        painter.drawPixmap(currentWalls[i].getTarget(), currentWalls[i].getTexture(), currentWalls[i].getSource());
    }
    for (unsigned int i = 0; i < NPCs.size(); i++)
    {
        painter.drawPixmap(NPCs[i]->getSprite().getTarget(), NPCs[i]->getSprite().getTexture(), NPCs[i]->getSprite().getSource());

//        painter.drawRect(NPCs[i]->getHitBox());//delete this

//        painter.drawRect(NPCs[i]->getVisionArea());//delete this

//        painter.drawRect(NPCs[i]->getAttackArea());//delete this

//        painter.drawRect(NPCs[i]->getLimitArea());//delete this
    }

//    painter.setPen(Qt::red);
//    for (unsigned int i = 0; i < redCollisions.size(); i++)
//    {
//        painter.drawRect(redCollisions[i]);
//    }
//    painter.setPen(Qt::black);  //delete this

    for (unsigned int i = 0; i < energyPotions.size(); i++)
    {
        painter.drawPixmap(energyPotions[i]->getTarget(), energyPotions[i]->getTexture(), energyPotions[i]->getSource());
    }

    for (unsigned int i = 0; i < healthPotions.size(); i++)
    {
        painter.drawPixmap(healthPotions[i]->getTarget(), healthPotions[i]->getTexture(), healthPotions[i]->getSource());
    }

    for (unsigned int i = 0; i < bodyExplosions.size(); i++)
    {
        painter.drawPixmap(bodyExplosions[i].getTarget(), bodyExplosions[i].getTexture(), bodyExplosions[i].getSource());
    }

    if (booleanDirt)
    {
        painter.drawPixmap(dirt.getTarget(), dirt.getTexture(), dirt.getSource());
    }

    //player's sprites


    for (unsigned int i = 0; i < playerSprites.size(); i++)
    {
        painter.drawPixmap(playerSprites[i]->getTarget(), playerSprites[i]->getTexture(), playerSprites[i]->getSource());
    }


    //...

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
        if (NPCs[i]->isAlly());
        else
        {
            NPCs[i]->setLimitArea(QRectF(NPCs[i]->getLimitArea().topLeft().x() + tx,
                                         NPCs[i]->getLimitArea().topLeft().y(),
                                         NPCs[i]->getLimitArea().width(),
                                         NPCs[i]->getLimitArea().height()));
        }
    }

    for (unsigned int i = 0; i < snowmans.size(); i++)
    {
        snowmans[i].setPosition(snowmans[i].getPosition().x() + tx, snowmans[i].getPosition().y());
    }

    for (unsigned int i = 0; i < snowtrees.size(); i++)
    {
        snowtrees[i].setPosition(snowtrees[i].getPosition().x() + tx, snowtrees[i].getPosition().y());
    }

    for (unsigned int i = 0; i < signboards.size(); i++)
    {
        signboards[i].setPosition(signboards[i].getPosition().x() + tx, signboards[i].getPosition().y());
    }

    for (unsigned int i = 0; i < energyPotions.size(); i++)
    {
        energyPotions[i]->setPosition(energyPotions[i]->getPosition().x() + tx, energyPotions[i]->getPosition().y());
    }

    for (unsigned int i = 0; i < healthPotions.size(); i++)
    {
        healthPotions[i]->setPosition(healthPotions[i]->getPosition().x() + tx, healthPotions[i]->getPosition().y());
    }

//    for (unsigned int i = 0; i < bodyExplosions.size(); i++)
//    {
//        bodyExplosions[i].setPosition(bodyExplosions[i].getPosition().x() + tx, bodyExplosions[i].getPosition().y());
//    }


    if (booleanDirt)
    {
        dirt.setPosition(dirt.getPosition().x() + tx, dirt.getPosition().y());
    }

    //...
    clip();
}

void Map::clip()
{
    std::vector<Ground> temp_grounds;
    std::vector<Wall> temp_walls;

    for (unsigned int i = 0; i < grounds.size(); i++)
    {
        if (QRectF(0, 0, width, height).intersects(grounds[i].getHitBox()))
            temp_grounds.push_back(grounds[i]);
    }

    for (unsigned int i = 0; i < walls.size(); i++)
    {
        if (QRectF(0, 0, width, height).intersects(walls[i].getHitBox()))
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

std::vector<Sprite *> Map::getHealthPotions()
{
    return healthPotions;
}
std::vector<Sprite *> Map::getEnergyPotions()
{
    return energyPotions;
}

std::vector<NPC *> Map::getNPCs()
{
    return NPCs;
}

std::vector<Collision> Map::getRedCollisions()
{
    return redCollisions;
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

void Map::getPlayerSprites(std::vector<Sprite*> playerSprites)
{
    this->playerSprites.clear();
    this->playerSprites = playerSprites;
}

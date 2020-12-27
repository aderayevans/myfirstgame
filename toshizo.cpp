#include "toshizo.h"
#include <iostream>
#include <QDebug>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

Toshizo::Toshizo()
{
    setTexture();
}

void Toshizo::setDirection(Direction direct)
{
    this->direct = direct;
}

void Toshizo::setTexture()
{
    standSprite.setTexture(":/images/characters/toshizo/implementStandingToshizo.png", 4, scale);
    hurtingStandSprite.setTexture(":/images/characters/toshizo/implementStandingHurtingToshizo.png", 4, scale);
    buffedStandSprite.setTexture(":/images/characters/toshizo/implementBuffedStandingToshizo.png", 4, scale);
    buffedHurtingStandSprite.setTexture(":/images/characters/toshizo/implementBuffedStandingHurtingToshizo.png", 4, scale);

    runSprite.setTexture(":/images/characters/toshizo/implementRunningToshizo.png", 5, scale);
    runSprite.setSpeed(speed);                                                       // for moving
    hurtingRunSprite.setTexture(":/images/characters/toshizo/implementRunningHurtingToshizo.png", 5, scale);

    jumpSprite.setTexture(":/images/characters/toshizo/implementJumpingToshizo.png", 5, scale);
    hurtingJumpSprite.setTexture(":/images/characters/toshizo/implementJumpingHurtingToshizo.png", 5, scale);

    attackSprite.setTexture(":/images/characters/toshizo/implementAttackingToshizo.png", 2, scale);
    hurtingAttackSprite.setTexture(":/images/characters/toshizo/implementAttackingHurtingToshizo.png", 2, scale);
    buffedAttackSprite.setTexture(":/images/characters/toshizo/implementBuffedAttackingToshizo.png", 2, scale);
    buffedHurtingAttackSprite.setTexture(":/images/characters/toshizo/implementBuffedAttackingHurtingToshizo.png", 2, scale);

    buffSprite.setTexture(":/images/characters/toshizo/implementBuffingToshizo.png", 3, scale);
    hurtingBuffSprite.setTexture(":/images/characters/toshizo/implementBuffingHurtingToshizo.png", 3, scale);

    jumpAttackSprite.setTexture(":/images/characters/toshizo/implementJumpAttackingToshizo.png", 4, scale);
    buffedJumpAttackSprite.setTexture(":/images/characters/toshizo/implementPeashooter.png", 8, scale*2);

    dyingSprite.setTexture(":/images/characters/toshizo/implementDyingToshizo.png", 1, scale);
    //---
    standSprite2.setTexture(":/images/characters/toshizo/flippedStandingToshizo.png", 4, scale);
    hurtingStandSprite2.setTexture(":/images/characters/toshizo/flippedStandingHurtingToshizo.png", 4, scale);
    buffedStandSprite2.setTexture(":/images/characters/toshizo/flippedBuffedStandingToshizo.png", 4, scale);
    buffedHurtingStandSprite2.setTexture(":/images/characters/toshizo/flippedBuffedStandingHurtingToshizo.png", 4, scale);

    runSprite2.setTexture(":/images/characters/toshizo/flippedRunningToshizo.png", 5, scale);
    hurtingRunSprite2.setTexture(":/images/characters/toshizo/flippedRunningHurtingToshizo.png", 5, scale);

    jumpSprite2.setTexture(":/images/characters/toshizo/flippedJumpingToshizo.png", 5, scale);
    hurtingJumpSprite2.setTexture(":/images/characters/toshizo/flippedJumpingHurtingToshizo.png", 5, scale);

    attackSprite2.setTexture(":/images/characters/toshizo/flippedAttackingToshizo.png", 2, scale);
    hurtingAttackSprite2.setTexture(":/images/characters/toshizo/flippedAttackingHurtingToshizo.png", 2, scale);
    buffedAttackSprite2.setTexture(":/images/characters/toshizo/flippedBuffedAttackingToshizo.png", 2, scale);
    buffedHurtingAttackSprite2.setTexture(":/images/characters/toshizo/flippedBuffedAttackingHurtingToshizo.png", 2, scale);

    buffSprite2.setTexture(":/images/characters/toshizo/flippedBuffingToshizo.png", 3, scale);
    hurtingBuffSprite2.setTexture(":/images/characters/toshizo/flippedBuffingHurtingToshizo.png", 3, scale);

    jumpAttackSprite2.setTexture(":/images/characters/toshizo/flippedJumpAttackingToshizo.png", 4, scale);
    buffedJumpAttackSprite2.setTexture(":/images/characters/toshizo/flippedPeashooter.png", 8, scale*2);

    //..
    avatar.setTexture(":/images/characters/toshizo/avatarToshizo.png", 1, scale);
    avatar.setPosition(70, 85);

    tornadoPattern.setTexture(":/images/characters/toshizo/water-tornado.png", 4, 1);
    tornadoPattern.setDuration(2);
    darkBallPattern.setTexture(":/images/characters/toshizo/darkBall.png", 8, 4);
    darkBallPattern.setDuration(1);
    rasenganPattern.setTexture(":/images/characters/toshizo/rasengan.png", 13, 1);
    rasenganPattern.setDuration(2);
    rasenganPattern2.setTexture(":/images/characters/toshizo/rasengan2.png", 13, 1);
    rasenganPattern2.setDuration(2);
}

void Toshizo::setState(State s)
{
    state = s;
}

void Toshizo::setPosition(double x, double y)
{
    position = QPointF(x, y);
    int tempX = x - 45;     //45 pixels of the sword
    standSprite.setPosition(tempX, y);
    hurtingStandSprite.setPosition(tempX, y);
    buffedStandSprite.setPosition(x - 52, y - 50);
    buffedHurtingStandSprite.setPosition(x - 52, y - 50);

    runSprite.setPosition(tempX, y);
    hurtingRunSprite.setPosition(tempX, y);

    jumpSprite.setPosition(tempX, y);
    hurtingJumpSprite.setPosition(tempX, y);

    attackSprite.setPosition(tempX, y);
    hurtingAttackSprite.setPosition(tempX, y);
    buffedAttackSprite.setPosition(x - 65, y - 67);
    buffedHurtingAttackSprite.setPosition(x - 65, y - 67);

    buffSprite.setPosition(x - 60, y - 105);
    hurtingBuffSprite.setPosition(x - 60, y - 105);

    jumpAttackSprite.setPosition(tempX, y - 45);
    buffedJumpAttackSprite.setPosition(x - 160, y);

    dyingSprite.setPosition(tempX, y);
    //---
    standSprite2.setPosition(x, y);
    hurtingStandSprite2.setPosition(x, y);
    buffedStandSprite2.setPosition(x - 35, y - 51);
    buffedHurtingStandSprite2.setPosition(x - 35, y - 51);

    runSprite2.setPosition(x, y);
    hurtingRunSprite2.setPosition(x, y);

    jumpSprite2.setPosition(x, y);
    hurtingJumpSprite2.setPosition(x, y);

    attackSprite2.setPosition(x - 120, y);
    hurtingAttackSprite2.setPosition(x - 120, y);
    buffedAttackSprite2.setPosition(x - 120, y - 67);
    buffedHurtingAttackSprite2.setPosition(x - 120, y - 67);

    buffSprite2.setPosition(x - 90, y - 105);
    hurtingBuffSprite2.setPosition(x - 90, y - 105);

    jumpAttackSprite2.setPosition(tempX, y - 45);
    buffedJumpAttackSprite2.setPosition(x - 30, y);

    setHitBox(QRectF(x, y, getWidth(), getHeight()));
}

void Toshizo::setHealth(double h)
{
    if (h >= leftHealth) leftHealth = h;
    else if (hurted || immortal);
    else
    {
        leftHealth = h;
        hurted = maxHurtTime;
    }
}

void Toshizo::setEnergy(double e)
{
    leftEnergy = e;
}

void Toshizo::setHitBox(QRectF q)
{
    standSprite.setHitBox(q);
}

bool Toshizo::doubleJumped()
{
    return doubleJump;
}

void Toshizo::setDoubleJump()
{
    doubleJump = true;
    jumpClock = 0;
}

bool Toshizo::isBuffed()
{
    return buffed;
}

QRectF Toshizo::getHitBox()
{
    return standSprite.getHitBox();
}

State Toshizo::getState()
{
    return state;
}

double Toshizo::getHeight()
{
    return standSprite.getHeight();
}

double Toshizo::getWidth()
{
    return standSprite.getWidth() - 50;
}

double Toshizo::getSpeed()
{
    switch (state) {
    case Run:
        return runSprite.getSpeed() + boostSpeed;
    case Jump:
        return runSprite.getSpeed() + boostSpeed;
    case Fall:
        return runSprite.getSpeed();
    case JumpAttack:
        return runSprite.getSpeed() + boostSpeed;
    case Stand:
        return 0;
    case Attack:
        return 0;
    case Buff:
        return 0;
    case Dying:
        return 0;
    }
}

void Toshizo::hackON()
{
    hacked = true;
}

void Toshizo::hackOFF()
{
    hacked = false;
}

bool Toshizo::isHacked()
{
    return hacked;
}

void Toshizo::setClock()
{
    collisions.clear();
    immortal = false;
    if (countdownSkill1) countdownSkill1--;
    if (countdownSkill2) countdownSkill2--;
    if (countdownSkill3) countdownSkill3--;
    if (!hacked)
    {
        if (buffed) buffed--;
    }
    if (hurted)
    {
        if (hurted) hurted--;
    }
    if (hacked)
    {
        immortal = true;
        leftEnergy = fullEnergy;
        leftHealth = fullHealth;
    }
    switch (state)
    {
    case Stand:
        jumpPicture = 0;
        buffPicture = 0;
        jumpClock = 0;
        runTime = 0;
        buffClock = 0;
        jumpAttackClock = 0;
        jumpAttackPicture = 0;
        boostSpeed = 0;
        boostHigh = 0;
        flyTime = maxFlyTime;
        doubleJump = false;
        if (standClock > standSlowTime)
        {
            standPicture++;
            standClock = 0;
        }
        if (standPicture == standSprite.getTotalPicture())
        {
            standPicture = 0;
        }
        standClock++;
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                buffedHurtingStandSprite2.setFrame(standPicture);
                break;
            default:    //case leftRight:
                buffedHurtingStandSprite.setFrame(standPicture);
                break;
            }
        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                buffedStandSprite2.setFrame(standPicture);
                break;
            default:    //case leftRight:
                buffedStandSprite.setFrame(standPicture);
                break;
            }

        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                hurtingStandSprite2.setFrame(standPicture);
                break;
            default:    //case leftRight:
                hurtingStandSprite.setFrame(standPicture);
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                standSprite2.setFrame(standPicture);
                break;
            default:    //case leftRight:
                standSprite.setFrame(standPicture);
                break;
            }
        }
        break;
    case Run:
        if (runTime == boostTime)
        {
            boostSpeed = maxBoost;
            boostHigh = maxBoost;
        }
        runTime++;
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                hurtingRunSprite2.setClock();
                break;
            default:    //case leftRight:
                hurtingRunSprite.setClock();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                runSprite2.setClock();
                break;
            default:    //case leftRight:
                runSprite.setClock();
                break;
            }
        }
        break;
    case Jump:
    {
        if (jumpPicture != 0 || (doubleJump && jumpPicture == 3))
            setPosition(position.x(), position.y() - jumpRangeEachTimeID - boostHigh);
        if (jumpClock > jumpLimitTime)
        {
            setState(Fall);
            break;
        }
        jumpClock++;
        if (jumpPicture >= 2 && !doubleJump)
        {
            jumpPicture = 1;
        }
        if (jumpPicture >= 3 && doubleJump)
        {
            jumpPicture = 3;
        }
        if (hurted)
        {
            switch (direct)
            {
            case rightLeft:
                hurtingJumpSprite2.setFrame(jumpPicture++);
                break;
            default:    //case leftRight:
                hurtingJumpSprite.setFrame(jumpPicture++);
                break;
            }
        }
        else
        {
            switch (direct)
            {
            case rightLeft:
                jumpSprite2.setFrame(jumpPicture++);
                break;
            default:    //case leftRight:
                jumpSprite.setFrame(jumpPicture++);
                break;
            }
        }
        break;
    }
    case Attack:
    {
        if (attackClock > attackSlowTime)
        {
            attackPicture++;
            attackClock = 0;
        }
        attackClock++;
        if (attackPicture > 0)
        {
            switch (direct) {
            case rightLeft:
                collisions.push_back(Collision(QRectF(QPointF(getPosition().x() - 120, getPosition().y()),
                              QPointF(getPosition().x(), getPosition().y() + getHeight() - 10)),
                                 getDamage()));
                break;
            default:    //case leftRight:
                collisions.push_back(Collision(QRectF(QPointF(getPosition().x() + getWidth(), getPosition().y()),
                              QPointF(getPosition().x() + getWidth() + 120, getPosition().y() + getHeight() - 10)),
                                 getDamage()));
                break;
            }
        }
        if (attackPicture == attackSprite.getTotalPicture())
        {
            attackPicture = 0;
            setState(Stand);
        }
        if (buffed && hurted)
        {
            switch (direct)
            {
            case rightLeft:
                buffedHurtingAttackSprite2.setFrame(attackPicture);
                break;
            default:    //case leftRight:
                buffedHurtingAttackSprite.setFrame(attackPicture);
                break;
            }
        }
        else if (buffed)
        {
            switch (direct)
            {
            case rightLeft:
                buffedAttackSprite2.setFrame(attackPicture);
                break;
            default:    //case leftRight:
                buffedAttackSprite.setFrame(attackPicture);
                break;
            }
        }
        else if (hurted)
        {
            switch (direct)
            {
            case rightLeft:
                hurtingAttackSprite2.setFrame(attackPicture);
                break;
            default:    //case leftRight:
                hurtingAttackSprite.setFrame(attackPicture);
                break;
            }
        }
        else
        {
            switch (direct)
            {
            case rightLeft:
                attackSprite2.setFrame(attackPicture);
                break;
            default:    //case leftRight:
                attackSprite.setFrame(attackPicture);
                break;
            }
        }
        break;
    }
    case JumpAttack:
    {
        immortal = true;
        if (buffed)
        {
            if (jumpAttackClock > jumpAttackSlowTime)
            {
                jumpAttackPicture++;
                jumpAttackClock = 0;
            }
            if (jumpAttackPicture == buffedJumpAttackSprite2.getTotalPicture())
            {
                jumpAttackPicture = 0;
            }
            if (!hacked)
            {
                flyTime--;
            }
            if (!flyTime)
            {
                setState(Fall);
            }
            jumpAttackClock++;
            switch (direct)
            {
            case rightLeft:
                setPosition(position.x() - buffedSkillRange, position.y());
                buffedJumpAttackSprite2.setFrame(jumpAttackPicture);
                collisions.push_back(Collision(QRectF(QPointF(getPosition().x() - 15, getPosition().y()),
                              QPointF(getPosition().x() + getWidth() + 100, getPosition().y() + getHeight())),
                                 getDamage()));
                break;
            default:    //case leftRight:
                setPosition(position.x() + buffedSkillRange, position.y());
                buffedJumpAttackSprite.setFrame(jumpAttackPicture);
                collisions.push_back(Collision(QRectF(QPointF(getPosition().x() - 100, getPosition().y()),
                              QPointF(getPosition().x() + getWidth() + 15, getPosition().y() + getHeight())),
                                 getDamage()));
                break;
            }
        }
        else
        {
            collisions.push_back(Collision(QRectF(QPointF(getPosition().x() - 40, getPosition().y() - 40),
                          QPointF(getPosition().x() + getWidth() + 50, getPosition().y() + getHeight() + 12)),
                             getDamage()));
            if (jumpAttackClock > jumpAttackSlowTime)
            {
                jumpAttackPicture++;
                jumpAttackClock = 0;
            }
            jumpAttackClock++;
            if (jumpAttackPicture >= onSkyTime_forNotBuffedJumpAttack)
            {
                setState(Fall);
            }
            switch (direct)
            {
            case rightLeft:
                jumpAttackSprite2.setFrame(jumpAttackPicture);
                break;
            default:    //case leftRight:
                jumpAttackSprite.setFrame(jumpAttackPicture);
                break;
            }
        }
        break;
    }
    case Buff:
    {
        if (leftEnergy < buffRequiredEnergy || buffed || hurted)
        {
            setState(Stand);
            break;
        }
        if (buffClock > buffSlowTime)
        {
            buffPicture++;
            buffClock = 0;
        }
        buffClock++;
        if (buffPicture == buffSprite.getTotalPicture())
        {
            leftEnergy-=buffRequiredEnergy;
            buffed = maxBuffTime;
            buffPicture = 0;
        }
        if (hurted)
        {
            switch (direct)
            {
            case rightLeft:
                hurtingBuffSprite2.setFrame(buffPicture);
                break;
            default:    //case leftRight:
                hurtingBuffSprite.setFrame(buffPicture);
                break;
            }
        }
        else
        {
            switch (direct)
            {
            case rightLeft:
                buffSprite2.setFrame(buffPicture);
                break;
            default:    //case leftRight:
                buffSprite.setFrame(buffPicture);
                break;
            }
        }
        break;
    }
    case Dying:
        dyingSprite.setFrame(0);
        break;
    default:    //case Fall:
        setPosition(position.x(), position.y() + fallingRangeEachTimeID);
        int fallAnimation;
        if (doubleJump) fallAnimation = 4;
        else fallAnimation = 2;
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                hurtingJumpSprite2.setFrame(fallAnimation);
                break;
            default:    //case leftRight:
                hurtingJumpSprite.setFrame(fallAnimation);
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                jumpSprite2.setFrame(fallAnimation);
                break;
            default:    //case leftRight:
                jumpSprite.setFrame(fallAnimation);
                break;
            }
        }
        break;
    }
    //skills
    for (unsigned int i = 0; i < tornados.size(); i++)
    {
        tornados[i].setClock();
        if (tornados[i].getLifetime() < lifetimeSkill1)
        {
            collisions.push_back(Collision(QRectF(tornados[i].getPosition().x(),
                                                  tornados[i].getPosition().y(),
                                                  tornados[i].getWidth(),
                                                  tornados[i].getHeight()),
                                           tornadoDamage));
        }
        else
        {
            tornados.erase(tornados.begin() + i);
        }
        switch (tornados[i].getDirection()) {
        case rightLeft:
            tornados[i].setPosition(tornados[i].getPosition().x() - 20, tornados[i].getPosition().y());
            break;
        default:    //case leftRight:
            tornados[i].setPosition(tornados[i].getPosition().x() + 20, tornados[i].getPosition().y());
            break;
        }
    }

    for (unsigned int i = 0; i < darkBalls.size(); i++)
    {
        darkBalls[i].setClock();
        if (darkBalls[i].getLifetime() < lifetimeSkill2)
        {
            collisions.push_back(Collision(QRectF(darkBalls[i].getPosition().x(),
                                                  darkBalls[i].getPosition().y(),
                                                  darkBalls[i].getWidth(),
                                                  darkBalls[i].getHeight()),
                                           darkBallDamage));
        }
        else
        {
            darkBalls.erase(darkBalls.begin() + i);
        }
        switch (darkBalls[i].getDirection()) {
        case rightLeft:
            darkBalls[i].setPosition(darkBalls[i].getPosition().x() - 20, darkBalls[i].getPosition().y());
            break;
        default:    //case leftRight:
            darkBalls[i].setPosition(darkBalls[i].getPosition().x() + 20, darkBalls[i].getPosition().y());
            break;
        }
    }
    for (unsigned int i = 0; i < rasengans.size(); i++)
    {
        rasengans[i].setClock();
        if (rasengans[i].getFrame() > 2 && rasengans[i].getFrame() < 9)
        {
            collisions.push_back(Collision(QRectF(rasengans[i].getPosition().x(),
                                                  rasengans[i].getPosition().y(),
                                                  rasengans[i].getWidth(),
                                                  rasengans[i].getHeight()),
                                           rasenganDamage));
            switch (rasengans[i].getDirection()) {
            case rightLeft:
                rasengans[i].setPosition(rasengans[i].getPosition().x() - 20, rasengans[i].getPosition().y());
                break;
            default:    //case leftRight:
                rasengans[i].setPosition(rasengans[i].getPosition().x() + 20, rasengans[i].getPosition().y());
                break;
            }
        }
        if (rasengans[i].getFrame() == rasenganPattern.getTotalPicture() - 1)
        {
            rasengans.erase(rasengans.begin() + i);
        }
    }
}

QPointF Toshizo::getPosition()
{
    return position;
}

QPointF Toshizo::getLowestPoint()
{
    return QPointF(position.x() + getWidth()/2, position.y() + getHeight());
}

std::vector<Collision> Toshizo::getBlueCollisions()
{
    return collisions;
}

double Toshizo::getDamage()
{
    if (hacked)
    {
        return maxDamage;
    }
    else if (buffed)
    {
        return buffedDamage;
    }
    else
    {
        return damage;
    }
}

Direction Toshizo::getDirection()
{
    return direct;
}

double Toshizo::getFullHealth()
{
    return fullHealth;
}

double Toshizo::getLeftHealth()
{
    return leftHealth;
}

double Toshizo::getFullEnergy()
{
    return fullEnergy;
}

double Toshizo::getLeftEnergy()
{
    return leftEnergy;
}

Sprite Toshizo::getSprite()
{
    switch (state) {
    case Run:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingRunSprite2;
            default:    //case leftRight:
                return hurtingRunSprite;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return runSprite2;
            default:    //case leftRight:
                return runSprite;
            }
        }
    case Jump:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2;
            default:    //case leftRight:
                return hurtingJumpSprite;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2;
            default:    //case leftRight:
                return jumpSprite;
            }
        }
    case Fall:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2;
            default:    //case leftRight:
                return hurtingJumpSprite;
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2;
            default:    //case leftRight:
                return jumpSprite;
            }
        }
    case Attack:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingAttackSprite2;
            default:    //case leftRight:
                return buffedHurtingAttackSprite;
            }
        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedAttackSprite2;
            default:    //case leftRight:
                return buffedAttackSprite;
            }
        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingAttackSprite2;
            default:    //case leftRight:
                return hurtingAttackSprite;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return attackSprite2;
            default:    //case leftRight:
                return attackSprite;
            }
        }
    case JumpAttack:
        if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedJumpAttackSprite2;
            default:    //case leftRight:
                return buffedJumpAttackSprite;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpAttackSprite2;
            default:    //case leftRight:
                return jumpAttackSprite;
            }
        }
    case Buff:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingBuffSprite2;
            default:    //case leftRight:
                return hurtingBuffSprite;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return buffSprite2;
            default:    //case leftRight:
                return buffSprite;
            }
        }
    case Dying:
        return dyingSprite;
    default:    //case Stand:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingStandSprite2;
            default:    //case leftRight:
                return buffedHurtingStandSprite;
            }

        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedStandSprite2;
            default:    //case leftRight:
                return buffedStandSprite;
            }

        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingStandSprite2;
            default:    //case leftRight:
                return hurtingStandSprite;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return standSprite2;
            default:    //case leftRight:
                return standSprite;
            }
        }
    }
}

void Toshizo::draw(QPainter &painter)
{
    setClock();
    painter.drawPixmap(getSprite().getTarget(), getSprite().getTexture(), getSprite().getSource());
}

Sprite Toshizo::getAvatar()
{
    return avatar;
}

int Toshizo::getHealthPotionNumber()
{
    return healthPotionNumber;
}

int Toshizo::getEnergyPotionNumber()
{
    return energyPotionNumber;
}

void Toshizo::setHealthPotionNumber(int n)
{
    healthPotionNumber = n;
}

void Toshizo::setEnergyPotionNumber(int n)
{
    energyPotionNumber = n;
}

void Toshizo::useHealthPotion()
{
    if (getHealthPotionNumber() > 0)
    {
        setHealth(min(getFullHealth(), getLeftHealth() + 500));
        setHealthPotionNumber(getHealthPotionNumber() - 1);
    }
}

void Toshizo::useEnergyPotion()
{
    if (getEnergyPotionNumber() > 0)
    {
        setEnergy(min(getFullEnergy(), getLeftEnergy() + 500));
        setEnergyPotionNumber(getEnergyPotionNumber() - 1);
    }
}

void Toshizo::useSkill1()   //tornado
{
    if (!countdownSkill1 && leftEnergy >= skill1RequiredEnergy)
    {
        leftEnergy -= skill1RequiredEnergy;
        if (hacked) countdownSkill1 = 15;
        else countdownSkill1 = cooldownSkill1;
        Sprite temp = tornadoPattern;
        switch (direct) {
        case rightLeft:
            temp.setPosition(getPosition().x() - 200, getPosition().y() - 120);
            break;
        default:    //case leftRight:
            temp.setPosition(getPosition().x() + 15, getPosition().y() - 120);
            break;
        }
        temp.setDirection(direct);
        tornados.push_back(temp);
    }
}

void Toshizo::useSkill2()   //darkBall
{
    if (!countdownSkill2 && leftEnergy >= skill2RequiredEnergy)
    {
        leftEnergy -= skill2RequiredEnergy;
        if (hacked) countdownSkill2 = 15;
        else countdownSkill2 = cooldownSkill2;
        Sprite temp = darkBallPattern;
        switch (direct) {
        case rightLeft:
            temp.setPosition(getPosition().x() - 100, getPosition().y() - 100);
            break;
        default:    //case leftRight:
            temp.setPosition(getPosition().x() + 15, getPosition().y() - 100);
            break;
        }
        temp.setDirection(direct);
        darkBalls.push_back(temp);
    }
}

void Toshizo::useSkill3()   //rasengan
{
    if (!countdownSkill3 && leftEnergy >= skill3RequiredEnergy)
    {
        leftEnergy -= skill3RequiredEnergy;
        if (hacked) countdownSkill3 = 15;
        else countdownSkill3 = cooldownSkill3;
        Sprite temp;
        switch (direct) {
        case rightLeft:
            temp = rasenganPattern2;
            temp.setPosition(getPosition().x() - 200, getPosition().y() - 60);
            break;
        default:    //case leftRight:
            temp = rasenganPattern;
            temp.setPosition(getPosition().x() + 50, getPosition().y() - 60);
            break;
        }
        temp.setDirection(direct);
        rasengans.push_back(temp);
    }
}

std::vector<Sprite*> Toshizo::getSprites()
{
    std::vector<Sprite*> sprites;

    for (unsigned int i = 0; i < tornados.size(); i++)
    {
        sprites.push_back(&tornados[i]);
    }

    for (unsigned int i = 0; i < darkBalls.size(); i++)
    {
        sprites.push_back(&darkBalls[i]);
    }

    for (unsigned int i = 0; i < rasengans.size(); i++)
    {
        sprites.push_back(&rasengans[i]);
    }
    return sprites;
}

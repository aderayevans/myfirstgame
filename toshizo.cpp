#include "toshizo.h"
#include <iostream>
#include <QDebug>

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
    standSprite.setTexture("D://Games//Toshizo//implementStandingToshizo.png", 4, scale);
    hurtingStandSprite.setTexture("D://Games//Toshizo//implementStandingHurtingToshizo.png", 4, scale);
    buffedStandSprite.setTexture("D://Games//Toshizo//implementBuffedStandingToshizo.png", 4, scale);
    buffedHurtingStandSprite.setTexture("D://Games//Toshizo//implementBuffedStandingHurtingToshizo.png", 4, scale);

    runSprite.setTexture("D://Games//Toshizo//implementRunningToshizo.png", 5, scale);
    runSprite.setSpeed(speed);                                                       // for moving
    hurtingRunSprite.setTexture("D://Games//Toshizo//implementRunningHurtingToshizo.png", 5, scale);

    jumpSprite.setTexture("D://Games//Toshizo//implementJumpingToshizo.png", 5, scale);
    hurtingJumpSprite.setTexture("D://Games//Toshizo//implementJumpingHurtingToshizo.png", 5, scale);

    attackSprite.setTexture("D://Games//Toshizo//implementAttackingToshizo.png", 2, scale);
    hurtingAttackSprite.setTexture("D://Games//Toshizo//implementAttackingHurtingToshizo.png", 2, scale);
    buffedAttackSprite.setTexture("D://Games//Toshizo//implementBuffedAttackingToshizo.png", 2, scale);
    buffedHurtingAttackSprite.setTexture("D://Games//Toshizo//implementBuffedAttackingHurtingToshizo.png", 2, scale);

    buffSprite.setTexture("D://Games//Toshizo//implementBuffingToshizo.png", 3, scale);
    hurtingBuffSprite.setTexture("D://Games//Toshizo//implementBuffingHurtingToshizo.png", 3, scale);

    jumpAttackSprite.setTexture("D://Games//Toshizo//implementJumpAttackingToshizo.png", 4, scale);
    buffedJumpAttackSprite.setTexture("D://Games//Toshizo//implementPeashooter.png", 8, scale*2);
    //---
    standSprite2.setTexture("D://Games//Toshizo//flippedStandingToshizo.png", 4, scale);
    hurtingStandSprite2.setTexture("D://Games//Toshizo//flippedStandingHurtingToshizo.png", 4, scale);
    buffedStandSprite2.setTexture("D://Games//Toshizo//flippedBuffedStandingToshizo.png", 4, scale);
    buffedHurtingStandSprite2.setTexture("D://Games//Toshizo//flippedBuffedStandingHurtingToshizo.png", 4, scale);

    runSprite2.setTexture("D://Games//Toshizo//flippedRunningToshizo.png", 5, scale);
    hurtingRunSprite2.setTexture("D://Games//Toshizo//flippedRunningHurtingToshizo.png", 5, scale);

    jumpSprite2.setTexture("D://Games//Toshizo//flippedJumpingToshizo.png", 5, scale);
    hurtingJumpSprite2.setTexture("D://Games//Toshizo//flippedJumpingHurtingToshizo.png", 5, scale);

    attackSprite2.setTexture("D://Games//Toshizo//flippedAttackingToshizo.png", 2, scale);
    hurtingAttackSprite2.setTexture("D://Games//Toshizo//flippedAttackingHurtingToshizo.png", 2, scale);
    buffedAttackSprite2.setTexture("D://Games//Toshizo//flippedBuffedAttackingToshizo.png", 2, scale);
    buffedHurtingAttackSprite2.setTexture("D://Games//Toshizo//flippedBuffedAttackingHurtingToshizo.png", 2, scale);

    buffSprite2.setTexture("D://Games//Toshizo//flippedBuffingToshizo.png", 3, scale);
    hurtingBuffSprite2.setTexture("D://Games//Toshizo//flippedBuffingHurtingToshizo.png", 3, scale);

    jumpAttackSprite2.setTexture("D://Games//Toshizo//flippedJumpAttackingToshizo.png", 4, scale);
    buffedJumpAttackSprite2.setTexture("D://Games//Toshizo//flippedPeashooter.png", 8, scale*2);
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

    setHitBox(x, y, x + getWidth(), y + getHeight());
}

void Toshizo::setOrigin(double x, double y)
{
    setPosition(x, y);
}

void Toshizo::setHealth(double h)
{
    if (hurted || immortal);
    else
    {
        leftHealth = h;
        hurted = maxHurtTime;
    }
}

void Toshizo::setLimitArea(double x1, double y1, double x2, double y2)
{
    x2 -= getWidth();
    y1 += getHeight();
    standSprite.setLimitArea(x1, y1, x2, y2);
}

void Toshizo::setHitBox(double x1, double y1, double x2, double y2)
{
    standSprite.setHitBox(x1, y1, x2, y2);
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

QPointF Toshizo::getLimitArea(int number)
{
    return standSprite.getLimitArea(number);
}

QPointF Toshizo::getPointHitBox(int number)
{
    return standSprite.getPointHitBox(number);
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
        break;
    case Jump:
        return runSprite.getSpeed() + boostSpeed;
        break;
    case Fall:
        return runSprite.getSpeed();
        break;
    case JumpAttack:
        return runSprite.getSpeed() + boostSpeed;
        break;
    case Stand:
        return 0;
        break;
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
    this->clock++;
    if (buffed && !hacked)
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
        attackPicture = 0;
        jumpAttackPicture = 0;
        boostSpeed = 0;
        boostHigh = 0;
        doubleJump = false;
        flyTime = 0;
        standClock++;
        if (standClock > standSlowTime)
        {
            standPicture++;
            standClock = 0;
        }
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                buffedHurtingStandSprite2.setClock(standPicture);
                break;
            default:    //case leftRight:
                buffedHurtingStandSprite.setClock(standPicture);
                break;
            }
        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                buffedStandSprite2.setClock(standPicture);
                break;
            default:    //case leftRight:
                buffedStandSprite.setClock(standPicture);
                break;
            }

        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                hurtingStandSprite2.setClock(standPicture);
                break;
            default:    //case leftRight:
                hurtingStandSprite.setClock(standPicture);
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                standSprite2.setClock(standPicture);
                break;
            default:    //case leftRight:
                standSprite.setClock(standPicture);
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
                hurtingRunSprite2.setClock(this->clock);
                break;
            default:    //case leftRight:
                hurtingRunSprite.setClock(this->clock);
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                runSprite2.setClock(this->clock);
                break;
            default:    //case leftRight:
                runSprite.setClock(this->clock);
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
                hurtingJumpSprite2.setClock(jumpPicture++);
                break;
            default:    //case leftRight:
                hurtingJumpSprite.setClock(jumpPicture++);
                break;
            }
        }
        else
        {
            switch (direct)
            {
            case rightLeft:
                jumpSprite2.setClock(jumpPicture++);
                break;
            default:    //case leftRight:
                jumpSprite.setClock(jumpPicture++);
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
        if (attackPicture >= attackSprite.getTotalPicture())
        {
            setState(Stand);
        }
        if (buffed && hurted)
        {
            switch (direct)
            {
            case rightLeft:
                buffedHurtingAttackSprite2.setClock(attackPicture);
                break;
            default:    //case leftRight:
                buffedHurtingAttackSprite.setClock(attackPicture);
                break;
            }
        }
        else if (buffed)
        {
            switch (direct)
            {
            case rightLeft:
                buffedAttackSprite2.setClock(attackPicture);
                break;
            default:    //case leftRight:
                buffedAttackSprite.setClock(attackPicture);
                break;
            }
        }
        else if (hurted)
        {
            switch (direct)
            {
            case rightLeft:
                hurtingAttackSprite2.setClock(attackPicture);
                break;
            default:    //case leftRight:
                hurtingAttackSprite.setClock(attackPicture);
                break;
            }
        }
        else
        {
            switch (direct)
            {
            case rightLeft:
                attackSprite2.setClock(attackPicture);
                break;
            default:    //case leftRight:
                attackSprite.setClock(attackPicture);
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
            if (!jumpAttackPicture)
            {
                flyTime = maxFlyTime;
            }
            else if (!hacked)
            {
                flyTime--;
            }
            jumpAttackClock++;
            if (!flyTime)
            {
                setState(Fall);
            }
            switch (direct)
            {
            case rightLeft:
                setPosition(position.x() - buffedSkillRange, position.y());
                buffedJumpAttackSprite2.setClock(jumpAttackPicture);
                break;
            default:    //case leftRight:
                setPosition(position.x() + buffedSkillRange, position.y());
                buffedJumpAttackSprite.setClock(jumpAttackPicture);
                break;
            }
        }
        else
        {
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
                jumpAttackSprite2.setClock(jumpAttackPicture);
                break;
            default:    //case leftRight:
                jumpAttackSprite.setClock(jumpAttackPicture);
                break;
            }
        }
        break;
    }
    case Buff:
    {
        if (leftEnergy < 500)
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
        if (buffPicture >= buffSprite.getTotalPicture())
        {
            leftEnergy-=500;
            buffed = maxBuffTime;
        }
        if (hurted)
        {
            switch (direct)
            {
            case rightLeft:
                hurtingBuffSprite2.setClock(buffPicture);
                break;
            default:    //case leftRight:
                hurtingBuffSprite.setClock(buffPicture);
                break;
            }
        }
        else
        {
            switch (direct)
            {
            case rightLeft:
                buffSprite2.setClock(buffPicture);
                break;
            default:    //case leftRight:
                buffSprite.setClock(buffPicture);
                break;
            }
        }
        break;
    }
    default:    //case Fall:
        setPosition(position.x(), position.y() + fallingRangeEachTimeID);
        int fallAnimation;
        if (doubleJump) fallAnimation = 4;
        else fallAnimation = 2;
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                hurtingJumpSprite2.setClock(fallAnimation);
                break;
            default:    //case leftRight:
                hurtingJumpSprite.setClock(fallAnimation);
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                jumpSprite2.setClock(fallAnimation);
                break;
            default:    //case leftRight:
                jumpSprite.setClock(fallAnimation);
                break;
            }
        }
        break;
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
QRectF Toshizo::getTarget()
{
    switch (state) {
    case Run:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingRunSprite2.getTarget();
                break;
            default:    //case leftRight:
                return hurtingRunSprite.getTarget();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return runSprite2.getTarget();
                break;
            default:    //case leftRight:
                return runSprite.getTarget();
                break;
            }
        }
    case Jump:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2.getTarget();
                break;
            default:    //case leftRight:
                return hurtingJumpSprite.getTarget();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2.getTarget();
                break;
            default:    //case leftRight:
                return jumpSprite.getTarget();
                break;
            }
        }
    case Fall:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2.getTarget();
                break;
            default:    //case leftRight:
                return hurtingJumpSprite.getTarget();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2.getTarget();
                break;
            default:    //case leftRight:
                return jumpSprite.getTarget();
                break;
            }
        }
    case Attack:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingAttackSprite2.getTarget();
                break;
            default:    //case leftRight:
                return buffedHurtingAttackSprite.getTarget();
                break;
            }
        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedAttackSprite2.getTarget();
                break;
            default:    //case leftRight:
                return buffedAttackSprite.getTarget();
                break;
            }
        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingAttackSprite2.getTarget();
                break;
            default:    //case leftRight:
                return hurtingAttackSprite.getTarget();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return attackSprite2.getTarget();
                break;
            default:    //case leftRight:
                return attackSprite.getTarget();
                break;
            }
        }
    case JumpAttack:
        if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedJumpAttackSprite2.getTarget();
                break;
            default:    //case leftRight:
                return buffedJumpAttackSprite.getTarget();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpAttackSprite2.getTarget();
                break;
            default:    //case leftRight:
                return jumpAttackSprite.getTarget();
                break;
            }
        }
    case Buff:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingBuffSprite2.getTarget();
                break;
            default:    //case leftRight:
                return hurtingBuffSprite.getTarget();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return buffSprite2.getTarget();
                break;
            default:    //case leftRight:
                return buffSprite.getTarget();
                break;
            }
        }
    default:    //case Stand:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingStandSprite2.getTarget();
                break;
            default:    //case leftRight:
                return buffedHurtingStandSprite.getTarget();
                break;
            }

        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedStandSprite2.getTarget();
                break;
            default:    //case leftRight:
                return buffedStandSprite.getTarget();
                break;
            }

        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingStandSprite2.getTarget();
                break;
            default:    //case leftRight:
                return hurtingStandSprite.getTarget();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return standSprite2.getTarget();
                break;
            default:    //case leftRight:
                return standSprite.getTarget();
                break;
            }
        }
    }
}

QRectF Toshizo::getSource()
{
    switch (state) {
    case Run:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingRunSprite2.getSource();
                break;
            default:    //case leftRight:
                return hurtingRunSprite.getSource();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return runSprite2.getSource();
                break;
            default:    //case leftRight:
                return runSprite.getSource();
                break;
            }
        }
    case Jump:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2.getSource();
                break;
            default:    //case leftRight:
                return hurtingJumpSprite.getSource();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2.getSource();
                break;
            default:    //case leftRight:
                return jumpSprite.getSource();
                break;
            }
        }
    case Fall:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2.getSource();
                break;
            default:    //case leftRight:
                return hurtingJumpSprite.getSource();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2.getSource();
                break;
            default:    //case leftRight:
                return jumpSprite.getSource();
                break;
            }
        }
    case Attack:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingAttackSprite2.getSource();
                break;
            default:    //case leftRight:
                return buffedHurtingAttackSprite.getSource();
                break;
            }
        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedAttackSprite2.getSource();
                break;
            default:    //case leftRight:
                return buffedAttackSprite.getSource();
                break;
            }
        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingAttackSprite2.getSource();
                break;
            default:    //case leftRight:
                return hurtingAttackSprite.getSource();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return attackSprite2.getSource();
                break;
            default:    //case leftRight:
                return attackSprite.getSource();
                break;
            }
        }
    case JumpAttack:
        if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedJumpAttackSprite2.getSource();
                break;
            default:    //case leftRight:
                return buffedJumpAttackSprite.getSource();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpAttackSprite2.getSource();
                break;
            default:    //case leftRight:
                return jumpAttackSprite.getSource();
                break;
            }
        }
    case Buff:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingBuffSprite2.getSource();
                break;
            default:    //case leftRight:
                return hurtingBuffSprite.getSource();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return buffSprite2.getSource();
                break;
            default:    //case leftRight:
                return buffSprite.getSource();
                break;
            }
        }
    default:    //case Stand:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingStandSprite2.getSource();
                break;
            default:    //case leftRight:
                return buffedHurtingStandSprite.getSource();
                break;
            }

        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedStandSprite2.getSource();
                break;
            default:    //case leftRight:
                return buffedStandSprite.getSource();
                break;
            }

        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingStandSprite2.getSource();
                break;
            default:    //case leftRight:
                return hurtingStandSprite.getSource();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return standSprite2.getSource();
                break;
            default:    //case leftRight:
                return standSprite.getSource();
                break;
            }
        }
    }
}

QPixmap Toshizo::getTexture()
{
    switch (state) {
    case Run:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingRunSprite2.getTexture();
                break;
            default:    //case leftRight:
                return hurtingRunSprite.getTexture();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return runSprite2.getTexture();
                break;
            default:    //case leftRight:
                return runSprite.getTexture();
                break;
            }
        }
    case Jump:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2.getTexture();
                break;
            default:    //case leftRight:
                return hurtingJumpSprite.getTexture();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2.getTexture();
                break;
            default:    //case leftRight:
                return jumpSprite.getTexture();
                break;
            }
        }
    case Fall:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingJumpSprite2.getTexture();
                break;
            default:    //case leftRight:
                return hurtingJumpSprite.getTexture();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpSprite2.getTexture();
                break;
            default:    //case leftRight:
                return jumpSprite.getTexture();
                break;
            }
        }
    case Attack:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingAttackSprite2.getTexture();
                break;
            default:    //case leftRight:
                return buffedHurtingAttackSprite.getTexture();
                break;
            }
        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedAttackSprite2.getTexture();
                break;
            default:    //case leftRight:
                return buffedAttackSprite.getTexture();
                break;
            }
        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingAttackSprite2.getTexture();
                break;
            default:    //case leftRight:
                return hurtingAttackSprite.getTexture();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return attackSprite2.getTexture();
                break;
            default:    //case leftRight:
                return attackSprite.getTexture();
                break;
            }
        }
    case JumpAttack:
        if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedJumpAttackSprite2.getTexture();
                break;
            default:    //case leftRight:
                return buffedJumpAttackSprite.getTexture();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return jumpAttackSprite2.getTexture();
                break;
            default:    //case leftRight:
                return jumpAttackSprite.getTexture();
                break;
            }
        }
    case Buff:
        if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingBuffSprite2.getTexture();
                break;
            default:    //case leftRight:
                return hurtingBuffSprite.getTexture();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return buffSprite2.getTexture();
                break;
            default:    //case leftRight:
                return buffSprite.getTexture();
                break;
            }
        }
    default:    //case Stand:
        if (buffed && hurted)
        {
            switch (direct) {
            case rightLeft:
                return buffedHurtingStandSprite2.getTexture();
                break;
            default:    //case leftRight:
                return buffedHurtingStandSprite.getTexture();
                break;
            }

        }
        else if (buffed)
        {
            switch (direct) {
            case rightLeft:
                return buffedStandSprite2.getTexture();
                break;
            default:    //case leftRight:
                return buffedStandSprite.getTexture();
                break;
            }

        }
        else if (hurted)
        {
            switch (direct) {
            case rightLeft:
                return hurtingStandSprite2.getTexture();
                break;
            default:    //case leftRight:
                return hurtingStandSprite.getTexture();
                break;
            }
        }
        else
        {
            switch (direct) {
            case rightLeft:
                return standSprite2.getTexture();
                break;
            default:    //case leftRight:
                return standSprite.getTexture();
                break;
            }
        }
    }
}

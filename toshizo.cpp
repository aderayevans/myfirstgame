#include "toshizo.h"
#include <iostream>

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
    standSprite.setTexture("D://Users//Downloads//ToshizoGameAsset//implementStandingToshizo.png", 4, scale);
    buffedStandSprite.setTexture("D://Users//Downloads//ToshizoGameAsset//implementBuffedStandingToshizo.png", 4, scale);
    runSprite.setTexture("D://Users//Downloads//ToshizoGameAsset//implementRunningToshizo.png", 5, scale);
    runSprite.setSpeed(speed);                                                       // for moving
    jumpSprite.setTexture("D://Users//Downloads//ToshizoGameAsset//implementJumpingToshizo.png", 5, scale);
    attackSprite.setTexture("D://Users//Downloads//ToshizoGameAsset//implementAttackingToshizo.png", 2, scale);
    buffedAttackSprite.setTexture("D://Users//Downloads//ToshizoGameAsset//implementBuffedAttackingToshizo.png", 2, scale);
    buffSprite.setTexture("D://Users//Downloads//ToshizoGameAsset//implementBuffingToshizo.png", 3, scale);

    standSprite2.setTexture("D://Users//Downloads//ToshizoGameAsset//flippedStandingToshizo.png", 4, scale);
    buffedStandSprite2.setTexture("D://Users//Downloads//ToshizoGameAsset//flippedBuffedStandingToshizo.png", 4, scale);
    runSprite2.setTexture("D://Users//Downloads//ToshizoGameAsset//flippedRunningToshizo.png", 5, scale);
    jumpSprite2.setTexture("D://Users//Downloads//ToshizoGameAsset//flippedJumpingToshizo.png", 5, scale);
    attackSprite2.setTexture("D://Users//Downloads//ToshizoGameAsset//flippedAttackingToshizo.png", 2, scale);
    buffedAttackSprite2.setTexture("D://Users//Downloads//ToshizoGameAsset//flippedBuffedAttackingToshizo.png", 2, scale);
    buffSprite2.setTexture("D://Users//Downloads//ToshizoGameAsset//flippedBuffingToshizo.png", 3, scale);
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
    buffedStandSprite.setPosition(x - 52, y - 50);
    runSprite.setPosition(tempX, y);
    jumpSprite.setPosition(tempX, y);
    attackSprite.setPosition(tempX, y);
    buffedAttackSprite.setPosition(x - 65, y - 67);
    buffSprite.setPosition(x - 60, y - 105);

    standSprite2.setPosition(x, y);
    buffedStandSprite2.setPosition(x - 35, y - 51);
    runSprite2.setPosition(x, y);
    jumpSprite2.setPosition(x, y);
    attackSprite2.setPosition(x - 120, y);
    buffedAttackSprite2.setPosition(x - 120, y - 67);
    buffSprite2.setPosition(x - 90, y - 105);

    setHitBox(x, y, x + getWidth(), y + getHeight());
}

void Toshizo::setOrigin(double x, double y)
{
    setPosition(x, y);
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
    default:    //case Stand:
        return 0;
        break;
    }
}

void Toshizo::setClock()
{
    this->clock++;
    if (buffed)
    {
        if (!buffTime) buffed = false;
        else buffTime--;
    }
    switch (state)
    {
    case Stand:
        jumpPicture = 0;
        buffPicture = 0;
        jumpClock = 0;
        runTime = 0;
        buffClock = 0;
        attackPicture = 0;
        boostSpeed = 0;
        boostHigh = 0;
        doubleJump = false;
        standClock++;
        if (standClock > standSlowTime)
        {
            standPicture++;
            standClock = 0;
        }
        if (buffed)
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
        if (runTime == goCrazyTime)
        {
            boostSpeed = maxBoost;
            boostHigh = maxBoost;
        }
        runTime++;
        switch (direct) {
        case rightLeft:
            runSprite2.setClock(this->clock);
            break;
        default:    //case leftRight:
            runSprite.setClock(this->clock);
            break;
        }
        break;
    case Jump:
    {
        jumpClock++;
        if (jumpPicture != 0 || (doubleJump && jumpPicture == 3))
            setPosition(position.x(), position.y() - jumpRangeEachTimeID - boostHigh);
        if (jumpClock > jumpLimitTime)
        {
            setState(Fall);
            break;
        }
        if (jumpPicture >= 2 && !doubleJump)
        {
            jumpPicture = 1;
        }
        if (jumpPicture >= 3 && doubleJump)
        {
            jumpPicture = 3;
        }
        switch (direct)
        {
        case rightLeft:
            jumpSprite2.setClock(jumpPicture++);
            break;
        default:    //case leftRight:
            jumpSprite.setClock(jumpPicture++);
            break;
        }
        break;
    }
    case Attack:
    {
        attackClock++;
        if (attackClock > attackSlowTime)
        {
            attackPicture++;
            attackClock = 0;
        }
        if (attackPicture >= attackSprite.getTotalPicture())
        {
            setState(Stand);
        }
        if (buffed)
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
    case Buff:
    {
        if (leftEnergy < 500)
        {
            setState(Stand);
            break;
        }
        buffClock++;
        if (buffClock > buffSlowTime)
        {
            buffPicture++;
            buffClock = 0;
        }
        if (buffPicture >= buffSprite.getTotalPicture())
        {
            leftEnergy-=500;
            buffed = true;
            buffTime = maxBuffTime;
        }
        switch (direct)
        {
        case rightLeft:
            buffSprite2.setClock(buffPicture);
            break;
        default:    //case leftRight:
            buffSprite.setClock(buffPicture);
            break;
        }
        break;
    }
    default:    //case Fall:
        setPosition(position.x(), position.y() + fallingRangeEachTimeID);
        int fallAnimation;
        if (doubleJump) fallAnimation = 4;
        else fallAnimation = 2;
        switch (direct) {
        case rightLeft:
            jumpSprite2.setClock(fallAnimation);
            break;
        default:    //case leftRight:
            jumpSprite.setClock(fallAnimation);
            break;
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

int Toshizo::getFullHealth()
{
    return fullHealth;
}
int Toshizo::getLeftHealth()
{
    return leftHealth;
}
int Toshizo::getFullEnergy()
{
    return fullEnergy;
}
int Toshizo::getLeftEnergy()
{
    return leftEnergy;
}
QRectF Toshizo::getTarget()
{
    switch (state) {
    case Run:
        switch (direct) {
        case rightLeft:
            return runSprite2.getTarget();
            break;
        default:    //case leftRight:
            return runSprite.getTarget();
            break;
        }
    case Jump:
        switch (direct) {
        case rightLeft:
            return jumpSprite2.getTarget();
            break;
        default:    //case leftRight:
            return jumpSprite.getTarget();
            break;
        }
    case Fall:
        switch (direct) {
        case rightLeft:
            return jumpSprite2.getTarget();
            break;
        default:    //case leftRight:
            return jumpSprite.getTarget();
            break;
        }
    case Attack:
        if (buffed)
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
    case Buff:
        switch (direct) {
        case rightLeft:
            return buffSprite2.getTarget();
            break;
        default:    //case leftRight:
            return buffSprite.getTarget();
            break;
        }
    default:    //case Stand:
        if (buffed)
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
        switch (direct) {
        case rightLeft:
            return runSprite2.getSource();
            break;
        default:    //case leftRight:
            return runSprite.getSource();
            break;
        }
    case Jump:
        switch (direct) {
        case rightLeft:
            return jumpSprite2.getSource();
            break;
        default:    //case leftRight:
            return jumpSprite.getSource();
            break;
        }
    case Fall:
        switch (direct) {
        case rightLeft:
            return jumpSprite2.getSource();
            break;
        default:    //case leftRight:
            return jumpSprite.getSource();
            break;
        }
    case Attack:
        if (buffed)
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
    case Buff:
        switch (direct) {
        case rightLeft:
            return buffSprite2.getSource();
            break;
        default:    //case leftRight:
            return buffSprite.getSource();
            break;
        }
    default:    //case Stand:
        if (buffed)
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
        switch (direct) {
        case rightLeft:
            return runSprite2.getTexture();
            break;
        default:    //case leftRight:
            return runSprite.getTexture();
            break;
        }
    case Jump:
        switch (direct) {
        case rightLeft:
            return jumpSprite2.getTexture();
            break;
        default:    //case leftRight:
            return jumpSprite.getTexture();
            break;
        }
    case Fall:
        switch (direct) {
        case rightLeft:
            return jumpSprite2.getTexture();
            break;
        default:    //case leftRight:
            return jumpSprite.getTexture();
            break;
        }
    case Attack:
        if (buffed)
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
    case Buff:
        switch (direct) {
        case rightLeft:
            return buffSprite2.getTexture();
            break;
        default:    //case leftRight:
            return buffSprite.getTexture();
            break;
        }
    default:    //case Stand:
        if (buffed)
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

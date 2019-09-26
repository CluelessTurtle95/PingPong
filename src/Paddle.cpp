#include "Paddle.h"

Paddle::Paddle(int posx, int posy, int s, int w, int gH)
{
    originalx = posx;
    originaly = posy;
    x = posx;
    y = posy;
    score = 0;
    length = s;
    width = w;
    gameHeight = gH;
}

bool Paddle::isColliding(Ball * ball)
{
    if( fabs((double)(ball->getx() - x)) < width/2 + ball->getRadius())
    {
        if( fabs((double)(ball->gety() - y)) < length/2 + ball->getRadius())
        {
            return true;
        }
    }
    return false;
}
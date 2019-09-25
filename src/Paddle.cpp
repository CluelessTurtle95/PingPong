#include "Paddle.h"

Paddle::Paddle(int posx, int posy, int s)
{
    originalx = posx;
    originaly = posy;
    x = posx;
    y = posy;
    score = 0;
    length = s;
}

bool Paddle::isColliding(Ball ball)
{
    if( abs(ball.getx() - x) < width/2 + ball.getRadius())
    {
        if( abs(ball.gety() - y) < length/2 + ball.getRadius())
        {
            return true;
        }
    }
    return false;
}
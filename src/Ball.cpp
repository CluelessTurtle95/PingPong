#include "pingpong.h"
#include <stdlib.h>

Ball::Ball(float posx, float posy)
{
    originalx = posx;
    originaly = posy;
    x = posx;
    y = posy;
    velocity = Velocity();
}

void Ball::reset() 
{
    x = originalx;
    y = originaly;
    velocity = Velocity();
}

void Ball::move() 
{
    velocity.move(x,y);
}
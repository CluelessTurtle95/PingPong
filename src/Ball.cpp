#include "Ball.h"
#include <stdlib.h>

Ball::Ball(float posx, float posy, float r)
{
    originalx = posx;
    originaly = posy;
    x = posx;
    y = posy;
    velocity = Velocity();
    radius = r;
}

void Ball::reset() 
{
    x = originalx;
    y = originaly;
    velocity = Velocity();
}

void Ball::move(double time_diff) 
{
    velocity.move(x,y, time_diff);
}

void Ball::collide(float surfaceAngle, bool ran)
{
    velocity.collision(surfaceAngle, ran);
}
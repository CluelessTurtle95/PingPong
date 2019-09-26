#include "Ball.h"

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

void Ball::collide(float surfaceAngle)
{
    velocity.collision(surfaceAngle);
}

void Ball::deflect(sf::VideoMode videoMode)
{
    if(y > videoMode.height + 10)
    {
        y=videoMode.height - 2;
        //velocity.deflect();
    }
    if(y < 0)
    {
        y=0;
        //velocity.deflect();
	}
}
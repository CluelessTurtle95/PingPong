#include"Velocity.h"
#include <iostream>
const int VMax = 500;
const int VMin = 400;

Velocity::Velocity()
{
    magnitude = VMin + (rand() % (VMax-VMin) + 1);
    angle = 2* PI * static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
}

void Velocity::move(float & x, float & y, double time_diff)
{
    x += magnitude*cos(angle) * time_diff;
    y += magnitude*sin(angle) * time_diff;
}

void Velocity::collision(float surfaceAngle, bool ran=false)
{
    float diff = angle - surfaceAngle;
    angle = PI - diff;
    if(ran)
    {
        angle += 2*((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) - 1) * (PI/6) * (cos(angle) > 0 ? -1 : 1);
    }
}
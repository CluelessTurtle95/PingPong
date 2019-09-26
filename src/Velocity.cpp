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

void Velocity::collision(float surfaceAngle)
{

    float diff = angle - surfaceAngle;
    angle = PI - diff;
    if(cos(angle) < 1.f/4 && cos(angle) > -1.f/4)
    {
        if(sin(angle) > 0 && cos(angle) > 0)
        {
            angle -= PI/8.f;
        }
        else
        {
            angle += PI/8.f;
        }
        
    }
}
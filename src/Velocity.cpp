# include "pingpong.h"

const float PI = atan(1)*4; 
const int VMax = 2;
const int VMin = 1;


Velocity::Velocity()
{
    time_last_call = time(nullptr);
    magnitude = VMin + (rand() % VMax + 1);
    angle = PI * (rand() % 4) / 2; 
}

void Velocity::move(float & x, float & y)
{
    time_t current = time(nullptr);
    float diff = current - time_last_call;
    time_last_call = current;
    x += magnitude*cos(angle) * diff;
    y += magnitude*sin(angle) * diff;
}

void Velocity::collision(float surfaceAngle)
{
    float diff = angle - surfaceAngle;
    angle = PI - diff;
    angle += (rand() % 20 - 10)/100 * (diff-PI/2); // Differ by about 10 percent
}
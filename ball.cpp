#include "pingpong.h"
#include <stdlib.h>

ball::ball(int posx, int posy)
{
    originalx = posx;
    originaly = posy;
    x = posx;
    y = posy;
    direction = stop;
}

void ball::reset() 
{
    x = originalx;
    y = originaly;
    direction = stop;
}

void ball::random()
{
    direction = (edir)((rand() % 6) + 1);
}

void ball::move() 
{
    switch (direction)
    {
    case stop:
        break;
    case Left:
        x--;
        break;
    case Right:
        x++;
        break;
    case upleft:
        x--; y--;
        break;
    case downleft:
        x--; y++;
        break;
    case upright:
        x++; y--;
        break;
    case downright:
        x++; y++;
        break;
    default:
        break;
    }
}
#pragma once

#include "pingpong.h"

paddle::paddle() 
{
    x = y = 0;
}

paddle::paddle(int posx, int posy) : paddle()
{
    originalx = posx;
    originaly = posy;
    x = posx;
    y = posy;
}
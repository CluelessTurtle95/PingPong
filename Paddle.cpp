#pragma once

#include "pingpong.h"

Paddle::Paddle(int posx, int posy, int s)
{
    originalx = posx;
    originaly = posy;
    x = posx;
    y = posy;
    score = 0;
    size = s;
}
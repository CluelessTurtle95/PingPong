#pragma once
#include "Ball.h"

const int paddleSensitivity = 1;

class Paddle
{
private:
	
    int x, y;
	int originalx, originaly;
	unsigned int score;
	int length;
	int width;

public:
	Paddle(int posx, int posy, int length);

	inline void reset()
	{
		x = originalx;
		y = originaly;
	}	

	inline int getx()
	{
		return x;
	}

	inline int gety()
    {
		return y;
	}

    inline void moveup() 
	{
		y += paddleSensitivity;
	}

	inline void movedown()
	{
		y-= paddleSensitivity;
	}

	inline void scoreup()
	{
		score += 1;
	}

	inline void scoredown()
	{
		score += -1;
	}

	inline int getscore()
	{
		return score;
	}

	inline int getsize()
	{
		return length;
	}

	bool isColliding(Ball ball);
};

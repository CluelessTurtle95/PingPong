#pragma once
#include "Ball.h"

const int paddleSensitivity = 10;

class Paddle
{
private:
	
    int x, y;
	int originalx, originaly;
	unsigned int score;
	int length;
	int width;
	int gameHeight;

public:
	Paddle(int posx, int posy, int length, int width, int gH);

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
		if(y < gameHeight - length/2)
			y += paddleSensitivity;
	}

	inline void movedown()
	{
		if(y > length/2)
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

    inline int getwidth()
	{
		return width;
	}

	inline void scaleSize(float factor)
	{
		length = length * factor;
	}

	bool isColliding(Ball *  ball);
};

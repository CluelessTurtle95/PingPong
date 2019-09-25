#pragma once
#include "Velocity.h"

class Ball
{
private:
	
    float x, y;
	float radius;
	float originalx, originaly;
	Velocity velocity;

public:
	Ball(float posx, float posy);

	void reset();

	inline void changevelocity(Velocity v)
	{
		velocity = v;
	}

	inline float getx()
	{
		return x;
	}

	inline float gety()
    {
		return y;
	}

	inline Velocity getVelocity()
	{
		return velocity;
	}

	inline float getRadius()
	{
		return radius;
	}

	void move() ;
};

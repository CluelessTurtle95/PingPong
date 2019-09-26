#pragma once

#include<cmath>
#include <ctime>
#include <stdlib.h>

const float PI = atan(1)*4; 

class Velocity
{
	private:

	float angle;
	float magnitude;
	time_t time_last_call;

	public:
	float inline getVelocity()
	{
		return magnitude;
	}
	float inline getAngle()
	{
		return angle;
	}
	Velocity();
	void move(float & x, float & y, double time_diff);
	void collision(float surfaceAngle,bool);

};

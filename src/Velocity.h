#pragma once

#include<cmath>
#include <ctime>
#include <stdlib.h>

class Velocity
{
	private:

	float angle;
	float magnitude;
	time_t time_last_call;

	public:
	Velocity();
	void move(float & x, float & y);
	void collision(float surfaceAngle);

};

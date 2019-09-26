#pragma once


#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>

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
	void deflect()
	{
		angle += PI;
	}
	void move(float & x, float & y, double time_diff);
	void collision(float surfaceAngle);

};

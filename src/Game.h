#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>

#include <chrono>
#include <thread>
#include<string>

#include "Paddle.h"
#include "Ball.h"

class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;

	Ball *ball;
	Paddle *player1;
	Paddle *player2;

	void initwindow(int h, int w);
	void parseCode();

	double time_diff;

	std::string message;
    
	sf::RectangleShape paddle1,paddle2;
	sf::CircleShape ping;
public:

	Game(int w, int h);

	~Game();

	void scoreup(Paddle * player);

	void scoredown(Paddle * player);

	inline bool running()
	{
		return window->isOpen();
	}

	inline std::string getMessage()
	{
		return message;
	}

	void render();

	void logic();

	void run(int fps);
};

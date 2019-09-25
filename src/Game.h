#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>

#include "Paddle.h"
#include "Ball.h"

class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;

	char up1, up2, down1, down2;
	bool quit;
	
	Ball *ball;
	Paddle *player1;
	Paddle *player2;

	void initwindow(int h, int w);
public:

	Game(int w, int h, int s);

	~Game();

	void scoreup(Paddle * player);

	void scoredown(Paddle * player);

	inline bool running()
	{
		return window->isOpen();
	}

	void render();

	void logic();

	void run();
};

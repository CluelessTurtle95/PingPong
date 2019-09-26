#pragma once

#include <chrono>
#include <thread>
#include<string>

#include "Paddle.h"
#include "Ball.h"
#include <vector>

class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;

	std::vector<Ball * > balls;
	Paddle *player1; 
	Paddle *player2;

	void initwindow(int h, int w);
	sf::CircleShape * initping(Ball *);

	void parseCode();

	double time_diff;

	std::string message;
    sf::Font font;
	sf::Text displayText;

	sf::RectangleShape paddle1,paddle2;
	std::vector<sf::CircleShape *> pings;

	bool pl1Flag;
	bool pl2Flag;
	int currentScoreLimit;

public:

	Game(int w, int h);

	~Game();

	void scoreup(Paddle * player);

	void scoredown(Paddle * player);

	void reset();

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

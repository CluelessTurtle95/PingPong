#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>

enum edir
{
	stop, Left , upleft, downleft , Right, upright, downright
};

class Ball
{
private:
	
    int x, y;
	int originalx, originaly;
	edir direction;

public:
	Ball(int posx, int posy);

	void reset();

	inline void changedirection(edir d)
	{
		direction = d;
	}

	inline int getx()
	{
		return x;
	}

	inline int gety()
    {
		return y;
	}


	inline edir getdirection()
	{
		return direction;
	}

	void random();

	void move() ;
};

class Paddle
{
private:
	
    int x, y;
	int originalx, originaly;
	int score;
	int size;

public:
	Paddle(int posx, int posy, int size);

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
		y--;
	}

	inline void movedown()
	{
		y++;
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
		return size;
	}
};

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
	Game();

	Game(int w, int h, int s);

	~Game();

	void scoreup(Paddle * player);

	void scoredown(Paddle * player);

	inline bool running()
	{
		return window->isOpen();
	}

	void draw();

	void input();

	void logic();

	void run();
};

#pragma once

enum edir
{
	stop, Left , upleft, downleft , Right, upright, downright
};

class ball
{
private:
	
    int x, y;
	int originalx, originaly;
	edir direction;

public:
	ball(int posx, int posy);

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

class paddle
{
private:
	
    int x, y;
	int originalx, originaly;

public:
	paddle();

	paddle(int posx, int posy);

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
};

class gamemanager
{
private:
	int score1, score2;
	char up1, up2, down1, down2;
	int width, height;
	bool quit;
	ball *cball;
	paddle *player1;
	paddle *player2;
public:
	gamemanager(int w, int h);

	~gamemanager();

	void scoreup(paddle * player);

	void draw();

	void input();

	void logic();

	void run();
};

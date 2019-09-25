// Ping_Pong_Game.cpp : Defines the entry point for the console application.
// pingpong game - my first game! 
#include <iostream>
#include <time.h>
#include <curses.h>
//#include <ncurses.h>

using namespace std;


int main()
{
	char choice;
	int x, y;
	system("Title Ping-Pong");
	cout << "Start game?" << endl;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		system("mode 100");
		cout << "Enter height and width of game window; recommended ~ 35 each";
		cin >> x >> y;
		gamemanager c(x, y);
		c.run();
		system("pause");
	}
    return 0;
}

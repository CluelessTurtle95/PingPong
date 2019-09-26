#include "Game.h"
#include <iostream>

using namespace std;
bool logger = false;

int main()
{
    // Setup
	Game game = Game(800,600);
    time_t now = time(nullptr);
    int fps = 0,prev_fps=7000;
    bool first = true;
    // Game Loop
    while(game.running())
    {
        fps++;
        game.run(prev_fps);
        if(time(nullptr) - now > 1)
        {
            now = time(nullptr);
            prev_fps = fps;
            fps = 0;
            if(first)
                cout << "Speed Adjusted!\n";
            if(logger & !first)
            {
                cout << "\033[2J\033[1;1H" << game.getMessage();
            }
            first = false;    
        }
    }
    // App End
    return 0;
}

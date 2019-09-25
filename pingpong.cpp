
#include"pingpong.h"

int main()
{
    // Setup
	Game game;

    // Game Loop
    while(game.running())
    {
        game.run();
    }
    // App End
    return 0;
}

#include "Game.h"

int main()
{
    // Setup
	Game game = Game(800,600,10);
    
    // Game Loop
    while(game.running())
    {
        game.run();
    }
    // App End
    return 0;
}

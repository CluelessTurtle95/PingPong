#include "Game.h"

void Game::initwindow(int height, int width)
{
    this->videoMode.height = height;
    this->videoMode.width = width;
    window = new sf::RenderWindow(videoMode, "Ping Pong", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game(int w, int h, int paddleSize)
{
    srand(time(NULL));

    window = nullptr;

    quit = false;
    up1 = 'w';
    up2 = 'i';
    down1 = 's';
    down2 = 'k';
    
    ball = new Ball(w / 2, h / 2);
    player1 = new Paddle(5, h / 2 , paddleSize);
    player2 = new Paddle(w - 5, h / 2 , paddleSize);
    initwindow(h,w);
}

Game::~Game()
{
    delete window;
    delete ball; 
    delete player1;
    delete player2;
}

void Game::scoreup(Paddle * player)
{
    player->scoreup();    
    ball->reset();
    player1->reset();
    player2->reset();
}

void Game::scoredown(Paddle * player)
{
    player->scoredown();    
    ball->reset();
    player1->reset();
    player2->reset();
}

void Game::logic()
{
    int ballx = ball->getx();
    int bally = ball->gety();

    for (int i = 0; i < player1->getsize(); i++)
    {
        if (  -3 < (int)ballx - (int)player1->getx() && ballx - player1->getx() < 3 )
            if (bally == player1->gety() + i)
                ball->changedirection((edir)((rand() % 3) + 4));
    }

    for (int i = 0; i < player2->getsize(); i++)
    {
        if ( -3 < (int)ballx - (int)player2->getx() && ballx - player2->getx() < 3)
            if (bally == player2->gety() + i)
                ball->changedirection((edir)((rand() % 3) + 1));
    }

    if (bally == videoMode.height - 1)
    {
        ball->changedirection(
            ball->getdirection() == downright ? upright : upleft);
    }
    
    if (bally == 0)
    {
        ball->changedirection(
            ball->getdirection() == upright ? downright : downleft);
    }
    if (ballx == videoMode.width - 1)
        scoreup(player1);
    if (ballx == 0)
        scoreup(player2);
}

void Game::render()
{

}

void Game::run()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed :
            window->close();
            break;
        case sf::Event::KeyPressed :
            if(ev.key.code == sf::Keyboard::Escape)
                window->close();
            break;

        default:
            break;
        }
    }
    // Input
    
    // Update
    //logic();
    
    // Render
    window->clear(sf::Color(0,0,255,255));
    render();
    window->display();
    // Draw 

    window->display();
}
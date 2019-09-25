#include "pingpong.h"
#include <time.h>
#include <stdlib.h>

void Game::initwindow(int height, int width)
{
    this->videoMode.height = height;
    this->videoMode.width = width;
    window = new sf::RenderWindow(videoMode, "Ping Pong", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
    Game(800,600,10);
}

Game::Game(int w, int h, int paddleSize)
{
    srand(time(NULL));

    this->window = nullptr;

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
    delete window, ball, player1, player2;
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
/*
void Game::draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            int ballx = 
            ball->getx();
            int bally = 
            ball->gety();
            int player1x = player1->getx();
            int player2x = player2->getx();
            int player1y = player1->gety();
            int player2y = player2->gety();

            if (j == 0)
                cout << "\xB2";
            if (ballx == j && bally == i)
                cout << "o";
            else if (player1x == j && player1y == i)
                cout << "\xDB";
            else if (player2x == j && player2y == i)
                cout << "\xDB";
            else if (j == width)
                cout << "\xB2";
            else if (player1x == j && player1y + 1 == i)
                cout << "\xDB";
            else if (player1x == j && player1y + 2 == i)
                cout << "\xDB";
            else if (player1x == j && player1y + 3 == i)
                cout << "\xDB";
            else if (player2x == j && player2y + 1 == i)
                cout << "\xDB";
            else if (player2x == j && player2y + 2 == i)
                cout << "\xDB";
            else if (player2x == j && player2y + 3 == i)
                cout << "\xDB";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    cout << "Score 1: " << score1 << "Score 2: " << score2 << endl;
}
*/

/*
void Game::input() 
{
    
    ball->move();

    int ballx = 
    ball->getx();
    int bally = 
    ball->gety();
    int player1x = player1->getx();
    int player2x = player2->getx();
    int player1y = player1->gety();
    int player2y = player2->gety();

    //if (_kbhit()) 
    {
        char current = getch();
        if (current == up1)
            if (player1y > 0)
                player1->moveup();
        if (current == down1)
            if (player1y + 4 < height)
                player1->movedown();
        if (current == up2)
            if (player2y > 0)
                player2->moveup();
        if (current == down2)
            if (player2y + 4 < height)
                player2->movedown();

        if (
            ball->getdirection() == stop)
            
            ball->random();

        if (current == 'q')
            quit = true;
    }

}
*/

void Game::logic()
{
    int ballx = ball->getx();
    int bally = ball->gety();
    int player2x = player2->getx();
    int player1y = player1->gety();
    int player2y = player2->gety();

    for (int i = 0; i < player1->getsize(); i++)
    {
        if (  -3 < ballx - player1->getx() < 3 )
            if (bally = player1->gety() + i)
                ball->changedirection((edir)((rand() % 3) + 4));
    }

    for (int i = 0; i < player2->getsize(); i++)
    {
        if ( -3 < ballx - player2->getx() < 3)
            if (bally = player2->gety() + i)
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
    logic();
    
    // Render
    window->clear(sf::Color(0,0,255,255));
    
    // Draw 

    window->display();
}

#include "Game.h"

void Game::initwindow(int height, int width)
{
    this->videoMode.height = height;
    this->videoMode.width = width;
    window = new sf::RenderWindow(videoMode, "Ping Pong", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game(int w, int h)
{
    srand(time(NULL));

    window = nullptr;

    player1 = new Paddle(15,h/2,60,16,h);
    player2 = new Paddle(w - 15,h/2,60,16,h);
    ball = new Ball(w/2,h/2 +10, 10);

    initwindow(h,w);

    paddle1 =  sf::RectangleShape(sf::Vector2f(player1->getwidth(), player1->getsize()));
    paddle2 =  sf::RectangleShape(sf::Vector2f(player2->getwidth(), player2->getsize()));
    ping = sf::CircleShape(50);
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
    
    if(player1->isColliding(ball))
    {
        ball->collide(0,false);
    }
    if(player2->isColliding(ball))
    {
        ball->collide(0,false);
    }
    if(fabs((double)(bally - videoMode.height)) < ball->getRadius() )
    {
        ball->collide(PI,false);
    }
    if(bally < ball->getRadius() )
    {
        ball->collide(PI,true);
    }
    if ( fabs((double)(ballx - videoMode.width)) < ball->getRadius() )
    {    
        scoreup(player1);
    }
    if (ballx < ball->getRadius())
    {    
        scoreup(player2);
    }
    ball->move(time_diff);
}

void Game::render()
{   
    paddle1.setFillColor(sf::Color::Red);
    paddle2.setFillColor(sf::Color::Red);

    paddle1.setPosition(sf::Vector2f(player1->getx()-player1->getwidth()/2,player1->gety()-player1->getsize()/2));
    paddle2.setPosition(sf::Vector2f(player2->getx()-player2->getwidth()/2,player2->gety()-player2->getsize()/2));
    ping.setFillColor(sf::Color::Yellow);
    ping.setRadius(ball->getRadius());
    ping.setPosition(sf::Vector2f(ball->getx(),ball->gety()));

    sf::Text displayText;
    displayText.setString(message);
    displayText.setPosition(sf::Vector2f(videoMode.width/2,videoMode.height/2));
    displayText.setFillColor(sf::Color::White);
    window->draw(paddle1);
    window->draw(paddle2);
    window->draw(ping);
    window->draw(displayText);
}

void Game::parseCode()
{
    switch (ev.key.code)
    {
    case sf::Keyboard::Escape:
        window->close();
        break;
    case sf::Keyboard::S:
        player1->moveup();
        break;
    case sf::Keyboard::W:
        player1->movedown();
        break;
    case sf::Keyboard::K:
        player2->moveup();
        break;
    case sf::Keyboard::I:
        player2->movedown();
        break;
    default:
        break;
    }
}

void Game::run(int fps)
{
    time_diff = 1.0/fps;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed :
            window->close();
            break;
        case sf::Event::KeyPressed :
            parseCode();
            break;
        default:
            break;
        }
    }
    
    // Update
    logic();
    
    // Render
    window->clear(sf::Color(0,0,255,255));
    render();
    window->display();
    // Draw 

    window->display();

    message = "Player 1 Score : " + std::to_string(player1->getscore()) + " Player 2 Score : " + std::to_string(player2->getscore())+
                "\n Ball X,Y : " + std::to_string(ball->getx()) + " , " + std::to_string(ball->gety()) + " Ball Velocity : " + std::to_string(ball->getVelocity().getVelocity()) +
                "\n Fps : " + std::to_string(1.0 / time_diff)+ "\n";
}
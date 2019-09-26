#include "Game.h"

void Game::initwindow(int height, int width)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    this->videoMode.height = height;
    this->videoMode.width = width;
    window = new sf::RenderWindow(videoMode, "Ping Pong", sf::Style::Titlebar | sf::Style::Close, settings);

    paddle1 =  sf::RectangleShape(sf::Vector2f(player1->getwidth(), player1->getsize()));
    paddle2 =  sf::RectangleShape(sf::Vector2f(player2->getwidth(), player2->getsize()));
    

    paddle1.setFillColor(sf::Color::Red);
    paddle2.setFillColor(sf::Color::Red);

    if(!font.loadFromFile("/home/parth/SFML_C-_Simple_Games/pingpong/src/Fonts/aerial.ttf"))
    {
        throw "Unable To load font!";
    }
    displayText.setFont(font);
    displayText.setCharacterSize(12);
    displayText.setFillColor(sf::Color::Red);
    displayText.setPosition(sf::Vector2f(videoMode.width/2 - 200 ,videoMode.height -50));

    window->setFramerateLimit(60);
}

Game::Game(int w, int h)
{
    srand(time(NULL));

    window = nullptr;

    player1 = new Paddle(15,h/2,60,16,h);
    player2 = new Paddle(w - 15,h/2,60,16,h);
    
    pl1Flag = false;
    pl2Flag = false;
    currentScoreLimit = 0;

    initwindow(h,w);
}

Game::~Game()
{
    delete window;
    for(Ball * ball : balls)
        delete ball; 
    delete player1;
    delete player2;
}

void Game::reset()
{
    for(Ball * ball : balls)
        ball->reset();
    player1->reset();
    player2->reset();
}

void Game::scoreup(Paddle * player)
{
    player->scoreup();    
}

sf::CircleShape * Game::initping(Ball * ball)
{
    sf::CircleShape * ping = new sf::CircleShape(50);
    ping->setFillColor(sf::Color::Green);
    ping->setRadius(ball->getRadius());
    ping->setOutlineColor(sf::Color::Black);
    ping->setOutlineThickness(ball->getRadius()/3);
    return ping;
}

void Game::logic()
{
    if( (player1->getscore() >= currentScoreLimit)| (player2->getscore() >= currentScoreLimit))
    {
        currentScoreLimit += 3;
        Ball * tempBall = new Ball(videoMode.width/2,videoMode.height/2 +10, 10);
        balls.push_back(tempBall);
        pings.push_back(initping(tempBall));
        player1->scaleSize(1.3);
        paddle1.scale(sf::Vector2f(1,1.3));
        player2->scaleSize(1.3);
        paddle2.scale(sf::Vector2f(1,1.3));
    }

    for(Ball * ball : balls)
    {
        int ballx = ball->getx();
        int bally = ball->gety();
        
        if(player1->isColliding(ball))
        {
            if (!pl1Flag)
            {
                ball->collide(0);
                pl1Flag = true;
            }
        }
        else
        {
            pl1Flag = false;
        }
        
        if(player2->isColliding(ball))
        {
            if (!pl2Flag)
            {
                pl2Flag = true;
                ball->collide(0);
            }
        }
        else
        {
            pl2Flag = false;
        }
        if(fabs((double)(bally - videoMode.height)) < ball->getRadius() )
        {
            ball->collide(PI);
        }
        if(bally < ball->getRadius() )
        {
            ball->collide(PI);
        }
        if ( fabs((double)(ballx - videoMode.width)) < ball->getRadius() )
        {    
            player1->scoreup();
            ball->reset();
        }
        if (ballx < ball->getRadius())
        {    
            player2->scoreup();
            ball->reset();
        }
        ball->move(time_diff);
        ball->deflect(videoMode);
    }
}

void Game::render()
{   

    paddle1.setPosition(sf::Vector2f(player1->getx()-player1->getwidth()/2,player1->gety()-player1->getsize()/2));
    paddle2.setPosition(sf::Vector2f(player2->getx()-player2->getwidth()/2,player2->gety()-player2->getsize()/2));
    
    for(size_t i=0 ; i < balls.size() ; i++)
    {
        pings[i]->setPosition(sf::Vector2f(balls[i]->getx(),balls[i]->gety()));
    }
    displayText.setString(message);
    
    window->draw(paddle1);
    window->draw(paddle2);
    for(sf::CircleShape * ping : pings)
    {
        window->draw(*ping);
    }
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
    window->clear(sf::Color(17,242,160,255));
    render();
    window->display();
    // Draw 

    window->display();

    message = "Player 1 Score : " + std::to_string(player1->getscore()) + " Player 2 Score : " + std::to_string(player2->getscore())+
            "\nBalls : " + std::to_string(balls.size()) +
            "\nFps : " + std::to_string((int)(1.0 / time_diff))+ "\n";
}
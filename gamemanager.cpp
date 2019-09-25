#include "pingpong.h"
#include <time.h>
#include <stdlib.h>

gamemanager::gamemanager(int w, int h)
{
    srand(time(NULL));
    quit = false;
    up1 = 'w';
    up2 = 'i';
    down1 = 's';
    down2 = 'k';
    score1 = score2 = 0;
    width = w; height = h;
    cball = new ball(w / 2, h / 2);
    player1 = new paddle(1, h / 2 - 3);
    player2 = new paddle(w - 2, h / 2 - 3);
}

gamemanager::~gamemanager()
{
    delete cball, player1, player2;
}

void gamemanager::scoreup(paddle * player)
{
    if (player == player1)
        score1++;
    else if (player == player2)
        score2++;

    cball->reset();
    player1->reset();
    player2->reset();
}
/*
void gamemanager::draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            int ballx = cball->getx();
            int bally = cball->gety();
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
void gamemanager::input() 
{
    cball->move();

    int ballx = cball->getx();
    int bally = cball->gety();
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

        if (cball->getdirection() == stop)
            cball->random();

        if (current == 'q')
            quit = true;
    }

}
*/

void gamemanager::logic()
{
    int ballx = cball->getx();
    int bally = cball->gety();
    int player1x = player1->getx();
    int player2x = player2->getx();
    int player1y = player1->gety();
    int player2y = player2->gety();

    for (int i = 0; i < 4; i++)
    {
        if (ballx == player1x + 1)
            if (bally = player1y + i)
                cball->changedirection((edir)((rand() % 3) + 4));
    }

    for (int i = 0; i < 4; i++)
    {
        if (ballx == player2x - 1)
            if (bally = player2y + i)
                cball->changedirection((edir)((rand() % 3) + 1));
    }

    if (bally == height - 1)
    {
        cball->changedirection(cball->getdirection() == downright ? upright : upleft);
    }
    
    if (bally == 0)
    {
        cball->changedirection(cball->getdirection() == upright ? downright : downleft);
    }
    if (ballx == width - 1)
        scoreup(player1);
    if (ballx == 0)
        scoreup(player2);
}

void gamemanager::run()
{
    while (!quit) 
    {
        draw();
        input();
        logic();
    }
}

#include <iostream>
#include <time.h>
#include "screen.h"
#include "board.h"
#include "ball.h"

// Defining virtual keys macroes
#define VK_W 0x57
#define VK_S 0x53

// Function returning -1 or 1
int one_rand()
{
    int value = rand() % 2;
    if (value) return 1;
    else return -1;
}

int main()
{
    // Screen setup
    Screen screen(120, 30);
    screen.setup(L' ');
	HANDLE Console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(Console);
	DWORD dwBytesWritten = 0;

    // Start randomization
    srand(time(NULL));

    // Game objects
    Board board_left(2, 12, 17, 0);
    Board board_right(117, 12, 17, 0);
    Ball ball(59, 14, one_rand(), one_rand());

    while (true)
    {
        
        // Input
        
        // -- Left board control
        if (GetAsyncKeyState(VK_W) && board_left.getY1() > 1)
        {
            board_left.changeY1(board_left.getY1() - 1);
            board_left.changeY2(board_left.getY2() - 1);
        }
        else if (GetAsyncKeyState(VK_S) && board_left.getY2() < 28)
        {
            board_left.changeY1(board_left.getY1() + 1);
            board_left.changeY2(board_left.getY2() + 1);
        }
        
        // -- Right board control
        if (GetAsyncKeyState(VK_UP) && board_right.getY1() > 1)
        {
            board_right.changeY1(board_right.getY1() - 1);
            board_right.changeY2(board_right.getY2() - 1);
        }
        else if (GetAsyncKeyState(VK_DOWN) && board_right.getY2() < 28)
        {
            board_right.changeY1(board_right.getY1() + 1);
            board_right.changeY2(board_right.getY2() + 1);
        }



        // Game logic

        // -- Checking is game over
        if (board_left.getPoints() == 2 || board_right.getPoints() == 2)
            break;

        // -- Detecting wall collisions and adding points
        if (ball.getX() == 1)
        {
            board_right.addPoint();
            ball.changeX(59);
            ball.changeY(14);
            ball.changeVX(1);
            ball.changeVY(one_rand());
            Sleep(2000);
        }
        if (ball.getX() == screen.getWidth() - 2)
        {
            board_left.addPoint();
            ball.changeX(59);
            ball.changeY(14);
            ball.changeVX(-1);
            ball.changeVY(one_rand());
            Sleep(2000);
        }     

        // -- Detecting floor and ceiling collisions
        if (ball.getY() == 1 || ball.getY() == screen.getHeight() - 2)
            ball.changeVY(ball.getVY() * (-1));

        // -- Detecting board collisions
        // ---- Left board
        if (ball.getX() == board_left.getX() + 1 && ball.getY() >= board_left.getY1() && ball.getY() <= board_left.getY2())
            ball.changeVX(ball.getVX() * (-1));
        // ---- Right board
        else if (ball.getX() == board_right.getX() - 1 && ball.getY() >= board_right.getY1() && ball.getY() <= board_right.getY2())
            ball.changeVX(ball.getVX() * (-1));

        // -- Updating position
        ball.updatePosition();



        // Drawing objects
        
        // -- Drawing game frame
        screen.drawRectangle(0, screen.getHeight() - 1, 0, screen.getWidth() - 1, L'X');

        // -- Drawing left board
        screen.drawLine(board_left.getX(), board_left.getY1(), board_left.getX(), board_left.getY2(), L'O');

        // -- Drawing left board
        screen.drawLine(board_right.getX(), board_right.getY1(), board_right.getX(), board_right.getY2(), L'O');

        // -- Drawing ball
        screen.drawPoint(ball.getX(), ball.getY(), L'@');



        // Displaying frame
        wsprintfW(&screen.array[(int)(screen.getWidth() * 1.5) - 2], L"%d - %d", board_left.getPoints(), board_right.getPoints());
        WriteConsoleOutputCharacterW(Console, screen.array, screen.getWidth() * screen.getHeight(), {0,0}, &dwBytesWritten);



        // Screen freeze
        Sleep(20);



        // Clearing screen
        screen.clear(L' ');
    }

    // Displaying the winner
    if (board_left.getPoints() == 2)
        wsprintfW(&screen.array[(int)(screen.getWidth() * 1.5) - 10], L"Game over! Left won!");
    
    else if (board_right.getPoints() == 2)
        wsprintfW(&screen.array[(int)(screen.getWidth() * 1.5) - 10], L"Game over! Right won!");

    wsprintfW(&screen.array[(int)(screen.getWidth() * 2.5) - 6], L"PRESS SPACE");



    // Displaying frame
    WriteConsoleOutputCharacterW(Console, screen.array, screen.getWidth() * screen.getHeight(), {0,0}, &dwBytesWritten);



    // Waiting for space
    while(!GetAsyncKeyState(VK_SPACE)) {}
}
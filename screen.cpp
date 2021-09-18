#include "screen.h"

#include <windows.h>

void Screen::setup(wchar_t c)
{
    for (int i = 0; i < width * height; i++)
        array[i] = c;
}

int Screen::getWidth() const { return width; }

int Screen::getHeight() const { return height; }

void Screen::drawPoint(int x, int y, wchar_t c)
{
    array[x + width * y] = c;
}

void Screen::drawLine(int x1, int y1, int x2, int y2, wchar_t c)
{
    double a, b;
    if (x1 != x2)
    {
        a = (double)(y2 - y1) / (x2 - x1);
        b = y2 - a * x2;
    
        for (int i = 0; i < width * height; i++)
        {
            int x = i % width;
            int y = i / width;
            if (y == (int)(a * (double)x + b) && x1 <= x2 && x >= x1 && x <= x2)
                array[i] = c;
            else if (y == (int)(a * (double)x + b) && x1 > x2 && x <= x1 && x >= x2)
                array[i] = c;        
        }
    }

    else
    {
        for (int i = 0; i < width * height; i++)
        {
            int x = i % width;
            int y = i / width;
            if (x == x1 && y1 <= y2 && y >= y1 && y <= y2)
                array[i] = c;
            else if (x == x1 && y1 > y2 && y >= y2 && y <= y1)
                array[i] = c;
        }
    } 
}

void Screen::drawRectangle(int top, int bottom, int right, int left, wchar_t c)
{
    for (int i = right; i <= left; i++)
    {
        drawPoint(i, top, c);
        drawPoint(i, bottom, c);
    }
    for (int i = top + 1; i <= bottom - 1; i++)
    {
        drawPoint(right, i, c);
        drawPoint(left, i, c);
    }
}

void Screen::clear(wchar_t c)
{
    for (int i = 0; i < width * height; i++)
        array[i] = c;
}

Screen::Screen(int w, int h)
{
    width = w;
    height = h;
    array = new wchar_t [width * height];
    this->setup(L'*');
}

Screen::~Screen()
{
    delete [] array;
}
#ifndef SCREEN_H
#define SCREEN_H

#include <windows.h>

class Screen
{
public:
    void setup(wchar_t);

    int getWidth() const;
    
    int getHeight() const;

    void drawPoint(int, int, wchar_t);

    void drawLine(int, int, int, int, wchar_t);

    void drawRectangle(int, int, int, int, wchar_t);

    void clear(wchar_t);

    Screen(int, int);
    
    ~Screen();
    
private:
    int width;
    int height;
public:
    wchar_t* array;
};

#endif
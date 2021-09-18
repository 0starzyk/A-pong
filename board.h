#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
    int getX() const;
    int getY1() const;
    int getY2() const;
    int getPoints() const;
    void changeY1(int value);
    void changeY2(int value);
    void addPoint();

    Board(int X, int Y1, int Y2, int P);
private:
    int x;
    int y1, y2;
    int points;
};

#endif
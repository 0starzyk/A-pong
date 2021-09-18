#include "board.h"

int Board::getX() const { return x; }
int Board::getY1() const { return y1; }
int Board::getY2() const { return y2; }
int Board::getPoints() const { return points; }
void Board::changeY1(int value) { y1 = value; }
void Board::changeY2(int value) { y2 = value; }
void Board::addPoint() { points++; }

Board::Board(int X, int Y1, int Y2, int P) : x(X), y1(Y1), y2(Y2), points(P) {}
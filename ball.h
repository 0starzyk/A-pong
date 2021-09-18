#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    int getX() const;
    int getY() const;
    int getVX() const;
    int getVY() const;
    void changeX(int);
    void changeY(int);
    void updateX(int);
    void updateY(int);
    void updatePosition(int);
    void updatePosition();
    void changeVX(int);
    void changeVY(int);
    Ball(int X, int Y, int VX, int VY);
private:
    int x, y;
    int vx, vy;
};

#endif
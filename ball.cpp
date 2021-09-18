#include "ball.h"

int Ball::getX() const { return x; }
int Ball::getY() const { return y; }
int Ball::getVX() const { return vx; }
int Ball::getVY() const { return vy; }
void Ball::changeX(int value) { x = value; }
void Ball::changeY(int value) { y = value; }
void Ball::updateX(int t) { x += vx * t; }
void Ball::updateY(int t) { y += vy * t; }
void Ball::updatePosition(int t) { updateX(t); updateY(t); }
void Ball::updatePosition() { updateX(1); updateY(1); }
void Ball::changeVX(int value) { vx = value; }
void Ball::changeVY(int value) { vy = value; }
Ball::Ball(int X, int Y, int VX, int VY) : x(X), y(Y), vx(VX), vy(VY) {}

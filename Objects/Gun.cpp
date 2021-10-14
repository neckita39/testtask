#include "Gun.h"
Gun::Gun() {}
Gun::Gun(double start_x, double start_y): m_x(start_x), m_y(start_y) {}
double Gun::getX() const{return m_x;}
double Gun::getY() const{return m_y;}
void Gun::setStartX(double start_x)  { m_x = start_x; }
void Gun::setStartY(double start_y)  { m_y = start_y; }

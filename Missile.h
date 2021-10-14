#pragma once
#include <math.h>
#include <ctime>
#include "TimeController.h"
#include <iostream>
class Missile
{
public:
    Missile();
    void setStartX(double start_x);
    void setStartY(double start_y);
    void setX(double x);
    void setY(double y);
    void setLifeTime(double life_time);
    void setStartAngle(double start_angle);
    void setVelocity(double start_velocity);
    double getVelocity() const;
    double getX() const;
    double getY() const;
    double getLifeTime() const;
    void Update();
private:
    double m_x, m_y;
    double m_rx, m_ry;
    double m_velocity;
    double m_life_time;
};

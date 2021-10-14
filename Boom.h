#pragma once
#include <cmath>
class Boom {
public:
    Boom();
    void setStartX(double start_x);
    void setStartY(double start_y);
    void setStartAngle(double start_angle);
    void setVelocity(double start_velocity);
    void setLifeTime(double life_time);
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




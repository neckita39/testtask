#pragma once
#include <math.h>
class SpaceShip
{
public:
    SpaceShip() {}
    SpaceShip(float start_x, float start_y)
    {
        m_x = start_x;
        m_y = start_y;
    }
    void setStartX(float start_x) { m_x = start_x; }
    void setStartY(float start_y) { m_y = start_y; }
    void setWindowWidth(int width) { m_window_width = width; }
    void setWindowHeight(int height) { m_window_height = height; }
    float getX(){return m_x;}
    float getY(){return m_y;}


private:
    float m_x, m_y, m_r;
    float m_angle;
    int m_window_width;
    int m_window_height;

    float m_velocity;
};

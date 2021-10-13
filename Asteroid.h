#pragma once
#include <math.h>
#include <ctime>
#include "TimeController.h"
#include <iostream>
class Asteroid
{
public:
    Asteroid()
    {

    }

    ~Asteroid()
    {

    }

    void setStartX(float start_x) { m_x = start_x; }
    void setStartY(float start_y) { m_y = start_y; }
    void setStartAngle(float start_angle)
    {
        m_rx = sinf(start_angle);
        m_ry = cosf(start_angle);
    }
    double getRx(){return m_rx;}
    double getRy(){return m_ry;}
    double getTg(){return m_rx/m_ry;}
    void setWindowWidth(int width) { m_window_width = width; }
    void setWindowHeight(int height) { m_window_height = height; }
    void setVelocity(float start_velocity) { m_velocity = start_velocity; }
    float getVelocity(){return m_velocity;}
    float getX() { return m_x; }
    float getY() { return m_y; }
    double getLifeTime(){return m_life_time;}
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    void setLifeTime(double life_time){m_life_time=life_time;}
    TimeController tc;
    void Update()
    {
        // ќсуществл€ем перемещение астероида
       // if (tc.currentTimeFromStart()<getLifeTime()) {
            m_x += m_rx * m_velocity;
            m_y += m_ry * m_velocity;
       // }
       // else{

      //  }
        //Жизненный цикл снаряда


    }

private:
    float m_x, m_y, m_r;
    float m_rx, m_ry;
    int m_window_width;
    int m_window_height;
    float m_velocity;
    double m_life_time;
};

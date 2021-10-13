#pragma once
class Boom {
public:
    Boom()
    {
    }
    ~Boom()
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
    void setWindowWidth(int width) { m_window_width = width; }
    void setWindowHeight(int height) { m_window_height = height; }
    void setVelocity(float start_velocity) { m_velocity = start_velocity; }
    void velocityUp(float up) { m_velocity *= up; }
    double getAngle(){return m_ry;}
    float getX() { return m_x; }
    float getY() { return m_y; }
    double getLifeTime(){return m_life_time;}
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    void setLifeTime(double life_time){m_life_time=life_time;}
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




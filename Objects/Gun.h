#pragma once
class Gun{
public:
    Gun();
    Gun(double start_x, double start_y);
    void setStartX(double start_x);
    void setStartY(double start_y);
    double getX() const;
    double getY() const;
private:
    double m_x, m_y, m_r;
    double m_angle;
    double m_velocity;
};

#include "Missile.h"
Missile::Missile() {}
void Missile::setStartY(double start_y)  { m_y = start_y; }
void Missile::setStartX(double start_x)  { m_x = start_x; }
double Missile::getY()  const{ return m_y; }
double Missile::getX()  const{ return m_x; }
double Missile::getLifeTime() const{return m_life_time;}
double Missile::getVelocity() const{return m_velocity;}
void Missile::setVelocity(double start_velocity) { m_velocity = start_velocity; }
void Missile::setStartAngle(double start_angle){
    m_rx = sin(start_angle);
    m_ry = cos(start_angle);
}
void Missile::setX(double x)  { m_x = x; }
void Missile::setY(double y)  { m_y = y; }
void Missile::Update(){
    m_x -= m_rx*m_rx * m_velocity/(m_ry*m_ry);
    m_y += m_rx*m_velocity/m_ry;
}
void Missile::setLifeTime(double life_time) {m_life_time=life_time;}
//
// Created by Никита Щербо on 13.10.2021.
//

#include "Boom.h"
void Boom::Update(){
    m_x -= m_rx*m_rx * m_velocity/(m_ry*m_ry);//тут скорость менять !!!!!!!!!!!!!
    m_y += m_rx*m_velocity/m_ry;
}
void Boom::setStartAngle(double start_angle){
    m_rx = sin(start_angle);
    m_ry = cos(start_angle);
}
void Boom::setVelocity(double start_velocity) { m_velocity = start_velocity; }
double Boom::getLifeTime() const{return m_life_time;}
double Boom::getX()  const{ return m_x; }
double Boom::getY()  const{ return m_y; }
void Boom::setStartX(double start_x)  { m_x = start_x; }
void Boom::setStartY(double start_y)  { m_y = start_y; }
void Boom::setLifeTime(double life_time) {m_life_time=life_time;}
Boom::Boom() {}
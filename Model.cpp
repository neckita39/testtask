//
// Created by Никита Щербо on 13.10.2021.
//
#include "Boom.h"
#include "Model.h"
Model::Model(int width, int height, int missiles_count, int booms_multi) {
    m_width = width;
    m_height = height;
    m_gameOver = false;
    m_gun.setStartX(350);
    m_gun.setStartY(410);
    m_missiles_list.clear();
    m_missiles_count=missiles_count;
    m_booms_multi=booms_multi;
    Distribution distribution;
    for (int i = 0; i < m_missiles_count; i++){
        Missile a;
        a.setStartX(330);
        a.setStartY(390);
        a.setStartAngle(distribution.missileAngle());
        a.setVelocity(distribution.missileSpeed());
        a.setLifeTime(distribution.missileLifeTime());
       // std::cout<<a.getLifeTime()<<std::endl;
        m_missiles_list.push_back(a);
    }
    for(int i=0; i<m_missiles_count*m_booms_multi; ++i){
        Boom b;
        b.setStartAngle(distribution.boomAngle());
        b.setVelocity(m_missiles_list[i /booms_multi ].getLifeTime());
        b.setLifeTime(m_missiles_list[i/booms_multi].getLifeTime()/2);
        m_booms_list.push_back(b);
    }
}
void Model::Update() {
    if (!m_gameOver){

        for (auto& it: m_missiles_list) {
            it.Update();
        }
        for (int i=0; i<m_booms_list.size(); ++i) {
            m_booms_list[i].setStartX(m_missiles_list[i / m_booms_multi].getX());
            m_booms_list[i].setStartY(m_missiles_list[i / m_booms_multi].getY());
            m_booms_list[i].setVelocity(m_missiles_list[i/m_booms_multi].getLifeTime());
            m_booms_list[i].setLifeTime(m_missiles_list[i/m_booms_multi].getLifeTime()/2.0);
        }
        for (auto& it: m_booms_list){
            it.Update();
        }
        m_gameOver = false;
    }
    NotifyUpdate();
}
std::vector<Boom> Model::getBoomsList() const{return m_booms_list;}
int Model::getHeight() const{ return m_height; }
int Model::getWidth() const{ return m_width; }
std::vector<Missile> Model::getMissilesList() const{return m_missiles_list;}
bool Model::getGameOver()  const{ return m_gameOver; }
Gun Model::getGun()  const{ return m_gun; }
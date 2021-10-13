#pragma once
#include "Observer.h"
#include "SpaceShip.h"
#include "Asteroid.h"
#include <time.h>
#include <iostream>
#include <random>
#include "Boom.h"
class Model : public Observable
{
public:
    Model(int width, int height)
    {
        m_width = width;
        m_height = height;
        m_gameOver = false;
        // —оздание корабл€
        m_space_ship.setStartX(350);
        m_space_ship.setStartY(410);
        m_space_ship.setWindowWidth(m_width);
        m_space_ship.setWindowHeight(m_height);

        // —оздание астероидов
        std::mt19937 ran;
        std::uniform_real_distribution<> dis_for_speed(0.01, 0.03);
        std::uniform_real_distribution<> dis_for_angle(M_PI/2.0, 3.0*M_PI/2.0);
        std::uniform_real_distribution<> dis_for_angle_boom(0, M_PI);

        std::uniform_real_distribution<> dis_for_life_time(1.0, 3.0);

        m_asteroid_list.clear();
        int missiles_count=7;
        Asteroid a;
        for (int i = 0; i < missiles_count; i++)		// регулировать количество астероидов
        {
            a.setStartX(330);
            a.setStartY(390);
            double m=dis_for_angle(ran);
            a.setStartAngle(m);
            a.setWindowWidth(m_width);
            a.setWindowHeight(m_height);
            a.setVelocity(dis_for_speed(ran));
            a.setLifeTime(dis_for_life_time(ran));
            m_asteroid_list.push_back(a);
        }
        for(int i=0; i<missiles_count*10; ++i){
            Boom b;
            b.setWindowHeight(m_height);
            b.setWindowWidth(m_width);
            double m=dis_for_angle_boom(ran);;
            b.setStartAngle(m);
            b.setVelocity(m_asteroid_list[i/3].getLifeTime()*dis_for_speed(ran));
            b.setLifeTime(m_asteroid_list[i/3].getLifeTime()/2.0);
            b.setLifeTime(dis_for_life_time(ran));
            m_booms_list.push_back(b);
        }
    }
    ~Model()
    {
    }

    void Update()
    {

        // ѕересчет всей логики игры
        if (!m_gameOver)
        {
            // ѕозици€ корабл€

            // ѕозиции астероидов
            for (int i = 0; i < m_asteroid_list.size(); i++) {
                m_asteroid_list[i].Update();

            }
            std::mt19937 ran;
            std::uniform_real_distribution<> dis_for_life_time(1.0, 3.0);
            for (int i=0; i<m_booms_list.size(); ++i){
                m_booms_list[i].setStartX(m_asteroid_list[i/3].getX());
                m_booms_list[i].setStartY(m_asteroid_list[i/3].getY());
                m_booms_list[i].Update();
            }


            // ѕроверка соударени€
            m_gameOver = false;
        }

        // ѕодача сигнала классу View
        NotifyUpdate();
    }
    SpaceShip* getSpaceShip() { return &m_space_ship; }
    std::vector<Asteroid>* getAsteroidsList()
    {
        return &m_asteroid_list;
    }
    std::vector<Boom>* getBoomsList()
    {
        return &m_booms_list;
    }
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    bool getGameOver() { return m_gameOver; }
    float getScore() { return m_score; }

private:
    SpaceShip m_space_ship;
    std::vector<Asteroid> m_asteroid_list;
    std::vector<Boom> m_booms_list;
    int m_width;
    int m_height;

    bool m_gameOver;
    float m_score;
};

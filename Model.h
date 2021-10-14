#pragma once
#include "Observer.h"
#include "Gun.h"
#include "Missile.h"
#include <ctime>
#include <iostream>
#include <random>
#include "Boom.h"
#include "Distribution.h"
#include "Observable.h"
class Model : public Observable
{
public:
    Model(int width, int height, int missiles_count=5, int booms_multi=2);
    void Update();
    Gun getGun() const;
    std::vector<Missile> getMissilesList() const;
    std::vector<Boom> getBoomsList() const;
    int getWidth() const;
    int getHeight() const;
    bool getGameOver() const;

private:
    Gun m_gun;
    std::vector<Missile> m_missiles_list;
    std::vector<Boom> m_booms_list;
    int m_width;
    int m_height;
    bool m_gameOver;
    int m_booms_multi;
    int m_missiles_count;
};

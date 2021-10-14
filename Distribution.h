#pragma once
#include <random>
class Distribution {
public:
    Distribution();
    double missileSpeed();
    double missileAngle();
    double boomAngle();
    double missileLifeTime();
private:
    std::mt19937 m_ran;
};



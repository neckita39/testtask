#include "Distribution.h"
Distribution::Distribution() {}
double Distribution::boomAngle() {
    std::uniform_real_distribution<> dis_for_angle_boom(0, M_PI);
    return dis_for_angle_boom(m_ran);
}
double Distribution::missileLifeTime() {
    std::uniform_real_distribution<> dis_for_life_time(1.0, 1.0);
    return dis_for_life_time(m_ran);
}
double Distribution::missileSpeed() {
    std::uniform_real_distribution<> dis_for_speed(0.03, 0.05);
    return dis_for_speed(m_ran);
}
double Distribution::missileAngle() {
    std::uniform_real_distribution<> dis_for_angle(M_PI, -M_PI/4.0);
    return dis_for_angle(m_ran);
}
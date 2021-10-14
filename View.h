#pragma once
#include "Observer.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TimeController.h"
#include "Boom.h"
#include "Observable.h"
#include "Model.h"
class View : public Observer
{
public:
    explicit View(Model& model);
    ~View();

    void initBackground();
    void initGun();

    void initMissiles();

    void initBooms();

    void setMissilesParams();
    //УКАЗАТЕЛИ + ВРЕМЯ
    void setMiniMissilesParams();

    void setBoomParams();

    void Update();
private:
    Model* m_model;
    sf::RenderWindow* m_window;
    sf::Sprite m_sprite_back;
    sf::Texture m_back_texture;
    sf::Sprite m_sprite_gun;
    sf::Texture m_gun_texture;
    std::vector<sf::Sprite> m_spriteMissiles;
    sf::Texture m_missile_texture;
    std::vector<sf::Sprite> m_spriteBooms;
    sf::Texture m_boom_texture;
};
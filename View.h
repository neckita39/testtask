#pragma once
#include "Observer.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TimeController.h"
#include "Boom.h"
class View : public Observer
{
public:
    View(Model& model)
    {
        // ѕолучили ссылку на модель
        m_model = &model;
        m_model->AddObserver(this);

        // —оздание окна
        InitBackground();

        // —оздание космического корабл€
        InitSpaceShip();

        // »нициализаци€ астероидов
        InitAsteroids();

        InitBoom();
    }
    ~View()
    {
        delete m_window;
    }

    void InitBackground()
    {
        if (!m_back_texture.loadFromFile("/Users/Nikita/CLionProjects/test/back.png"))
        {
            std::cout << "ERROR: Could not find background image." << std::endl;
        }

        m_window = new sf::RenderWindow(sf::VideoMode(m_model->getWidth(), m_model->getHeight()), "Space game");
        m_sprite_back.setTexture(m_back_texture);
    }

    void InitSpaceShip()
    {
        if (!m_ship_texture.loadFromFile("/Users/Nikita/CLionProjects/test/gun.png"))
        {
            // error...
        }
        m_ship_texture.setSmooth(true);
        m_sprite_ship.setTexture(m_ship_texture);
        m_sprite_ship.setScale(0.05, 0.05);
        m_sprite_ship.setOrigin(m_ship_texture.getSize().x / 2.0, m_ship_texture.getSize().y / 2.0);
    }

    void InitAsteroids()
    {
        if (!m_asteroid_texture.loadFromFile("/Users/Nikita/CLionProjects/test/missile.png"))
        {
            // error...
        }
        m_asteroid_texture.setSmooth(true);
        SetAsteroidsParams();
    }

    void InitBoom(){
        if (!m_boom_texture.loadFromFile("/Users/Nikita/CLionProjects/test/boom.png")){
            //error...
        }
        m_boom_texture.setSmooth(true);
        SetBoomParams();
    }

    void SetAsteroidsParams() {
        TimeController tc;
        bool exploded=false;
        std::vector<Asteroid> *asteroids = m_model->getAsteroidsList();
        m_spriteAsteroids.clear();
        for (int i = 0; i < asteroids->size(); i++) {

            sf::Sprite tmp;
            tmp.setTexture(m_asteroid_texture);
            tmp.setScale(0.03, 0.03);
            tmp.setOrigin(m_asteroid_texture.getSize().x/2 , m_asteroid_texture.getSize().y/2 );
            if (tc.currentTimeFromStart() < asteroids->at(i).getLifeTime()) {
                tmp.setPosition(asteroids->at(i).getX(), asteroids->at(i).getY());
                m_spriteAsteroids.push_back(tmp);
            } else {
                SetMiniAsteroidsParams();
            }
        }
    }
    void SetMiniAsteroidsParams(){
        TimeController tc;
        bool exploded=false;
        std::vector<Asteroid> *asteroids = m_model->getAsteroidsList();
        m_spriteAsteroids.clear();
        for (int i = 0; i < asteroids->size(); i++) {

            sf::Sprite tmp;
            tmp.setTexture(m_asteroid_texture);
            tmp.setScale(0.01, 0.01);
            tmp.setOrigin(m_asteroid_texture.getSize().x/2 , m_asteroid_texture.getSize().y/2 );
            if (tc.currentTimeFromStart()-2.0 < asteroids->at(i).getLifeTime()/2) {
                tmp.setPosition(asteroids->at(i).getX(), asteroids->at(i).getY());
                m_spriteAsteroids.push_back(tmp);
            } else {
                SetBoomParams();
            }
        }
    };
    void SetBoomParams(){
        TimeController tc;
        std::vector<Boom>* booms=m_model->getBoomsList();
        m_spriteBooms.clear();
        for (int i=0; i<booms->size(); ++i){
            sf::Sprite tmp;
            tmp.setTexture(m_boom_texture);
            tmp.setScale(0.03, 0.03);
            tmp.setOrigin(m_boom_texture.getSize().x/2 , m_boom_texture.getSize().y/2 );
            if (tc.currentTimeFromStart()-3 < booms->at(i).getLifeTime()/2) {
                tmp.move(booms->at(i).getX(), booms->at(i).getY());
                m_spriteBooms.push_back(tmp);
            }
        }
    }


    void Update()
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }

        // ќчистка экрана
        m_window->clear();

        if (!m_model->getGameOver())
        {
            // ќбновление позиции корабл€
            m_sprite_ship.setPosition(m_model->getSpaceShip()->getX(), m_model->getSpaceShip()->getY());


            // ќбновление позиции астероидов
            SetAsteroidsParams();
            //SetBoomParams();

            m_window->draw(m_sprite_back);
            m_window->draw(m_sprite_ship);
            for (int i = 0; i < m_spriteAsteroids.size(); i++) {
                m_window->draw(m_spriteAsteroids[i]);
            }
            for (int i = 0; i < m_spriteBooms.size(); i++)
                m_window->draw(m_spriteBooms[i]);
        }


        // ќтображение буфера на экране
        m_window->display();
    }
private:
    Model* m_model;

    sf::RenderWindow* m_window;

    sf::Sprite m_sprite_back;
    sf::Texture m_back_texture;

    sf::Sprite m_sprite_ship;
    sf::Texture m_ship_texture;

    std::vector<sf::Sprite> m_spriteAsteroids;
    sf::Texture m_asteroid_texture;

    std::vector<sf::Sprite> m_spriteBooms;
    sf::Texture m_boom_texture;
};
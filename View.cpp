
#include "View.h"
#include <thread>
void View::Update()
{
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        //setMissilesParams();
        if (event.type == sf::Event::Closed)
            m_window->close();
    }
    m_window->clear();
    if (!m_model->getGameOver())
    {
        setMissilesParams();
        m_window->draw(m_sprite_back);
        m_window->draw(m_sprite_gun);
        for (int i = 0; i < m_spriteMissiles.size(); i++) {
            m_window->draw(m_spriteMissiles[i]);
        }
        for (int i = 0; i < m_spriteBooms.size(); i++)
            m_window->draw(m_spriteBooms[i]);
    }
    m_window->display();
}

void View::setMissilesParams()  {
    TimeController tc;
    std::vector<Missile> missiles = m_model->getMissilesList();
    m_spriteMissiles.clear();

    for (int i=0; i<missiles.size(); ++i) {
        sf::Sprite tmp;
        tmp.setTexture(m_missile_texture);
        tmp.setScale(0.03, 0.03);
        tmp.setOrigin(m_missile_texture.getSize().x / 2 , m_missile_texture.getSize().y / 2 );
        if (tc.currentTimeFromStart()  < missiles[i].getLifeTime()){
                tmp.setPosition(missiles[i].getX(), missiles[i].getY());
                m_spriteMissiles.push_back(tmp);
        }
        else {
            setMiniMissilesParams();

        }
    }
}
void View::initMissiles() {
    if (!m_missile_texture.loadFromFile("../res/missile.png")){
        std::cout << "ERROR: Could not find missile image." << std::endl;
    }
    m_missile_texture.setSmooth(true);
    setMissilesParams();
}
void View::initBackground() {
    if (!m_back_texture.loadFromFile("../res/back.png")){
        std::cout << "ERROR: Could not find background image." << std::endl;
    }
    m_window = new sf::RenderWindow(sf::VideoMode(m_model->getWidth(), m_model->getHeight()), "Test task");
    m_sprite_back.setTexture(m_back_texture);
}
void View::initBooms() {
    if (!m_boom_texture.loadFromFile("../res/boom.png")){
        std::cout << "ERROR: Could not find boom image." << std::endl;
    }
    m_boom_texture.setSmooth(true);
}
void View::initGun() {
    if (!m_gun_texture.loadFromFile("../res/gun.png")){
        std::cout << "ERROR: Could not find gun image." << std::endl;
    }
    m_gun_texture.setSmooth(true);
    m_sprite_gun.setTexture(m_gun_texture);
    m_sprite_gun.setScale(0.05, 0.05);
    m_sprite_gun.setOrigin(m_gun_texture.getSize().x / 2.0, m_gun_texture.getSize().y / 2.0);
    m_sprite_gun.setPosition(m_model->getGun().getX(), m_model->getGun().getY());
}
void View::setBoomParams() {
    TimeController tc;
    std::vector<Boom> booms = m_model->getBoomsList();
    m_spriteBooms.clear();

    for (auto &it: booms) {
        sf::Sprite tmp;
        tmp.setTexture(m_boom_texture);
        tmp.setScale(0.07, 0.07);
        tmp.setOrigin(m_boom_texture.getSize().x / 2, m_boom_texture.getSize().y / 2);
        if (tc.currentTimeFromStart() - 3 < it.getLifeTime()) {
            tmp.move(it.getX(), it.getY());
            m_spriteBooms.push_back(tmp);
        }

    }
}
void View::setMiniMissilesParams() {
    TimeController tc;
    std::vector<Missile> asteroids = m_model->getMissilesList();
    m_spriteMissiles.clear();

    for (auto &it: asteroids) {
        sf::Sprite tmp;
        tmp.setTexture(m_missile_texture);
        tmp.setScale(0.01, 0.01);
        tmp.setOrigin(m_missile_texture.getSize().x / 2, m_missile_texture.getSize().y / 2);
        if (tc.currentTimeFromStart()-2  < (it.getLifeTime()/2.0 )) {
            it.setVelocity(it.getVelocity() * 2);
            tmp.setPosition(it.getX(), it.getY());
            m_spriteMissiles.push_back(tmp);
        } else {
            setBoomParams();
        }
    }
}
View::View(Model &model){
    m_model = &model;
    m_model->AddObserver(this);
    initBackground();
    initGun();
    initMissiles();
    initBooms();
}
View::~View() {
    delete m_window;
}
#pragma once
#include <SFML/Graphics.hpp>
#include "Model.h"
#include <thread>

class Controller
{
public:
    Controller(Model& model)
    {
        m_model = &model;
    }
    ~Controller() {}

    void LifeCycle()
    {
        while (true)
        {
            // ќбновление класса модели
            m_model->Update();
        }
    }
private:
    Model* m_model;
};

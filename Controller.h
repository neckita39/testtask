#pragma once
#include <SFML/Graphics.hpp>
#include "Model.h"
#include <thread>
class Controller
{
public:
    Controller(Model& model);
    void LifeCycle();
private:
    Model* m_model;
};

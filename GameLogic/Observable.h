#pragma once
#include "Observer.h"
class Observable
{
public:
    void AddObserver(Observer* observer);
    void NotifyUpdate();
private:
    std::vector<Observer*> m_observers;
};




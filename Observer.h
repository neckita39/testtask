#pragma once
#include <vector>

class Observer
{
public:
    virtual void Update() = 0;
};

class Observable
{
public:
    void AddObserver(Observer* observer)
    {
        m_observers.push_back(observer);
    }
    void NotifyUpdate()
    {
        int size = m_observers.size();
        for (int i = 0; i < size; i++)
        {
            m_observers[i]->Update();
        }
    }
private:
    std::vector<Observer*> m_observers;
};

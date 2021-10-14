//
// Created by Никита Щербо on 14.10.2021.
//
#pragma once
#include "Observable.h"
void Observable::AddObserver(Observer *observer)  {
    m_observers.push_back(observer);
}
void Observable::NotifyUpdate()  {
    int size = m_observers.size();
    for (int i = 0; i < size; i++)
    {
        m_observers[i]->Update();
    }
}
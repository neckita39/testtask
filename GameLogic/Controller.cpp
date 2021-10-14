#include "Controller.h"
void Controller::LifeCycle(){
    while (true){
        m_model->Update();
    }
}
Controller::Controller(Model &model){
    m_model = &model;
}
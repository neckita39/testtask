//
// Created by Никита Щербо on 13.10.2021.
//

#include "TimeController.h"
TimeController::TimeController() {}
double TimeController::currentTimeFromStart() {
    clock_t start=clock();
    double res=static_cast<double>(start)/CLOCKS_PER_SEC;
    return res;
}
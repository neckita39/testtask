#pragma once
#include <ctime>
#include <iostream>
class TimeController {
public:
    TimeController(){
    }
    ~TimeController(){}
    double currentTimeFromStart(){
        clock_t start=clock();
        double res=(double)start/CLOCKS_PER_SEC;
        //std::cout<<res<<std::endl;
        return res;
    }
};




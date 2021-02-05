//
// Created by Adrian Antonio on 1/29/2021.
//

#include "StopWatch.h"


StopWatch::StopWatch():_initialTime() {
    std::cout<<"Program ";
    start();
}

void StopWatch::start() {
    _initialTime= std::chrono::system_clock::now();
    std::cout<< "Time starts " << std::endl;
}

double StopWatch::stop() {
    _endTime = std::chrono::system_clock::now();
    auto diff = _endTime-_initialTime;
    std::cout<< "Time ends @ " << std::chrono::duration<double> (diff).count() << std::endl;

    return 0;
}

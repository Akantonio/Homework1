//
// Created by Adrian Antonio on 1/29/2021.
//

#include "StopWatch.h"


StopWatch::StopWatch():_initialTime(std::chrono::system_clock::now()) {

    std::cout<<"Initial Time: "<< std::endl;
}

void StopWatch::start() {
    std::cout<< "Time starts @ " << std::endl;
}

double StopWatch::stop() {
    std::cout<< "Time ends @ " << std::endl;

    return 0;
}

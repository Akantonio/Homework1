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

void StopWatch::stop() {
    _endTime = std::chrono::system_clock::now();
    readTime();
}

double StopWatch::readTime(StopWatch::DurationFormat) {
    double duration=0;
    auto diff = _endTime-_initialTime;
    switch (StopWatch::DurationFormat) {
        case SECONDS:
            std::cout<< "Time ends @ " << std::chrono::duration<double> (diff).count() << " seconds."<< std::endl;
            duration= std::chrono::duration<double> (diff).count();
            break;
        case MILLISECONDS:
            std::cout<< "Time ends @ " << std::chrono::duration<double> (diff).count() << " seconds."<< std::endl;
            duration= std::chrono::duration<double,std::milli> (diff).count();
            break;
        default:
            break;
    }
    return duration;
}

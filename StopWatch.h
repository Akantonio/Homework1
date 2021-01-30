//
// Created by Adrian Antonio on 1/29/2021.
//

#ifndef HOMEWORK1_STOPWATCH_H
#define HOMEWORK1_STOPWATCH_H

#include <chrono>
#include <ctime>

class StopWatch {
public:
    StopWatch();
    void start();
    double stop();

private:
    std::chrono::steady_clock::time_point _initialTime;
    double _startTime;
    double _endTime;
};


#endif //HOMEWORK1_STOPWATCH_H

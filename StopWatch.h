//
// Created by Adrian Antonio on 1/29/2021.
//

#ifndef HOMEWORK1_STOPWATCH_H
#define HOMEWORK1_STOPWATCH_H

#include <iostream>
#include <chrono>
#include <ctime>


class StopWatch {
public:
    StopWatch();
    void start();
    void stop();
    double readTime(int type);

private:
    std::chrono::time_point<std::chrono::system_clock> _initialTime;
    std::chrono::time_point<std::chrono::system_clock> _endTime;
};


#endif //HOMEWORK1_STOPWATCH_H

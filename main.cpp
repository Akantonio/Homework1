
#include "StopWatch.h"
#include <random>
#include <vector>
#include <algorithm>

void testIng(){
    for(int i=0; i<1000; ++i){
        std::cout<< i << std::endl;
    }
}

void randomT(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    for (int n=0; n<10; ++n)

        std::cout << dis(gen) << ' ';
    std::cout << '\n';
}

void search(int amount){
    std::cout<<"Sequential search of 2 vectors" << amount <<std::endl;
    std::vector<int> randomVector1{};
    randomVector1.reserve(10);

}

int main() {
    StopWatch theClock;
    theClock.start();
    testIng();
    theClock.stop();
    theClock.readTime(0);
    theClock.readTime(1);


    return 0;
}

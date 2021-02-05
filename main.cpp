
#include "StopWatch.h"
#include <random>

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

}

int main() {
    StopWatch theClock;
    theClock.start();
    testIng();
    theClock.stop();
    theClock.readTime(0);
    theClock.readTime(1);

    theClock.start();
    randomT();

    return 0;
}

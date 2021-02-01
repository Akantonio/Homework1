#include <iostream>
#include "StopWatch.h"

void testIng(){
    for(int i=0; i<1000; ++i){
        std::cout<< i << std::endl;
    }
}

int main() {
    StopWatch theClock;
    theClock.start();
    testIng();
    theClock.stop();

    return 0;
}

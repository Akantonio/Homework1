
#include "StopWatch.h"
#include <random>
#include <vector>
#include <algorithm>
#include <fstream>

void testIng(){
    for(int i=0; i<1000; ++i){
        std::cout<< i << std::endl;
    }
}

int randomInt(int minimum,int maximum){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minimum, maximum);

    return dis(gen);
}

void search(int amount){
    std::cout<<"Sequential search of 2 vectors " << amount <<std::endl;
    std::vector<int> randomVector1;
    randomVector1.reserve(10);

}

int main() {
    StopWatch theClock;

    theClock.start();
    testIng();
    theClock.stop();
    theClock.readTime(0);
    theClock.readTime(1);

    search(4);

    //Gutenberg Book
    std::fstream fInput;
    fInput.open("../174.txt");
    if(!fInput){
        std::cout<<"Could not read File!" << std::endl;
    }
    return 0;
}


#include "StopWatch.h"
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>



int randomInt(int minimum,int maximum){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minimum, maximum);

    return dis(gen);
}



int main() {
    //Time It I
    StopWatch theClock;

    std::vector<int> randomVector;
    randomVector.reserve(10);
    for(auto & i:randomVector){
        i.push_back(randomInt(1,10));
    }



    //Gutenberg Book
    std::string bookLine;
    std::fstream fInput;
    fInput.open("../174.txt");
    if(!fInput){
        std::cout<<"Could not read File!" << std::endl;
    }
    theClock.start();
    while(std::getline(fInput,bookLine)){
        std::cout << bookLine <<std::endl;
    }
    theClock.stop();
    theClock.readTime(0);

    return 0;
}

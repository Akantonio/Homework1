
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

void search(std::vector<int> & data){
    std::vector<int> parameter{3,4,5,6}; //search parameters
    std::vector<int>::iterator intPoint;

    intPoint= std::search(data.begin(), data.end(), parameter.begin(), parameter.end());
    if(intPoint != data.end()){
        std::cout<<"Parameter is in the Data "<<(intPoint - data.begin())<<"\n";
    }else{
        std::cout<<" Parameter is not present in Data\n";
    }
}

int main() {
    //Time It I
    StopWatch theClock;

    std::vector<int> randomVector;
    randomVector.reserve(10);
    for(int i=0;i<10;++i){
        randomVector.push_back(randomInt(1,10));
    }

    theClock.start();
    search(randomVector);
    theClock.stop();
    theClock.readTime(1);

    //Gutenberg
    std::string bookLine;
    std::fstream fInput;
    fInput.open("../174.txt");
    if(!fInput){
        std::cout<<"Could not read File!" << std::endl;
    }
    theClock.start();
    while(std::getline(fInput,bookLine)){
        //std::cout << bookLine <<std::endl;
    }
    theClock.stop();
    theClock.readTime(0);

    return 0;
}

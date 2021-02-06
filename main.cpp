
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

void search(std::vector<int> & data,StopWatch & clockT){
    std::vector<int> parameter{3,4,5}; //search parameters
    std::vector<int>::iterator intPoint;
    clockT.start();
    intPoint= std::search(data.begin(), data.end(), parameter.begin(), parameter.end());
    clockT.stop();
    clockT.readTime(1);
    if(intPoint != data.end()){
        std::cout<<"Parameter is in the Data "<<(intPoint - data.begin())<<"\n";
    }else{
        std::cout<<"Parameter is not present in Data\n";
    }
}

void binarySearch(std::vector<int> & data,StopWatch & clockT){
    clockT.start();
    if(std::binary_search(data.begin(),data.end(),3)){
        clockT.stop();
        clockT.readTime(1);
        std::cout<<"Found a 3! \n";
    } else{
        clockT.stop();
        clockT.readTime(1);
        std::cout<<"Did not Find a 3!\n";
    }
}

void timingVectors(int capacity,StopWatch & clockT){
    std::vector<int> randomVector;
    randomVector.reserve(capacity);
    for(int i=0; i < capacity; ++i){
        randomVector.push_back(randomInt(1,10));
    }

    //using std::search
    std::cout<<"-Search-"<<std::endl;
    search(randomVector,clockT);

    //using std::binary_search
    std::cout<<"-Binary Search-"<<std::endl;
    binarySearch(randomVector,clockT);
}

void gutenberg(std::string fileName,StopWatch clockW){
    std::string bookLine;
    std::fstream fInput;
    fInput.open(("../"+fileName));
    if(!fInput){
        std::cout<<"Could not read File!" << std::endl;
    }
    std::cout<< fileName <<std::endl;
    std::cout<<" -String- "<<std::endl;
    clockW.start();
    while(std::getline(fInput,bookLine)){
        //std::cout << bookLine <<std::endl;
    }
    clockW.stop();
    clockW.readTime(1);

    std::cout<<" -Vector- "<<std::endl;
    std::vector<std::string> bookCase;
    clockW.start();
    while(std::getline(fInput,bookLine)){
        bookCase.push_back(bookLine);
    }
    clockW.stop();
    clockW.readTime(1);
}

int main() {
    //Time It I
    StopWatch theClock;

    std::cout<<"Vector with 100 inside" <<std::endl;
    timingVectors(100,theClock);
    std::cout<<"Vector with 1000 inside" <<std::endl;
    timingVectors(1000,theClock);
    std::cout<<"Vector with 10000 inside" <<std::endl;
    timingVectors(10000,theClock);
    std::cout<<"Vector with 100000 inside" <<std::endl;
    timingVectors(100000,theClock);
    std::cout<<"Vector with 1000000 inside" <<std::endl;
    timingVectors(1000000,theClock);
    std::cout<<"Vector with 10000000 inside" <<std::endl;
    timingVectors(10000000,theClock);

    //Time It II  -- Gutenberg
    gutenberg("174.txt",theClock);
    gutenberg("219-0.txt",theClock);
    gutenberg("1080-0.txt",theClock);
    gutenberg("pg3207.txt",theClock);
    gutenberg("pg22668.txt",theClock);

    return 0;
}

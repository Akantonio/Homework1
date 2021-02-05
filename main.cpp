
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
        std::cout<<"Found a 3! \n";
    } else{
        clockT.stop();
        std::cout<<"Did not Find a 3!\n";
    }
}

int main() {
    //Time It I
    StopWatch theClock;

    int capacity=100;
    std::vector<int> randomVector;
    randomVector.reserve(capacity);
    for(int i=0; i < capacity; ++i){
        randomVector.push_back(randomInt(1,10));
    }

    //using std::search
    std::cout<<"-Search-"<<std::endl;

    search(randomVector,theClock);


    //using std::binary_search
    std::cout<<"-Binary Search-"<<std::endl;

    binarySearch(randomVector,theClock);


    //Gutenberg
    std::string bookLine;
    std::fstream fInput;
    fInput.open("../174.txt");
    if(!fInput){
        std::cout<<"Could not read File!" << std::endl;
    }
    std::cout<<" -String- "<<std::endl;
    theClock.start();
    while(std::getline(fInput,bookLine)){
        std::cout << bookLine <<std::endl;
    }
    theClock.stop();
    theClock.readTime(1);


    return 0;
}

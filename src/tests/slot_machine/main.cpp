
#include<iostream>
#include<vector>
#include "../../include/tester.h"
#include "reel_tests.hpp"
#include "machine_tests.hpp"
#include "paystrategy_tests.hpp"

using namespace std;

void runTests(vector<Tester*> &tests){

    for(auto *test: tests){
        test->run();
    }
}

int main(){

    vector<Tester*> tests;

    ReelTests reelTests;
    tests.push_back(&reelTests);

    MachineTests machineTests;
    tests.push_back(&machineTests);

    PayStrategyTests payStrategyTests;
    tests.push_back(&payStrategyTests);

    runTests(tests);
    
    return 0;
}

#include<iostream>
#include<vector>
#include "../../include/tester.hpp"
#include "reel_tests.hpp"
#include "machine_tests.hpp"
#include "paystrategy_tests.hpp"
#include "purse_tests.hpp"
#include "machine_interface_tests.hpp"

using namespace std;

void runTests(vector<Tester*> &tests){

    int totalTestsPassed = 0;
    int totalTestsFailed = 0;
    for(auto *test: tests){
        test->run();
        //These can only be run after run
        totalTestsFailed += test->getTestsFailedCount();
        totalTestsPassed += test->getTestsPassedCount();
    }

    cout << "Total tests run:    " << totalTestsFailed + totalTestsPassed << endl;
    cout << "Total tests passed: " << totalTestsPassed << endl;
    cout << "Total tests failed: " << totalTestsFailed << endl;
}

int main(){

    vector<Tester*> tests;

    ReelTests reelTests;
    tests.push_back(&reelTests);

    MachineTests machineTests;
    tests.push_back(&machineTests);

    PayStrategyTests payStrategyTests;
    tests.push_back(&payStrategyTests);

    PurseTests purseTests;
    tests.push_back(&purseTests);

    MachineInterfaceTests machineInterfaceTests;
    tests.push_back(&machineInterfaceTests);

    runTests(tests);
    
    return 0;
}
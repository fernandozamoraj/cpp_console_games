
#include<iostream>
#include<vector>
#include "../../include/tester.h"
#include "reel_tests.hpp"

using namespace std;

void runTests(vector<Tester*> &tests){

    for(auto *test: tests){
        test->run();
    }
}

int main(){

    vector<Tester*> tests;

    ReelTests realTests;
    tests.push_back(&realTests);

    runTests(tests);
    
    return 0;
}
/*
   Tester: this is a helper class to test my code
   Why Tester and not something else like Catch or Google Test:
   Those frameworks are way too bloated.
   This keeps it simple and it's provides faster testing (faster compile)


*/
#ifndef TESTER_H
#define TESTER_H

#include<string>
#include<iostream>
#include<vector>
#include<sstream>



using namespace std;

template <typename T>
void _assertEqual(T expected, T actual, string testName, string category, vector<string> &passedCollection, vector<string> &failedCollection){
        if(expected == actual){
            stringstream ss;
            ss << category << ":" << testName << " Test Passed";
            passedCollection.push_back(ss.str());
        }
        else{
            stringstream ss;
            ss << category << ":" << testName << " Test Failed: expected \"" << expected << "\" but was \"" << actual << "\"";
            failedCollection.push_back(ss.str());
        }
}

void _assertTrue(bool condition, string testName, string category, vector<string> &passedCollection, vector<string> &failedCollection){
        if(condition){
            stringstream ss;
            ss << category << ":" << testName << " Test Passed";
            passedCollection.push_back(ss.str());
        }
        else{
            stringstream ss;
            ss << category << ":" << testName << " Test Failed expected " << condition << " but was " << !condition;
            failedCollection.push_back(ss.str());
        }
}

class Tester{

private:
    string category;
    vector<string> passedTests;
    vector<string> failedTests;

public:
    void setCategory(string category){
        this->category = category;
    }

    void assert_equal(int expected, int actual, string testName){
        _assertEqual(expected, actual, testName, category, passedTests, failedTests);
    }

    void assert_equal(float expected, float actual, string testName){
        _assertEqual(expected, actual, testName, category, passedTests, failedTests);
    }

    void assert_equal(string expected, string actual, string testName){
        _assertEqual(expected, actual, testName, category, passedTests, failedTests);
    }

    void assert_true(bool condition, string testName){
        _assertTrue(condition, testName, category, passedTests, failedTests);
    }

    string getResults(){
        stringstream ss;

        ss << passedTests.size() << " Tests passed" << endl;
        ss << failedTests.size() << " Tests failed" << endl;
        ss << "--------------------------------------------" << endl;

        for(auto test: failedTests){
            ss << test << endl;
        }

        return ss.str();
    }

    virtual void run(){};

};

#endif
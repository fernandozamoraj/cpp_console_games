#ifndef SLOTMACHINE_SPINDATA_H
#define SLOTMACHINE_SPINDATA_H
#include <string>

using namespace std;

struct SpinData{

public:
    SpinData(){}
    SpinData(const SpinData &other){
        for(int i=0;i<3;i++){
            row1[i] = other.row1[i];
            row2[i] = other.row2[i];
            row2[i] = other.row2[i];            
        }
    }

    SpinData operator=(const SpinData &other){
        for(int i=0;i<3;i++){
            row1[i] = other.row1[i];
            row2[i] = other.row2[i];
            row2[i] = other.row2[i];            
        }

        return *this;
    }

    string row1[3];
    string row2[3];
    string row3[3];
};



#endif
#ifndef SLOTMACHINE_MACHINE_H
#define SLOTMACHINE_MACHINE_H
#include <string>
#include "reel.h"
#include "spinData.hpp"

using namespace std;

class Machine{

private:
    vector<Reel*> reels;
public:
    Machine();
    ~Machine();
    string getReel(int reel, int index) const;
    SpinData spin();
};

#endif // !SLOTMACHINE_CMAHINE_H

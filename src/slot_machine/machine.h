#ifndef SLOTMACHINE_MACHINE_H
#define SLOTMACHINE_MACHINE_H
#include <string>
#include "Reel.h"

using namespace std;

class Machine{

private:
    vector<Reel*> reels;
public:
    Machine();
    ~Machine();
    string getReel(int reel, int index) const;
    void spin();
};

#endif // !SLOTMACHINE_CMAHINE_H

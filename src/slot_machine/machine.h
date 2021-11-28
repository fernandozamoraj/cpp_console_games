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

    //spin returns SpinData which consists of three rows of data
    //that is representative of the entire screen
    //The entire screen is necessary for whild symbols that may appear
    //anywhere on the scree... e.g. a 2x or 3 symbol combined with a winning
    //payline
    //e.g.
    //     &   @  2x
    //     *   *  *
    //     ^   0  #
    // In the example above the middle row is a winner mulitplied by the 2x  
    SpinData spin();
};

#endif // !SLOTMACHINE_CMAHINE_H

#include "machine.h"

Machine::Machine(){
   
   Reel *reel1 = new Reel("7, ,@, ,n,@, ,@,#,$, ,^,&, ,*, ,0, ,2x, ,3x, ");
   Reel *reel2 = new Reel("@, ,3x, ,$, , ,^, ,@,&, ,2x,*,#, 1x, ,0, 7, n");
   Reel *reel3 = new Reel("@, ,@, ,$,n, ,#, ,^,2x, ,3x, ,0,7, ,&, , *, n");

   reels.push_back(reel1);
   reels.push_back(reel2);
   reels.push_back(reel3);
}

Machine::~Machine(){

    Reel* reel1 = reels[0];
    Reel* reel2 = reels[1];
    Reel* reel3 = reels[2];

    reels.clear();
    delete reel1;
    delete reel2;
    delete reel3;
}

string Machine::getReel(int reelIndex, int index) const{
    Reel*reel =  reels[reelIndex];
    return (*reel)[index];
}

void Machine::spin(){
    reels[0]->spin();
    reels[1]->spin();
    reels[2]->spin();
}
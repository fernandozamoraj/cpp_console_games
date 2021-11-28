#include "machine.h"

Machine::Machine(){
   
   Reel *reel1 = new Reel("7, ,@, ,n,@, ,$,#, , ,^,&, ,*, ,0, ,2x, ,3x,$");
   Reel *reel2 = new Reel("@,7,3x, ,$, ,0,^, ,*,&, ,2x,*,#,*, ,0,7,n,*,#");
   Reel *reel3 = new Reel("@, ,@, ,$,n, ,#, ,^,2x, ,3x, ,0,7, ,&, ,*,n,^");

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

SpinData Machine::spin(){
    reels[0]->spin();
    reels[1]->spin();
    reels[2]->spin();

    SpinData data;
    data.row1[0] = (*reels[0])[0];
    data.row1[1] = (*reels[1])[0];
    data.row1[2] = (*reels[2])[0];

    data.row2[0] = (*reels[0])[1];
    data.row2[1] = (*reels[1])[1];
    data.row2[2] = (*reels[2])[1];

    data.row3[0] = (*reels[0])[2];
    data.row3[1] = (*reels[1])[2];
    data.row3[2] = (*reels[2])[2];
    
    return data;
}
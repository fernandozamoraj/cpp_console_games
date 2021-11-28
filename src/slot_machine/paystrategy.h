#ifndef SLOTMACHINE_PAYSTRATEGY_H
#define SLOTMACHINE_PAYSTRATEGY_H

#include <vector>
#include <map>
#include <string>

using namespace std;

class PayStrategy{
private:
    map<string, double> payMappings;
public:
   /*   
     @ = .25
     # = .5
     n = 1
     ^ = 1.5
     0 = 4
     2x = wild pays twich the pay
     3x = wild pays 3 times
     *  = 5
     *  = wild
     $  = 20
     2x = 3 2x pays $ times 8 or 
     3x = pays jackpot 100 times 81  
     7, ,@, ,n,@, ,@,#,$, ,^,&, ,*, ,0, ,2x, ,3x, 
    */ 
    PayStrategy();
    double payOut(string firstSymbol, string secondSymbol, string thirdSymbol) const;
    vector<string> getPayTables() const;
};

#endif

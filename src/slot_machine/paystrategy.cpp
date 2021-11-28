#include "paystrategy.h"

bool allThreeSymbolsAreTheSame(string symbol1, string symbol2, string symbol3){
    return symbol1 == symbol2 && symbol2 == symbol3;
}

bool containsMultiplier(string symbol1, string symbol2, string symbol3){
    if(symbol1 == "2x" || symbol2 == "2x" || symbol3 == "2x"){
        return true;
    }

    if(symbol1 == "3x" || symbol2 == "3x" || symbol3 == "3x"){
        return true;
    }

    return false;
}

double getMultiplierValue(string symbol1, string symbol2, string symbol3){
    double multiplier = 1;
    if(symbol1 == "2x"){
        multiplier *= 2;
    }
    else if(symbol1 == "3x"){
        multiplier *= 3;
    }

   if(symbol2 == "2x"){
        multiplier *= 2;
    }
    else if(symbol2 == "3x"){
        multiplier *= 3;
    }

    if(symbol3 == "2x"){
        multiplier *= 2;
    }
    else if(symbol3 == "3x"){
        multiplier *= 3;
    }

    return multiplier;
}

bool isMultiplier(string symbol){
    return (symbol == "2x" || symbol == "3x");
}

double getPayout(string symbol1, string symbol2, string symbol3, map<string,double> paylines){
    if(allThreeSymbolsAreTheSame(symbol1, symbol2, symbol3)){
        return paylines[symbol1];
    }

    if(containsMultiplier(symbol1, symbol2, symbol3)){
        double multiplier = getMultiplierValue(symbol1, symbol2, symbol3);
        
        //When a multiplier is > 3 means there are two multipliers in te symbols
        if(multiplier > 3){
            if(isMultiplier(symbol1) == false){
                return multiplier * paylines[symbol1];
            }
            else if(isMultiplier(symbol2) == false){
                return multiplier * paylines[symbol2];
            }

            return multiplier * paylines[symbol3];    
        }
        else if(symbol1 == symbol2 || symbol1 == symbol3 || symbol2 == symbol3){
            if(isMultiplier(symbol1) == false){
                return multiplier * paylines[symbol1];
            }
            else if(isMultiplier(symbol2) == false){
                return multiplier * paylines[symbol2];
            }
            
            return multiplier * paylines[symbol3];
        }

        return 0.0;
    }

    return 0.0;
}

PayStrategy::PayStrategy(){
/*
    payLines.push_back("@ = .25");
    payLines.push_back("# = .5");
    payLines.push_back("n = 1");
    payLines.push_back("^ = 1.5");
    payLines.push_back("0 = 4");
    payLines.push_back("1 2x = wild pays 2x payline");
    payLines.push_back("2 2x = wild pays 4x payline");
    payLines.push_back("1 2x anywhere = wild pays 2x payline");
    payLines.push_back("3 2x pays 400");
    payLines.push_back("1 3x = wild pays 3x payline");
    payLines.push_back("2 3x = wild pays 9x payline");
    payLines.push_back("1 3x anywhere = wild pays 3x payline");
    payLines.push_back("3 3x anywhere wild pays 1350");
    payLines.push_back("3 3x on payline wild pays 2700");    
    payLines.push_back("* = 10");
    payLines.push_back("$ = 20");
    payLines.push_back("7 = 50");    
*/
    payMappings["@"] = .25;
    payMappings["#"] = .5;
    payMappings["n"] = 1;
    payMappings["^"] = 1.5;
    payMappings["0"] = 4;
    payMappings["2x"] = 400;
    payMappings["3x"] = 2700;
    payMappings["*"] = 10;
    payMappings["$"] = 20;
    payMappings["7"] = 50;
    payMappings[" "] = 0;
}

double PayStrategy::payOut(string row1[], string row2[], string row3[]) const
{
   double payout = getPayout(row2[0], row2[1], row2[2], payMappings);

   return payout;
}

vector<string> PayStrategy::getPayTables() const{

    vector<string> payLines;
    payLines.push_back("@ = .25");
    payLines.push_back("# = .5");
    payLines.push_back("n = 1");
    payLines.push_back("^ = 1.5");
    payLines.push_back("0 = 4");
    payLines.push_back("1 2x = wild pays 2x payline");
    payLines.push_back("2 2x = wild pays 4x payline");
    payLines.push_back("1 2x anywhere = wild pays 2x payline");
    payLines.push_back("3 2x pays 400");
    payLines.push_back("1 3x = wild pays 3x payline");
    payLines.push_back("2 3x = wild pays 9x payline");
    payLines.push_back("1 3x anywhere = wild pays 3x payline");
    payLines.push_back("3 3x anywhere wild pays 1350");
    payLines.push_back("3 3x on payline wild pays 2700");    
    payLines.push_back("* = 10");
    payLines.push_back("$ = 20");
    payLines.push_back("7 = 50");    
    return payLines;
}
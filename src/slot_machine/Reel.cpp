#include <sstream>
#include "Reel.h"

Reel::Reel(){
    offset = 0;
}

Reel::Reel(const char *symbolsString){
    parse(symbolsString);
    offset = 0;
}

Reel::Reel(const Reel &other){

    symbols.clear();

    for(auto symbol: other.symbols){
        symbols.push_back(symbol);
    }
}

Reel Reel::operator=(const Reel &other){

    symbols.clear();

    for(auto symbol: other.symbols){
        symbols.push_back(symbol);
    }

    return *this;
}

//This reel makes the assumption 
//that the payline will be index 1 and index 0 is the line above the payline 
//and index 2 is below the payline
string Reel::operator[](int index) const{
    int actualIndex = index;

    return symbols[(index+offset)%symbols.size()];
}

// parses a comma separated list of strings into the symbols vector
void Reel::parse(const char *symbolString){

   stringstream ss(symbolString);
   string symbol;

   while(getline(ss, symbol, ',')){
       symbols.push_back(symbol);
   }    
}

int Reel::size() const{
    return symbols.size();
}

void Reel::spin(){
    offset = rand()%symbols.size();
}

int Reel::getOffset() const{
    return offset;
}
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

string Reel::operator[](int index) const{
    if(index + 1 > symbols.size() ){
        return "WTF!";
    }
    return symbols[(index+offset)%symbols.size()];
}

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
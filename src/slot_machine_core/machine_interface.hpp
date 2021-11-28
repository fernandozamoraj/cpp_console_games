#ifndef SLOT_MACHINE_GAME_HPP
#define SLOT_MACHINE_GAME_HPP
#include "machine.h"
#include "paystrategy.h"
#include "purse.hpp"
#include "spindata.hpp"

struct SpinDataDto{
     string row1[3];
     string row2[3];
     string row3[3];
     double winAmount = 0.0;
     double betAmount = 0.0;
     double balance = 0.0;
     bool spun = false;
};

struct ScreenData{
   double paid;
   double betAmount;
   double balance;
   SpinData screenSymbols;
};

#define MINCOINS 1
#define MAXCOINS 5

class MachineInterface{
private:
    Machine _machine;
    PayStrategy _payStrategy;
    Purse _purse;
    double _currentBetAmount;
    ScreenData _screenData;
public:
    MachineInterace(){
        _currentBetAmount = 1;
    }   

    bool inserFunds(double amount){
        _purse.addMoney(amount);
    }

    double cashOut(double amount){
        return _purse.cashOut();
    }

    bool changeBet(int coins){
        if(coins >= MINCOINS && coins <= MAXCOINS){
            _currentBetAmount = coins;
            return true;
        }

        return false;
    }

    bool increaseBet(){
        if(_currentBetAmount + 1 <= MAXCOINS){
            _currentBetAmount += 1;
            return true;
        }

        return false;
    }
    
    bool decreaseBet(){
        if(_currentBetAmount - 1 >= MINCOINS){
            _currentBetAmount -= 1;
            return true;
        }

        return false;
    }

    bool canSpin() const{
        return (_currentBetAmount <= _purse.getBalance());
    }

    double getBalance() const{
        return _purse.getBalance();
    }

    SpinDataDto spin(){

        SpinDataDto spinDataDto;
        if(canSpin()){

            _purse.bet(_currentBetAmount);
            SpinData spinData = _machine.spin();

            double winAmount = _payStrategy.payOut(spinData.row1, spinData.row2, spinData.row3);
            if(winAmount > 0.0){
                _purse.collectWin(winAmount);
            }

            //copy row data
            spinDataDto.betAmount = _currentBetAmount;
            spinDataDto.winAmount = winAmount;
            spinDataDto.balance = _purse.getBalance();
            spinDataDto.spun = true;
            _screenData.paid = winAmount;
            //TODO get screen symbols for display
        }

        return spinDataDto;
    }

    ScreenData getScreenData(){
        _screenData.betAmount = _currentBetAmount;
        _screenData.balance = _purse.getBalance();
    }

};

#endif // !SLOT_MACHINE_GAME_HPP
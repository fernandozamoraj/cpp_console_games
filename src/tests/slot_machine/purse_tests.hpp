#ifndef TESTS_SLOTMACHINE_PURSETESTS_H
#define TESTS_SLOTMACHINE_PURSETESTS_H
#include <string>
#include <iostream>
#include <vector>
#include "../../slot_machine/purse.hpp"
#include "../../include/tester.hpp"

using namespace std;

class PurseTests  : public Tester{

private:
    Purse purse;
public:
    PurseTests(){
        setCategory("Purse Tests");
    }

    void create_purse(){
        assert_equal(0.0, purse.getBalance(), "purse.getBalance()");
    }

    void has_correct_balance_after_bet(){
        purse.clear();
        purse.addMoney(10.0);
        purse.bet(3.0);
        assert_equal(7.0, purse.getBalance(), "has correct balance after bet 1");
        purse.bet(1.0);
        assert_equal(6.0, purse.getBalance(), "has correct balance after bet 2");       
    }

    void has_correct_balance_after_win(){
        purse.clear();
        purse.addMoney(10.0);
        purse.bet(3.0);
        purse.collectWin(6.0);
        assert_equal(13.0, purse.getBalance(), "has correct balance after win");       
    }

    void does_not_place_bet_when_balance_is_0(){
        purse.clear();
        double betAmount = purse.bet(3.0);
        assert_equal(0.0, betAmount, "does not place bet when balance is 0"); 
    }

    void does_not_place_bet_when_balance_is_less_than_bet(){
        purse.clear();
        purse.addMoney(2.0);
        double betAmount = purse.bet(3.0);
        assert_equal(0.0, betAmount, "does not place bet when balance is less than bet amount"); 
    }

    //DON'T Forget to add your tests to the run function
    void run(){

        create_purse();
        has_correct_balance_after_bet();
        has_correct_balance_after_win();
        does_not_place_bet_when_balance_is_0();
        does_not_place_bet_when_balance_is_less_than_bet();

        string results = getResults();
        
        cout << results;
    }
};

#endif
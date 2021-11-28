#ifndef TESTS_SLOTMACHINE_PAYSTRATEGYTESTS_H
#define TESTS_SLOTMACHINE_PAYSTRATEGYTESTS_H
#include <string>
#include <iostream>
#include <vector>
#include "../../include/tester.hpp"
#include "../../slot_machine_core/paystrategy.h"

using namespace std;

class PayStrategyTests  : public Tester{

private:
    PayStrategy payStrategy;
    string row1[3];
    string row2[3];
    string row3[3];
public:
   /*   
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
    p
    */ 
    PayStrategyTests(){
        setCategory("PayStrategy Tests");
    }

    void prepareRowPayline(string symbol1, string symbol2, string symbol3){
        row2[0] = symbol1;
        row2[1] = symbol2;
        row2[2] = symbol3;
    }

    void pays_on_symbol_at(){
        prepareRowPayline("@", "@", "@");
        assert_equal(.25, payStrategy.payOut(row1, row2, row3), "@ @ @");
    }

    void pays_on_symbol_pound(){
        prepareRowPayline("#", "#", "#");
        assert_equal(.5, payStrategy.payOut(row1, row2, row3), "# # #");
    }

    void pays_on_symbol_n(){
        prepareRowPayline("n", "n", "n");
        assert_equal(1.0, payStrategy.payOut(row1, row2, row3), "n n n");
    }

    void pays_on_symbol_caret(){
        prepareRowPayline("^", "^", "^");
         assert_equal(1.5, payStrategy.payOut(row1, row2, row3), "^ ^ ^");
    }

    void pays_on_symbol_zero(){
        prepareRowPayline("0", "0", "0");
        assert_equal(4.0, payStrategy.payOut(row1, row2, row3), "0 0 0");
    }

    void pays_on_symbol_star(){
        prepareRowPayline("*", "*", "*");
        assert_equal(10.0, payStrategy.payOut(row1, row2, row3), "* * *");
    }

    void pays_on_symbol_dollar(){
        prepareRowPayline("$", "$", "$");
        assert_equal(20.0, payStrategy.payOut(row1, row2, row3), "$ $ $");
    }

    void pays_2x_symbol_dollar(){
        prepareRowPayline("$", "$", "2x");
         assert_equal(40.0, payStrategy.payOut(row1, row2, row3), "$ $ 2x");

        prepareRowPayline("$", "2x", "$");
        assert_equal(40.0, payStrategy.payOut(row1, row2, row3), "$ 2x $");

        prepareRowPayline("$", "2x", "$");
        assert_equal(40.0, payStrategy.payOut(row1, row2, row3), "2x $ $");
    }

    void pays_3x_symbol_dollar(){
        prepareRowPayline("$", "$", "3x");
        assert_equal(60.0, payStrategy.payOut(row1, row2, row3), "$ $ 2x");

        prepareRowPayline("$", "3x", "$");
        assert_equal(60.0, payStrategy.payOut(row1, row2, row3), "$ 2x $");

        prepareRowPayline("3x", "$", "$");
        assert_equal(60.0, payStrategy.payOut(row1, row2, row3), "2x $ $");
    }

    void pays_double2x_symbol_dollar(){
        prepareRowPayline("2x", "2x", "$");
         assert_equal(80.0, payStrategy.payOut(row1, row2, row3), "2x 2x $");

         prepareRowPayline("2x", "$", "2x");
         assert_equal(80.0, payStrategy.payOut(row1, row2, row3), "2x $  2x");

         prepareRowPayline("$", "2x", "2x");
         assert_equal(80.0, payStrategy.payOut(row1, row2, row3), "$  2x 2x");;
    }

    void pays_double3x_symbol_dollar(){
        prepareRowPayline("$", "3x", "3x");
        assert_equal(180.0, payStrategy.payOut(row1, row2, row3), "$ 3x 3x");

        prepareRowPayline("3x", "$", "3x");
        assert_equal(180.0, payStrategy.payOut(row1, row2, row3), "3x $ 3x");

        prepareRowPayline("3x", "3x", "$");
        assert_equal(180.0, payStrategy.payOut(row1, row2, row3), "3x 3x $");
    }

    void pays_triple2x_symbol_dollar(){
        prepareRowPayline("2x", "2x", "2x");
        assert_equal(400.0, payStrategy.payOut(row1, row2, row3), "2x 2x 2x");
    }

    void pays_triple3x_symbol_dollar(){
        prepareRowPayline("3x", "3x", "3x");
        assert_equal(2700.0, payStrategy.payOut(row1, row2, row3), "3x 3x 3x");
    }

    void pays_combined_2x_and_3x(){
        prepareRowPayline("3x", "2x", "$");
        assert_equal(120.0, payStrategy.payOut(row1, row2, row3), "3x 2x $");

        prepareRowPayline("2x", "3x", "$");
        assert_equal(120.0, payStrategy.payOut(row1, row2, row3), "2x 3x $");

        prepareRowPayline("3x", "$", "2x");
        assert_equal(120.0, payStrategy.payOut(row1, row2, row3), "3x  $ 2x");

        prepareRowPayline("2x", "$", "3x");
        assert_equal(120.0, payStrategy.payOut(row1, row2, row3), "2x  $ 3x");

        prepareRowPayline("$", "3x", "2x");
        assert_equal(120.0, payStrategy.payOut(row1, row2, row3), " $ 3x 2x");

        prepareRowPayline("$", "2x", "3x");
        assert_equal(120.0, payStrategy.payOut(row1, row2, row3), " $ 2x 3x");
    }

    void pays_3x_anywhere_combined_with_payline(){
        assert_true(false, "Need a test for this");
    }

    void run(){
        pays_on_symbol_at();
        pays_on_symbol_caret();
        pays_on_symbol_dollar();
        pays_on_symbol_n();
        pays_on_symbol_pound();
        pays_on_symbol_star();
        pays_on_symbol_zero();
        pays_2x_symbol_dollar();
        pays_3x_symbol_dollar();
        pays_double2x_symbol_dollar();
        pays_double3x_symbol_dollar();
        pays_triple2x_symbol_dollar();
        pays_triple3x_symbol_dollar();
        pays_combined_2x_and_3x();
        pays_3x_anywhere_combined_with_payline();
        
        cout << getResults();
    }
};

#endif
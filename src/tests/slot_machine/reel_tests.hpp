#ifndef TESTS_SLOTMACHINE_REETESTSS_H
#define TESTS_SLOTMACHINE_REETESTSS_H
#include <string>
#include <iostream>
#include <vector>
#include "../../slot_machine/Reel.h"
#include "../../include/tester.h"

using namespace std;

class ReelTests  : public Tester{

private:

    Reel reel;
    vector<string> symbols;

public:
    ReelTests(){

        setCategory("ReelTests");
        reel = Reel("7, ,@, ,n,@, ,@,#,$, ,^,&, ,*, ,1x, ,2x, ,3x, ");
        symbols.push_back("7");
        symbols.push_back(" ");
        symbols.push_back("@");
        symbols.push_back(" ");
        symbols.push_back("n");
        symbols.push_back("@");
        symbols.push_back(" ");
        symbols.push_back("@");
        symbols.push_back("#");
        symbols.push_back("$");
        symbols.push_back(" ");
        symbols.push_back("^");
        symbols.push_back("&");
        symbols.push_back(" ");
        symbols.push_back("*");
        symbols.push_back(" ");
        symbols.push_back("1x");
        symbols.push_back(" ");
        symbols.push_back("2x");
        symbols.push_back(" ");
        symbols.push_back("3x");
        symbols.push_back(" ");
        
    }

    void create_reel_test(){

        assert_equal("7", reel[0], "create reel [0]l");
        assert_equal(" ", reel[1], "create reel [1]");
        assert_equal("3x", reel[20], "create reel [20]");
        assert_equal(22, reel.size(), "create reel reel.size()");
        
        std::cout << "ran tests" << endl;
    }

    void when_spun_sets_offset(){
        reel.spin();
        int offset = reel.getOffset();
        assert_true(offset >= 0, "offset > 0");
    }

    void when_spun_offset_is_correct(){
        reel.spin();
        int offset1 = reel.getOffset();
        reel.spin();
        int offset2 = reel.getOffset();
        assert_true(offset1 != offset2, "offset1 != offset2");
        assert_equal(reel[0], symbols[offset2], "offset check");
        cout << "offset2 " << offset2 << endl;
    }

    void run(){

        create_reel_test();
        when_spun_sets_offset();
        when_spun_offset_is_correct();

        string results = getResults();

        cout << "results: " << endl;
        
        cout << results;
    }

};

#endif
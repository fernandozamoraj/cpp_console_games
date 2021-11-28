#ifndef TESTS_SLOTMACHINE_MACHINETESTS_H
#define TESTS_SLOTMACHINE_MACHINETESTS_H
#include <string>
#include <iostream>
#include <vector>
#include "../../slot_machine/machine.h"
#include "../../slot_machine/spindata.hpp"
#include "../../include/tester.hpp"

using namespace std;

class MachineTests  : public Tester{

    Machine machine;
public:
    MachineTests(){
        setCategory("Machine Tests");
    }

    void create_machine(){
        assert_equal("7", machine.getReel(0, 0), "machine.getReel(0,0)");
    }

    void machine_has_symbols_after_spin(){
        SpinData spinData = machine.spin();
        assert_true(machine.getReel(0,0) != machine.getReel(1,0) && machine.getReel(0,0) != "7", "reels are different after spin");
    }

    void machine_returns_correct_spin_data(){
        SpinData spinData = machine.spin();
        assert_true(machine.getReel(0,0) != machine.getReel(1,0) && machine.getReel(0,0) != "7", "reels are different after spin");
        assert_equal(spinData.row1[0], machine.getReel(0,0), "spinData1");
        assert_equal(spinData.row1[1], machine.getReel(1,0), "spinData2");
        assert_equal(spinData.row1[2], machine.getReel(2,0), "spinData3");
        assert_equal(spinData.row2[0], machine.getReel(0,1), "spinData4");
        assert_equal(spinData.row2[1], machine.getReel(1,1), "spinData5");
        assert_equal(spinData.row2[2], machine.getReel(2,1), "spinData6");
        assert_equal(spinData.row3[0], machine.getReel(0,2), "spinData7");
        assert_equal(spinData.row3[1], machine.getReel(1,2), "spinData8");
        assert_equal(spinData.row3[2], machine.getReel(2,2), "spinData9");
    }


    void run(){
        create_machine();
        machine_has_symbols_after_spin();
        machine_returns_correct_spin_data();
        cout << getResults();
    }
};

#endif
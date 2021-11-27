#ifndef TESTS_SLOTMACHINE_MACHINETESTSS_H
#define TESTS_SLOTMACHINE_MACHINETESTSS_H
#include <string>
#include <iostream>
#include <vector>
#include "../../slot_machine/machine.h"
#include "../../include/tester.h"

using namespace std;

class MachineTests  : public Tester{

    Machine machine;
public:
    MachineTests(){
        setCategory("Machine Tests");
    }

    void create_machine(){
        assert_equal("7", machine.getReel(0, 0), "getReel(0)");
    }

    void machine_has_symbols_after_spin(){
        machine.spin();
        assert_true(machine.getReel(0,0) != machine.getReel(1,0), "reels are different after spin");
    }


    void run(){

        create_machine();
        machine_has_symbols_after_spin();

        string results = getResults();
        
        cout << results;
    }
};

#endif
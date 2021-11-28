#ifndef TESTS_SLOTMACHINE_MACHINE_INTERFACE_TESTS_H
#define TESTS_SLOTMACHINE_MACHINE_INTERFACE_TESTS_H
#include <string>
#include <iostream>
#include <vector>
#include "../../slot_machine_core/machine_interface.hpp"
#include "../../include/tester.hpp"

using namespace std;

class MachineInterfaceTests  : public Tester{

    MachineInterface machine;
public:
    MachineInterfaceTests(){
        setCategory("Machine Interface Tests");
    }

    void create_machine_interface(){
        assert_true(false, "need machine interface tests");
    }

    void run(){
        create_machine_interface();
        cout << getResults();
    }
};

#endif
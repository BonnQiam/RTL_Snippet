#include <verilated.h>

#include "VAuto_LFSR_8_RTL.h"
#include "Auto_LFSR_8.h"

#include <cassert>
#include <iostream>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VAuto_LFSR_8_RTL* top = new VAuto_LFSR_8_RTL;

    Auto_LFSR_8_RTL ref;

    // Test Rst functionality
    top->Reset = 0;
    ref.operate(0);
    // Toggle clock
    top->Clock = 0;
    top->eval();
    top->Clock = 1;
    top->eval();

    assert(top->Y == ref.get_output());

    top->Reset = 1;
    for (int i = 0; i < 25; ++i) {
        // Toggle clock
        top->Clock = 0;
        top->eval();
        top->Clock = 1;
        top->eval();

        ref.operate(1);

        std::cout << "Y: " << binary_format(int(top->Y),8) 
                << " Expected: " << binary_format(int(ref.get_output()),8) 
                << std::endl;

        assert(top->Y == ref.get_output());
    }

    delete top;
    std::cout << "All test passed" << std::endl;
    return 0;
}
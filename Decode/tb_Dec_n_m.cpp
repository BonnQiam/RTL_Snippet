#include <verilated.h>
#include "VDec_n_m.h"
#include <cassert>
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VDec_n_m* top = new VDec_n_m;

    // Test case 1: When a = 0, b should be 1 (1 << 0)
    top->a = 0;
    top->eval();
    assert(top->b == 1);

    // Test case 2: When a = 1, b should be 2 (1 << 1)
    top->a = 1;
    top->eval();
    assert(top->b == 2);

    // Test case 3: When a = 2, b should be 4 (1 << 2)
    top->a = 2;
    top->eval();
    assert(top->b == 4);

    // Test case 4: When a = 3, b should be 8 (1 << 3)
    top->a = 3;
    top->eval();
    assert(top->b == 8);

    delete top;
    std::cout << "Test passed" << std::endl;
    return 0;
}
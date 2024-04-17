#include <verilated.h>
//#include "Vbinary_mux_3_case.h"
#include "Vbinary_mux_3.h"
#include <cassert>
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    //Vbinary_mux_3_case* top = new Vbinary_mux_3_case;
    Vbinary_mux_3* top = new Vbinary_mux_3;

    // Test case 1: When sb = 0, b should be a0
    top->a0 = 1;
    top->a1 = 0;
    top->a2 = 0;
    top->sb = 0;
    top->eval();
    assert(top->b == 1);

    // Test case 2: When sb = 1, b should be a1
    top->a0 = 0;
    top->a1 = 1;
    top->a2 = 0;
    top->sb = 1;
    top->eval();
    assert(top->b == 1);

    // Test case 3: When sb = 2, b should be a2
    top->a0 = 0;
    top->a1 = 0;
    top->a2 = 1;
    top->sb = 2;
    top->eval();
    assert(top->b == 1);

    delete top;
    std::cout << "Test passed" << std::endl;
    return 0;
}
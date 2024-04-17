#include <verilated.h>
//#include "Vmux_3_assign.h"
#include "Vmux_3_case.h"

#include <cassert>
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    //Vmux_3_assign* top = new Vmux_3_assign;
    Vmux_3_case* top = new Vmux_3_case;

    // Assuming the module has inputs: a2, a1, a0, s
    // and output: b

    // Test case 1: When s = 1, b should be a0
    top->a2 = 0;
    top->a1 = 0;
    top->a0 = 1;
    top->s = 1;
    top->eval();
    assert(top->b == 1);

    // Test case 2: When s = 2, b should be a1
    top->a2 = 0;
    top->a1 = 1;
    top->a0 = 0;
    top->s = 2;
    top->eval();
    assert(top->b == 1);

    // Test case 3: When s = 4, b should be a2
    top->a2 = 1;
    top->a1 = 0;
    top->a0 = 0;
    top->s = 4;
    top->eval();
    assert(top->b == 1);

    delete top;
    std::cout << "Test passed" << std::endl;
    return 0;
}
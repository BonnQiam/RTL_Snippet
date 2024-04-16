#include <verilated.h>
#include "VEncoder_4_2.h"
#include <cassert>

#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VEncoder_4_2* top = new VEncoder_4_2;

    for (int i = 0; i < 4; i++) {
        top->a = 1 << i;
        top->eval();
        assert(top->b == i);
    }

    delete top;
    std::cout << "All tests pass" << std::endl;
    return 0;
}
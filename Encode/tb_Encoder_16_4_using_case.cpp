#include <verilated.h>
#include "VEncoder_16_4_using_case.h"

#include <cassert>
#include <iostream>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VEncoder_16_4_using_case* top = new VEncoder_16_4_using_case;

    top->enable = 1;
    for (int i = 0; i < 16; ++i) {
        top->encoder_in  = 1 << i;
        top->eval();
        assert(top->binary_out == i);
    }

    top->enable = 0;
    top->eval();
    assert(top->binary_out == 0);

    top->final();
    delete top;
    std::cout << "All test pass" << std::endl;
    return 0;
}
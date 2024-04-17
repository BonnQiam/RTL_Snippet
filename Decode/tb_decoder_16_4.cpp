#include <verilated.h>
//#include "Vdecoder_16_4_assign.h"
#include "Vdecoder_16_4_case.h"

#include <cassert>
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    //Vdecoder_16_4_assign* top = new Vdecoder_16_4_assign;
    Vdecoder_16_4_case* top = new Vdecoder_16_4_case;

    // Test all possible inputs
    top->enable = 1;
    for (int i = 0; i < 16; ++i) {
        top->binary_in = i;
        top->eval();

        assert(top->decoder_out == (1 << i));
    }

    delete top;
    std::cout << "Test passed" << std::endl;
    return 0;
}
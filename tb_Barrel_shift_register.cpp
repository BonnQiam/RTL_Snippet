#include <verilated.h>
#include "VBarrel_shift_register.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VBarrel_shift_register* top = new VBarrel_shift_register;

    // Initialize
    top->Data_in = 0;
    top->load = 0;
    top->clock = 0;
    top->reset = 0;
    top->eval();

    // Run some test cases
    for(int i = 0; i < 256; i++) {
        // Test load functionality
        top->Data_in = i;
        top->load = 1;
        top->clock = 0; // Start with clock low
        top->eval();

        top->clock = 1; // Clock high (posedge)
        top->eval();
        assert(top->Data_out == i);

        // Test shift functionality
        top->load = 0;
        top->clock = 0; // Clock low
        top->eval();

        top->clock = 1; // Clock high (posedge)
        top->eval();
        assert(top->Data_out == ((i << 1) & 0xFF | (i >> 7)));// rotate shift left

        // Test reset functionality
        top->reset = 1;
        top->clock = 0; // Clock low
        top->eval();

        top->clock = 1; // Clock high (posedge)
        top->eval();
        assert(top->Data_out == 0);
        top->reset = 0;
    }

    delete top;
    std::cout << "All test passed!" << std::endl;
    return 0;
}
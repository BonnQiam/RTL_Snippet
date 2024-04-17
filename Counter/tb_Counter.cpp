#include <verilated.h>
//#include "VCounter_8.h"
#include "VCounter_32.h"

#include <cassert>
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    //VCounter_8* top = new VCounter_8;
    VCounter_32* top = new VCounter_32;

    // Assuming the module has inputs: clk, rst
    // and output: out

    // Initialize inputs
    top->clk = 0;
    top->rst = 0;

    // Test case: Counter should increment on each clock cycle
    //for (int i = 0; i < 8; ++i) {
    for (int i = 0; i < 32; ++i) {
        // Toggle clock
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        // Check output
        std::cout << "i: " << i << " out: " << int(top->out) << std::endl;
        //assert(top->out == (i+1) % 8);
        assert(top->out == (i+1) % 32);
    }

    // Test case: Counter should reset when rst is high
    top->rst = 1;
    top->clk = !top->clk;
    top->clk = !top->clk;
    top->eval();
    assert(top->out == 0);

    delete top;
    //std::cout << "Counter_8 test passed!" << std::endl;
    std::cout << "Counter_32 test passed!" << std::endl;
    return 0;
}
#include <verilated.h>
#include "VShift_register_n.h"
#include "ShiftRegister.h"

#include <time.h>
#include <cassert>
#include <iostream>
#include <bitset>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VShift_register_n* top = new VShift_register_n;

    top->clk = 0;
    top->rst = 1;

    assert(top->out  == 0);

    // Reset
    top->rst = 0;

    // Test sin = 0;
    srand(time(0));
    ShiftRegister sr;
    for (int i = 0; i < 4; i++) {
        // random 0/1 for top->sin
        top->sin = rand() % 2;
        sr.shiftLeft(top->sin);

        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        std::cout << "sin: " << binary_format(int(top->sin),1) 
                << " Expected: " << binary_format(int(sr.get()),4) 
                << " Output: " << binary_format(int(top->out),4) 
                << std::endl;

        assert(top->out == sr.get());
    }


    delete top;
    return 0;
}
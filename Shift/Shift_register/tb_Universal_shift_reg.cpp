#include <verilated.h>

#include "VUniversal_shift_reg.h"
#include "ShiftRegister.h"

#include <time.h>
#include <cassert>
#include <iostream>
#include <bitset>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VUniversal_shift_reg* top = new VUniversal_shift_reg;

    Universal_shift_reg ref;
    
    /*
    // Test rst
    top->rst = 1;

    // Toggle clock
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();

    assert(top->Data_Out == 0);
    assert(top->MSB_Out == 0);
    assert(top->LSB_Out == 0);
    std::cout << "Rst functionality passed" << std::endl;

    top->rst = 0;
    */
    srand(time(0));
    for (int i = 0; i < 25; ++i) {
        top->rst = rand() % 2;
        top->s1  = rand() % 2;
        top->s0  = rand() % 2;

        top->MSB_In = rand() % 2;
        top->LSB_In = rand() % 2;
        top->Data_In = rand() % 16;

        // Toggle clock
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        ref.operate(top->rst, top->s1, top->s0, top->Data_In, top->MSB_In, top->LSB_In);

        assert(top->Data_Out == ref.get_output());
        assert(top->MSB_Out == ref.get_MSB_output());
        assert(top->LSB_Out == ref.get_LSB_output());
    }

    delete top;
    std::cout << "Simulation passed" << std::endl;
    exit(0);
}
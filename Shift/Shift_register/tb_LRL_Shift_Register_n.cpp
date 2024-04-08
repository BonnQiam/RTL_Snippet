#include <verilated.h>

#include "VLRL_Shift_Register_n.h"
#include "ShiftRegister.h"

#include <time.h>
#include <cassert>
#include <iostream>
#include <bitset>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VLRL_Shift_Register_n* top = new VLRL_Shift_Register_n;

    LRL_Shift_Register_n ref;

    /*
    // Test rst
    top->rst = 1;

    // Toggle clock
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();

    assert(top->out == 0);
    std::cout << "Rst functionality passed" << std::endl;
    */
    srand(time(0));
    for (int i = 0; i < 25; ++i) {
        top->rst   = rand() % 2;
        top->left  = rand() % 2;
        top->right = rand() % 2;
        top->load  = rand() % 2;
        
        top->sin   = rand() % 2;
        top->in    = rand() % 16;

        // Toggle clock
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        ref.operate(top->rst, top->left, top->right, top->load, top->sin, top->in);

        assert(top->out == int(ref.get_output()));
    }

    delete top;
    std::cout << "Simulation passed" << std::endl;
    exit(0);
}
#include "verilated.h"

#include "VRound_robin_n_Arb_1.h"
#include "Arb.h"

#include <cassert>
#include <iostream>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VRound_robin_n_Arb_1* top = new VRound_robin_n_Arb_1;

    srand(time(0));
    RoundRobinArbiter<4> arb;

    top->rstn = 0;
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();

    arb.reset();
    
    top->rstn = 1;
    for(int i = 0; i < 30; ++i) {
        top->req = rand() & 0b1111;

        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        arb.update(int(top->req));

        std::cout << "Input: " << binary_format(int(top->req), 4)
            << " Expected: " << binary_format(arb.get_gnt(), 4)
            << " Got: " << binary_format(int(top->gnt), 4)
            << std::endl;
    }


    delete top;
    std::cout << "All test passed\n" << std::endl;
    return 0;
}
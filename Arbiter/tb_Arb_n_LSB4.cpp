#include "verilated.h"

#include "VArb_n_LSB4.h"
#include "Arb.h"

#include <cassert>
#include <iostream>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VArb_n_LSB4* top = new VArb_n_LSB4;

    for (int i = 0; i < (1<<16); ++i) {
        top->req = i;
        top->eval();

        Arb_n_LSB<16> ref(i);

        std::cout << "Input: " << binary_format(i, 16)
        << " Expected: " << binary_format(ref.get_g(), 16) 
        << " Got: " << binary_format(int(top->gnt), 16)
        << std::endl;

        assert(top->gnt == ref.get_g());
    }

    delete top;
    std::cout << "All test passed\n" << std::endl;
    return 0;
}
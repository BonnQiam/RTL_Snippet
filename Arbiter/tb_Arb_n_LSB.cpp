#include "verilated.h"

#include "VArb_n_LSB.h"
#include "Arb.h"

#include <cassert>
#include <iostream>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VArb_n_LSB* top = new VArb_n_LSB;

    for (int i = 0; i < (1<<8); ++i) {
        top->r = i;
        top->eval();

        Arb_n_LSB<8> ref(i);

        std::cout << "Input: " << binary_format(i, 8)
        << " Expected: " << binary_format(ref.get_g(), 8) 
        << " Got: " << binary_format(int(top->g), 8)
        << std::endl;

        assert(top->g == ref.get_g());
    }

    delete top;
    std::cout << "All test passed\n" << std::endl;
    return 0;
}
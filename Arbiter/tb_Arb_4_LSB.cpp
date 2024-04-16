#include "verilated.h"

#include "VArb_4_LSB.h"
#include "Arb.h"

#include <cassert>
#include <iostream>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VArb_4_LSB* top = new VArb_4_LSB;

    for (int i = 0; i < 16; ++i) {
        top->r = i;
        top->eval();

        Arb_4_LSB ref(top->r);

        std::cout 
        << "Input: " << binary_format(i, 4) << 
        << " Expected: " << binary_format(ref.get_g(), 4) 
        << " Got: " << binary_format(int(top->g), 4)
        << std::endl;

        assert(top->g == ref.get_g());
    }

    delete top;
    std::cout << "All test passed\n" << std::endl;
    return 0;
}
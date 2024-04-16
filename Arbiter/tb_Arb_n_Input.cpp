#include "verilated.h"

#include "VArb_n_Input.h"
#include "Arb.h"

#include <cassert>
#include <iostream>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VArb_n_Input* top = new VArb_n_Input;

    for(int r = 0; r < (1<<4); ++r) {
        for(int base = 1; base <= 8; base *= 2){
            top->req = r;
            top->base = base;
            top->eval();

            Arb_n_Input<4> ref(r, base);

            std::cout << "Base: " << base
            << " Input: " << binary_format(r, 4)
            << " Expected: " << binary_format(ref.get_g(), 4) 
            << " Got: " << binary_format(int(top->gnt), 4)
            << std::endl;

            assert(top->gnt == ref.get_g());
        }
    }

    delete top;
    std::cout << "All test passed\n" << std::endl;
    return 0;

}
#include <verilated.h>
#include "VComp_2_RTL.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VComp_2_RTL* top = new VComp_2_RTL;

    // Initialize
    top->A0 = 0;
    top->A1 = 0;
    top->B0 = 0;
    top->B1 = 0;
    top->eval();

    // Run some test cases
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            // set {A1,A0} = i and {B1,B0} = j
            top->A0 = i & 1;
            top->A1 = (i >> 1) & 1;

            top->B0 = j & 1;
            top->B1 = (j >> 1) & 1;

            top->eval();
            assert(top->A_lt_B == (i < j));
            assert(top->A_gt_B == (i > j));
            assert(top->A_eq_B == (i == j));
        }
    }

    delete top;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
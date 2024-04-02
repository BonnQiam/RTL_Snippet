#include <verilated.h>
#include "VComp_2_algo.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VComp_2_algo* top = new VComp_2_algo;

    // Initialize
    top->A = 0;
    top->B = 0;
    top->eval();

    // Run some test cases
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            top->A = i;
            top->B = j;
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
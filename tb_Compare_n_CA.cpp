#include <verilated.h>
#include "VCompare_n_CA.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VCompare_n_CA* top = new VCompare_n_CA;

    // Initialize
    top->A = 0;
    top->B = 0;
    top->eval();

    // Run some test cases
    for(uint64_t i = 0; i < 64; i++) {
        for(uint64_t j = 0; j < 64; j++) {
            top->A = i;
            top->B = j;
            top->eval();
            assert(top->A_lt_B == (i < j));
            assert(top->A_gt_B == (i > j));
            assert(top->A_eq_B == (i == j));
        }
    }

    delete top;
    printf("All tests passed!\n");
    return 0;
}
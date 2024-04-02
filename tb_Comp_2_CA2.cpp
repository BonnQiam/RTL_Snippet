#include <verilated.h>
#include "VComp_2_CA2.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VComp_2_CA2* top = new VComp_2_CA2;

    // Initialize model
    top->A = 0;
    top->B = 0;
    top->eval();

    // Run some test cases
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            top->A = i;
            top->B = j;

            top->eval();

            std::cout << "A = " << i << ", B = " << j << std::endl;
            std::cout << "In Model: A_lt_B = " << (i < j) << ", A_gt_B = " << (i > j) << ", A_eq_B = " << (i == j) << std::endl;
            std::cout << "In RTL: A_lt_B = " << int(top->A_lt_B) << ", A_gt_B = " << int(top->A_gt_B) << ", A_eq_B = " << int(top->A_eq_B) << std::endl;

            assert(top->A_lt_B == (i < j));
            assert(top->A_gt_B == (i > j));
            assert(top->A_eq_B == (i == j));
        }
    }

    delete top;
    printf("All tests passed!\n");
    return 0;
}
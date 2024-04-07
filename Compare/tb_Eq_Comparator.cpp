#include <verilated.h>
#include "VEq_Comparator.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VEq_Comparator* top = new VEq_Comparator;

    // Initialize
    top->a = 0;
    top->b = 0;
    top->eval();

    // Run some test cases
    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < 256; j++) {
            top->a = i;
            top->b = j;
            top->eval();
            assert(top->eq == (i == j));
        }
    }

    delete top;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
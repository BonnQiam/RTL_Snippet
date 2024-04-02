#include <verilated.h>
#include "VMagComp_b.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VMagComp_b* top = new VMagComp_b;

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
            assert(top->gt == (i > j));
        }
    }

    delete top;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
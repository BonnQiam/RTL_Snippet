#include <verilated.h>
#include "VShift_Left_Width_ShiftBit.h"
#include <iostream>
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VShift_Left_Width_ShiftBit* top = new VShift_Left_Width_ShiftBit;

    // Initialize
    top->a = 0;
    top->n = 0;
    top->eval();

    // Run some test cases
    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < 8; j++) {
            top->a = i;
            top->n = j;
            top->eval();

            std::cout << "Input: " << i << " Shift: " << j << std::endl;
            int expected = (i << j);
            std::cout << "Expected: " << expected << " Got: " << int(top->b) << std::endl;

            assert(top->b == expected);
        }
    }

    delete top;
    std::cout << "Shift_Left_Width_ShiftBit test passed!" << std::endl;
    return 0;
}
#include <verilated.h>          // Defines common routines
#include "VComp_2_CA1.h"       // From Verilating "VComp_2_CA1.h"

#include <time.h>
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);   // Pass command line arguments to Verilator
    VComp_2_CA1* top = new VComp_2_CA1;   // Create instance of module
    
    // Simulate for 100 clock cycles
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        // Set inputs
        top->A1 = rand() & 1;
        top->A0 = rand() & 1;
        top->B1 = rand() & 1;
        top->B0 = rand() & 1;
        
        // Evaluate model
        top->eval();
        
        //display input and  outputs
        std::cout << "A1: " << (int)top->A1 << std::endl;
        std::cout << "A0: " << (int)top->A0 << std::endl;
        std::cout << "B1: " << (int)top->B1 << std::endl;
        std::cout << "B0: " << (int)top->B0 << std::endl;
        std::cout << "A_lt_B: " << (int)top->A_lt_B << std::endl;
        std::cout << "A_gt_B: " << (int)top->A_gt_B << std::endl;
        std::cout << "A_eq_B: " << (int)top->A_eq_B << std::endl;
        std::cout << "----------------" << std::endl;
    }
    
    delete top;   // Delete instance
    
    return 0;
}

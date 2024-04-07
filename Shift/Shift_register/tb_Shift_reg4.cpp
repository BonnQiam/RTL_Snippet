#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VShift_reg4.h"
#include "ShiftRegister.h"

#include <time.h>
#include <cassert>
#include<iostream>
#include<bitset>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VShift_reg4* top = new VShift_reg4;

    // Create a VCD file
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 5);
    tfp->open("wave.vcd");

    // Test shift and sync reset functionality
    srand(time(0));
    ShiftRegister sr;
    for(int i = 0; i < 25; i++) {
        // Reset on the first cycle
        if(i == 0) {
            top->reset = 0;
        } 
        else if ((i>0) && (i<5) ){
            top->reset = 1;
            top->Data_in = rand() % 2;
            sr.shiftRight(top->Data_in);
        }
        else {
            top->reset = 1;
            top->Data_in = rand() % 2;
            sr.shiftRight(top->Data_in);
        }

        // Toggle clock
        top->clock = 0;
        top->eval();
        top->clock = 1;
        top->eval();

        // Dump to VCD file
        tfp->dump(i);

        if(i==0){
            assert(top->Data_out == 0);
            std::cout << "Sync Rst functionality is passed" << std::endl;
        }
        else if ((i>0) && (i<5) ){}
        else if ((i>=5) && (i<=20))
        {
            int expected = sr.get() & 0x01;
            
            std::cout << "Data_in: " << int(top->Data_in)
                << " State: " << binary_format(sr.get(),4)
                << " Expected: " << expected
                << " Output: " << int(top->Data_out)
                << std::endl;

            assert(top->Data_out == expected);
        }
    }

    // Test reset functionality
    top->reset = 1;
    top->reset = 0;
    top->eval();
    assert(top->Data_out == 0);
    std::cout << "Async Reset functionality is passed" << std::endl;

    // Close VCD file
    tfp->close();

    delete top;
    return 0;
}
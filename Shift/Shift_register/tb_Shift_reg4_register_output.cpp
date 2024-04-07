#include <verilated.h>

#include "VShift_reg4_register_output.h"
#include "ShiftRegister.h"

#include <time.h>
#include <cassert>
#include <iostream>
#include <bitset>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

static int expected_new_signal;

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VShift_reg4_register_output* top = new VShift_reg4_register_output;

    // Initialize inputs
    top->clock = 0;
    top->reset = 0;

    // Test shift and sync reset functionality
    srand(time(0));
    ShiftRegister sr;
    for(int i = 0; i < 25; i++) {
        // Reset on the first cycle
        if(i == 0) {
            top->reset = 1;
        } 
        else if ((i>0) && (i<5) ){
            top->reset = 0;
            top->Data_in = rand() % 2;

            sr.shiftRight(top->Data_in);
        }
        else {
            top->reset = 0;
            top->Data_in = rand() % 2;

            // get most high bit of the shift register
            int expected_sig_a = (sr.get() >> 3) & 0x01;
            // get second most high bit of the shift register
            int expected_sig_b = (sr.get() >> 2) & 0x01;

            expected_new_signal = ((~expected_sig_a) & expected_sig_b);

            std::cout << " State: " << binary_format(sr.get())
                    << " Expected_sig_a: " << expected_sig_a
                    << " Expected_sig_b: " << expected_sig_b
                    << " Expected_new_signal: " << expected_new_signal
                    << std::endl;

            sr.shiftRight(top->Data_in);
        }

        // Toggle clock
        top->clock = 0;
        top->eval();
        top->clock = 1;
        top->eval();

        // Check outputs and assert
        if(i==0){
            assert(top->sig_d == 0);
            std::cout << "Sync Rst functionality is passed" << std::endl;
        }
        else if ((i>0) && (i<5) ){}
        else if ((i>=5) && (i<=20))
        {
            int expected_sig_d = sr.get() & 0x01;// most low bit of the shift register
            
            std::cout << "Data_in: " << int(top->Data_in) 
                    << " State: " << binary_format(sr.get(),4)
                    << " Output_sig_d: " << int(top->sig_d)
                    << " Output_new_signal: " << int(top->new_signal)
                    << std::endl;

            assert(top->sig_d == expected_sig_d);
            assert(top->new_signal == expected_new_signal);
        }
    }

    // Test reset functionality
    top->reset = 0;
    top->reset = 1;
    top->eval();
    assert(top->sig_d == 0);
    assert(top->new_signal == 0);
    std::cout << "Async Reset functionality is passed" << std::endl;

    delete top;
    return 0;
}
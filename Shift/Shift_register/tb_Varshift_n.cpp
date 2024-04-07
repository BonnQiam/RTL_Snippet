#include <verilated.h>

#include "VVarshift_n.h"
#include "ShiftRegister.h"

#include <time.h>
#include <cassert>
#include <iostream>
#include <bitset>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

static int state;
static uint8_t shift_bit;

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VVarshift_n* top = new VVarshift_n;

    // Test shift and sync reset functionality
    top->rst = 0;
    srand(time(0));
    Varshift_n sr;
    for(int i = 0; i < 25; i++) {
        if(i<4){
            top->rst = 0;
            top->sh_amount = 2;
            top->sin = rand() % 5;

            sr.shift(top->sh_amount, top->sin);
        }
        else{
            top->rst = 0;
            top->sh_amount = rand() % 4;
            top->sin = rand() % 8;

            shift_bit = int(top->sh_amount);
            state     = sr.get();
            sr.shift(top->sh_amount, top->sin);
        }

        // Toggle clock
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        // Check outputs and assert
        if(i<4){}
        else{
            int expected = sr.get();

            std::cout << "Data_in: " << binary_format(int(top->sin),3)
                    << " sh_amount: " << int(top->sh_amount)
                    << " State: " << binary_format(state,8)
                    << " Expected: " << binary_format(expected,8)
                    << " Output: " << binary_format(int(top->out),8)
                    << std::endl;

            assert(top->out == expected);
        }
    }

    delete top;
    std::cout << "All test passed!" << std::endl;
    return 0;
}
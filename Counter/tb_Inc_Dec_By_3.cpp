#include <verilated.h>

#include "VInc_Dec_By_3.h"
#include "Inc_Dec_By_3.h"

#include <cassert>
#include <iostream>
#include <time.h>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VInc_Dec_By_3* top = new VInc_Dec_By_3;

    Inc_Dec_By_3 inc_dec_by_3 = Inc_Dec_By_3();

    srand(time(NULL));
    for (int i = 0; i < 30; ++i) {
        top->rst = rand() % 2;
        
        top->inc = rand() % 2;
        top->dec = rand() % 2;
        if(int(top->inc) == 0 && int(top->dec) == 0){
            top->inc = 0;
            top->dec = 0;
        }

        inc_dec_by_3.update(int(top->rst), int(top->inc), int(top->dec));

         // Toggle clock
        top->clk = 0;
        top->eval();
        top->clk = 1;

        // Check output
        std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;

        top->eval();

        if(int(top->rst) == 1){
            std::cout << "Test case: Reset" << std::endl;
            std::cout << "Expected: " << binary_format(inc_dec_by_3.get_out(), 4) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == 0);
        }
        else if(int(top->inc) == 1){
            std::cout << "Test case: Increment" << std::endl;
            std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;
            std::cout << "Expected: " << binary_format(inc_dec_by_3.get_out(), 4) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == inc_dec_by_3.get_out());
        }
        else if(int(top->dec) == 1){
            std::cout << "Test case: Decrement" << std::endl;
            std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;
            std::cout << "Expected: " << binary_format(inc_dec_by_3.get_out(), 4) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == inc_dec_by_3.get_out());
        }
    }

    delete top;
    std::cout << "Simulation passed!" << std::endl;
    return 0;
}
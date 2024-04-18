#include <verilated.h>

#include "VUp_down_Counter_3.h"
#include "Up_down_Counter_3.h"

#include <cassert>
#include <iostream>
#include <time.h>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);

    VUp_down_Counter_3* top = new VUp_down_Counter_3;
    Up_down_Counter_3* udc = new Up_down_Counter_3;

    srand(time(NULL));
    for (int i = 0; i < 30; ++i) {
        top->reset = rand() % 2;
        top->load = rand() % 2;
        top->counter_on = rand() % 2;
        top->count_up = rand() % 2;
        top->Data_in = rand() % 8;

        udc->update(int(top->reset), int(top->load), int(top->counter_on), int(top->count_up), int(top->Data_in));

        // Toggle clock
        top->clk = 0;
        top->eval();
        top->clk = 1;

        // Check output
        std::cout << "State: " << binary_format(int(top->Count), 3) << std::endl;

        top->eval();

        if(int(top->reset) == 1){
            std::cout << "Test case: Reset" << std::endl;
            std::cout << "Expected: " << binary_format(udc->get_out(), 3) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->Count == 0);
        }
        else if(int(top->load) == 1){
            std::cout << "Test case: Load" << std::endl;
            std::cout << "State: " << binary_format(int(top->Count), 3) << std::endl;
            std::cout << "Expected: " << binary_format(udc->get_out(), 3) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->Count == udc->get_out());
        }
        else if(int(top->counter_on) == 1){
            if(int(top->count_up) == 1){
                std::cout << "Test case: Up" << std::endl;
                std::cout << "State: " << binary_format(int(top->Count), 3) << std::endl;
                std::cout << "Expected: " << binary_format(udc->get_out(), 3) << std::endl;
                std::cout << "=============================" << std::endl;
                assert(top->Count == udc->get_out());
            }
            else{
                std::cout << "Test case: Down" << std::endl;
                std::cout << "State: " << binary_format(int(top->Count), 3) << std::endl;
                std::cout << "Expected: " << binary_format(udc->get_out(), 3) << std::endl;
                std::cout << "=============================" << std::endl;
                assert(top->Count == udc->get_out());
            }
        }
    }

    delete top;
    std::cout << "Up_down_Counter_3 test passed!" << std::endl;
    return 0;
}
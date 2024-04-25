#include <verilated.h>

#include "VRing_Counter_8.h"
#include "Ring_Counter_8.h"

#include <cassert>
#include <iostream>
#include <time.h>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);

    VRing_Counter_8* top = new VRing_Counter_8;
    Ring_Counter_8* ref = new Ring_Counter_8;

    srand(time(NULL));
    for (int i = 0; i < 30; ++i) {
        top->reset = rand() % 2;
        top->enable = rand() % 2;

        ref->update(int(top->enable), int(top->reset));

        // Toggle clock
        top->clock = 0;
        top->eval();
        top->clock = 1;
        top->eval();
        
        if(int(top->reset) == 1){
            std::cout << "Test case: Reset" << std::endl;
            std::cout << "Expected: " << binary_format(ref->get_count(), 8) << std::endl;
            std::cout << "RTL: " << binary_format(int(top->count), 8) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->count == 1);
        }
        else if(int(top->enable) == 1){
            std::cout << "Test case: Enable" << std::endl;
            std::cout << "Expected: " << binary_format(ref->get_count(), 8) << std::endl;
            std::cout << "RTL: " << binary_format(int(top->count), 8) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->count == ref->get_count());
        
        }
    }

    delete top;
    std::cout << "Ring_Counter_8 test passed!" << std::endl;
    return 0;
}
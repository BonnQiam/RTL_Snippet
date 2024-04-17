#include <verilated.h>

//#include "VUDL_Counter_n_1.h"
//#include "VUDL_Counter_n_2.h"
#include "VUDL_Counter_n_3.h"
#include "UDL.h"

#include <cassert>
#include <iostream>
#include <time.h>

#define binary_format(a,num_bit) std::bitset<num_bit>(a)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    //VUDL_Counter_n_1* top = new VUDL_Counter_n_1;
    //VUDL_Counter_n_2* top = new VUDL_Counter_n_2;
    VUDL_Counter_n_3* top = new VUDL_Counter_n_3;

    UDL_Counter_n* udl = new UDL_Counter_n(4);

    srand(time(NULL));
    for (int i = 0; i < 30; ++i) {
        // Random inputs
        top->rst = rand() % 2;
        top->up = rand() % 2;
        top->down = rand() % 2;
        top->load = rand() % 2;
        top->in   = rand() % 16;

        udl->update(int(top->rst), int(top->up), int(top->down), int(top->load), int(top->in));

        // Toggle clock
        top->clk = 0;
        top->eval();
        top->clk = 1;

        // Check output
        std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;

        top->eval();

        if(int(top->rst) == 1){
            std::cout << "Test case: Reset" << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == 0);
        }
        else if(int(top->up) == 1){
            std::cout << "Test case: Up" << std::endl;
            std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == udl->get_out());
        }
        else if(int(top->down) == 1){
            std::cout << "Test case: Down" << std::endl;
            std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == udl->get_out());
        }
        else if(int(top->load) == 1){
            std::cout << "Test case: Load" << std::endl;
            std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == udl->get_out());
        }
        else{
            std::cout << "Test case: No change" << std::endl;
            std::cout << "State: " << binary_format(int(top->out), 4) << std::endl;
            std::cout << "=============================" << std::endl;
            assert(top->out == udl->get_out());
        }
    } 

    delete top;
    std::cout << "UDL_Counter_n test passed!" << std::endl;
    return 0;
}
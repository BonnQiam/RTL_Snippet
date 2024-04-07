#include <verilated.h>
#include "VPar_load_reg4.h"

#include <time.h>
#include <cassert>
#include<iostream>

static int expected_Data_out;

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VPar_load_reg4* top = new VPar_load_reg4;
    
    // Test load and sync reset functionality
    srand(time(0));
    for(int i = 0; i < 5; i++) {
        if(i == 0){
            top->reset = 1;
            top->load  = 1;
        }
        else if( (i>0) && (i<3) ){
            top->reset = 0;
            top->load  = 1;

            top->Data_in = rand() % 16;
            expected_Data_out = int(top->Data_in);
        }
        else{
            top->reset = 0;
            top->load  = 0;
        }

        // Toggle clock
        top->clock = 0;
        top->eval();
        top->clock = 1;
        top->eval();

        // Check outputs and assert
        if(i==0){
            assert(top->Data_out == 0);
            std::cout << "Sync Rst functionality is passed" << std::endl;
        }
        else if( (i>1) && (i<=3) ){
            assert(top->Data_out == expected_Data_out);
            std::cout << "Load functionality is passed" << std::endl;
        }
        //! don't use 'else{}'
        else if (i>3){
            assert(top->Data_out == expected_Data_out);
            std::cout << "No Load functionality is passed" << std::endl;
        }
    }

    // Test reset functionality
    top->reset = 0;
    top->reset = 1;
    top->eval();
    assert(top->Data_out == 0);
    std::cout << "Async Reset functionality is passed" << std::endl;

    delete top;
    return 0;
}
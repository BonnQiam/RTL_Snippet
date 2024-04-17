#include "verilated.h"

//#include "Vmux_4_32_case.h"
//#include "Vmux_4_32_if.h"
#include "Vmux_4_32_CA.h"

#include <cassert>
#include <iostream>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    //Vmux_4_32_case* top = new Vmux_4_32_case;
    //Vmux_4_32_if* top = new Vmux_4_32_if;
    Vmux_4_32_CA* top = new Vmux_4_32_CA;

    top->data_0 = 0;
    top->data_1 = 1;
    top->data_2 = 2;
    top->data_3 = 3;
    top->select = 0;
    top->enable = 1;

    top->eval();

    assert(top->mux_out == 0);

    top->select = 1;

    top->eval();

    assert(top->mux_out == 1);

    top->select = 2;

    top->eval();

    assert(top->mux_out == 2);

    top->select = 3;

    top->eval();

    assert(top->mux_out == 3);

    delete top;
    std::cout << "Test passed" << std::endl;
    return 0;
}
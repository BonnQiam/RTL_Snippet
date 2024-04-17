#include <verilated.h>
//#include "Vmux_using_if.h"
//#include "Vmux_using_case.h"
#include "Vmux_using_assign.h"

#include <cassert>
#include <iostream>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    //Vmux_using_if* top = new Vmux_using_if;
    //Vmux_using_case* top = new Vmux_using_case;
    Vmux_using_assign* top = new Vmux_using_assign;

    top->din_0 = 0;
    top->din_1 = 1;
    top->sel = 0;

    top->eval();

    assert(top->mux_out == 0);

    top->sel = 1;

    top->eval();

    assert(top->mux_out == 1);

    delete top;
    std::cout << "Test passed" << std::endl;
    return 0;
}
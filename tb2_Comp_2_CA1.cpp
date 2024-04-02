#include "VComp_2_CA1.h"
#include "verilated.h"
#include <cassert>

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VComp_2_CA1* top = new VComp_2_CA1;

    for(int A1 = 0; A1 <= 1; A1++) {
        for(int A0 = 0; A0 <= 1; A0++) {
            for(int B1 = 0; B1 <= 1; B1++) {
                for(int B0 = 0; B0 <= 1; B0++) {
                    top->A1 = A1;
                    top->A0 = A0;
                    top->B1 = B1;
                    top->B0 = B0;

                    top->eval();

                    assert(top->A_lt_B == ((A1*2 + A0) < (B1*2 + B0)));
                    assert(top->A_gt_B == ((A1*2 + A0) > (B1*2 + B0)));
                    assert(top->A_eq_B == ((A1*2 + A0) == (B1*2 + B0)));
                }
            }
        }
    }

    top->final();
    delete top;
    printf("All tests passed!\n");
    return 0;
}
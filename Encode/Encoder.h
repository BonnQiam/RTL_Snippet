#include <bitset>

int priority_encoder_ref_model(int input) {
    std::bitset<16> bitset(input);
    
    for (int i = 0; i < 16; ++i) {
        if (bitset[i]) {
            return i;
        }
    }
    return 15;
}
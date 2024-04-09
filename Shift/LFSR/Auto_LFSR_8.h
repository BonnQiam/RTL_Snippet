#include <bitset>

class Auto_LFSR_8_RTL {
public:
    Auto_LFSR_8_RTL() : initial_state(0b10010001), tap_coefficient(0b11001111), y(0b10010001) {}

    void operate(bool reset) {
        if (!reset)
            y = initial_state;
        else {
            std::bitset<8> y_next;

            /*
            y_next[0] = y[7];
            y_next[1] = tap_coefficient[6] ? (y[0] ^ y[7]) : y[0];
            y_next[2] = tap_coefficient[5] ? (y[1] ^ y[7]) : y[1];
            y_next[3] = tap_coefficient[4] ? (y[2] ^ y[7]) : y[2];
            y_next[4] = tap_coefficient[3] ? (y[3] ^ y[7]) : y[3];
            y_next[5] = tap_coefficient[2] ? (y[4] ^ y[7]) : y[4];
            y_next[6] = tap_coefficient[1] ? (y[5] ^ y[7]) : y[5];
            y_next[7] = tap_coefficient[0] ? (y[6] ^ y[7]) : y[6];
            */

            
            y_next[7] = y[0];
            y_next[6] = tap_coefficient[1] ? (y[7] ^ y[0]) : y[7];
            y_next[5] = tap_coefficient[2] ? (y[6] ^ y[0]) : y[6];
            y_next[4] = tap_coefficient[3] ? (y[5] ^ y[0]) : y[5];
            y_next[3] = tap_coefficient[4] ? (y[4] ^ y[0]) : y[4];
            y_next[2] = tap_coefficient[5] ? (y[3] ^ y[0]) : y[3];
            y_next[1] = tap_coefficient[6] ? (y[2] ^ y[0]) : y[2];
            y_next[0] = tap_coefficient[7] ? (y[1] ^ y[0]) : y[1];
            
            y = y_next;
        }
    }

    unsigned char get_output() const {
        return y.to_ulong();
    }
private:
    std::bitset<8> initial_state;//  indexed from 0 to 7, MSB is 7
    std::bitset<8> tap_coefficient;
    std::bitset<8> y;
};

class Auto_LFSR_8_ALGO {
public:
    Auto_LFSR_8_ALGO() : initial_state(0b10010001), tap_coefficient(0b11001111), y(0b10010001) {}

    void operate(bool reset) {
        if (!reset)
            y = initial_state;
        else {
            std::bitset<8> y_next;

            for (int cell_ptr = 6; cell_ptr >= 0; --cell_ptr) {
                if (tap_coefficient[8 - cell_ptr - 1] == 1)
                    y_next[cell_ptr] = y[cell_ptr + 1] ^ y[0];
                else
                    y_next[cell_ptr] = y[cell_ptr + 1];
            }
            y_next[7] = y[0];
            y = y_next;
        }
    }

    unsigned char get_output() const {
        return y.to_ulong();
    }

private:
    std::bitset<8> initial_state;
    std::bitset<8> tap_coefficient;
    std::bitset<8> y;
};
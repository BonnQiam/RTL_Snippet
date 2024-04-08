// C++ reference model of a 4-bit shift register
class ShiftRegister {
private:
    unsigned char register_;

public:
    ShiftRegister() : register_(0) {}

    void shiftLeft(unsigned char in) {
        register_ = (register_ << 1) | (in & 0x01);
    }

    void shiftRight(unsigned char in) {
        register_ = (register_ >> 1) | ((in & 0x01) << 3);
    }

    unsigned char get() const {
        return register_ & 0x0F; // Only return the 4 least significant bits
    }
};

#include <cstdint>
// C++ reference model of a 8-bit shift register
class Varshift_n {
public:
    static const int n = 8;
    uint8_t out;

    Varshift_n() : out(0) {}

    void reset() {
        out = 0;
    }

    void shift(uint8_t sh_amount, uint8_t sin) {
        uint16_t next_width = (out << 3) | sin;// next_width is 11 bits wide, 8 bits for out and 3 bits for sin
        next_width >>= (3 - sh_amount);// shift right by 3 - sh_amount
        out = next_width & ((1 << n) - 1);// mask out the 8 bits, ((1 << n) - 1) is 8 bits wide
    }

    uint8_t get() const {
        return out;
    }
};

class LRL_Shift_Register_n {
public:
    LRL_Shift_Register_n() : out(0) {}

    void operate(int rst, int left, int right, int load, int sin, unsigned char in) {
        if (rst) {
            out = 0; // Reset
        } else if (left) {
            out = (out << 1) | sin; // Left shift
        } else if (right) {
            out = (out >> 1) | (sin << 3); // Right shift
        } else if (load) {
            out = in;
        }
    }

    unsigned char get_output() const {
        return out & 0x0F; // Only return the 4 least significant bits
    }

private:
    unsigned char out;
};

class Universal_shift_reg {
public:
    Universal_shift_reg() : Data_Out(0) {}

    void operate(
        int rst, int s1, int s0, 
        unsigned char Data_In, int MSB_In, int LSB_In) 
    {
        if (rst) {
            Data_Out = 0; // Reset
        } else {
            switch ((s1 << 1) | s0) {
                case 0: // Hold
                    Data_Out = Data_Out;
                    break;
                case 1: //Serial shift from MSB: {MSB_In, Data_Out[3:1]};
                    Data_Out = (MSB_In << 3) | (Data_Out >> 1);
                    break;
                case 2: // Serial shift from LSB: {Data_Out[2: 0], LSB_In}
                    Data_Out = (Data_Out << 1) | LSB_In;
                    break;
                case 3: // Parallel Load
                    Data_Out = Data_In;
                    break;
            }
        }
    }

    unsigned char get_output() const {
        return Data_Out & 0x0F; // Only return the 4 least significant bits
    }

    bool get_MSB_output() const {
        return (Data_Out & 0x0F) & 0x08;// get the MSB
    }

    bool get_LSB_output() const {
        return (Data_Out & 0x0F) & 0x01;// get the LSB
    }

private:
    unsigned char Data_Out;
};
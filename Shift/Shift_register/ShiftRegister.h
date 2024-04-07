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
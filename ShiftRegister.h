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
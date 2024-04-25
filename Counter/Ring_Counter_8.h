#include <bitset>

class Ring_Counter_8 {
private:
    std::bitset<8> count;

public:
    Ring_Counter_8() : count(0) {}

    void update(bool enable, bool reset) {
        if (reset) {
            count = 0b00000001;
        } else if (enable) {
            bool bit7 = count[7];
            count <<= 1;
            count[0] = bit7;
        }
    }

    unsigned int get_count() {
        return count.to_ulong();
    }
};
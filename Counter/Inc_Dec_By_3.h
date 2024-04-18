#include <bitset>

class Inc_Dec_By_3 {
    private:
        std::bitset<8> out;

    public:
        Inc_Dec_By_3() {}

        void update(bool rst, bool inc, bool dec) {
            if (rst) {
                out = 0;
            } else if (inc) {
                out = std::bitset<8>(out.to_ulong() + 3);
            } else if (dec) {
                out = std::bitset<8>(out.to_ulong() - 3);
            } else {
                out = out;
            }
        }

        unsigned int get_out() {
            return out.to_ulong();
        }
};
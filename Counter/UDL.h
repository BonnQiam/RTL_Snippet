#include <bitset>

class UDL_Counter_n {
    private:
        std::bitset<4> out;
        int n;

    public:
        UDL_Counter_n(int n) : n(n) {}

        void update(bool rst, bool up, bool down, bool load, std::bitset<4> in) {
            if (rst) {
                out = 0;
            } else if (up) {
                out = out.to_ulong() + 1;
            } else if (down) {
                out = out.to_ulong() - 1;
            } else if (load) {
                out = in;
            } else {
                out = out;
            }
        }

        unsigned int get_out() {
            return out.to_ullong();
        }
};
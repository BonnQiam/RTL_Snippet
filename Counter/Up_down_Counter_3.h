#include <bitset>

class Up_down_Counter_3 {
    private:
        std::bitset<3> out;

    public:
        Up_down_Counter_3() {}

        void update(bool rst, bool load, bool counter_on, bool up, std::bitset<3> in) {
            if (rst) {
                out = 0;
            } else if (load){
                out = in;
            }
            else if (counter_on) {
                if(up){
                    out = std::bitset<3>(out.to_ulong() + 1);
                }
                else{
                    out = std::bitset<3>(out.to_ulong() - 1);
                }
            }
        }

        unsigned int get_out() {
            return out.to_ulong();
        }
};
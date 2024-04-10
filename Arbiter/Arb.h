#include <bitset>

class Arb_4_LSB {
public:
    std::bitset<4> r;
    std::bitset<4> g;

    Arb_4_LSB(std::bitset<4> r) : r(r){
        if (r[0]) {
            g = std::bitset<4>(0b0001);
        } else if (r[1]) {
            g = std::bitset<4>(0b0010);
        } else if (r[2]) {
            g = std::bitset<4>(0b0100);
        } else if (r[3]) {
            g = std::bitset<4>(0b1000);
        } else {
            g = std::bitset<4>(0b0000);
        }
    }

    unsigned int get_g() {
        return g.to_ulong();
    }
};

#include <bitset>

template<size_t n>
class Arb_n_LSB {
public:
    std::bitset<n> r;
    std::bitset<n> g;

    Arb_n_LSB(std::bitset<n> r) : r(r){
        std::bitset<n> c;
        c[0] = 1;
        for (size_t i = 1; i < n; ++i) {
            c[i] = ~r[i-1] & c[i-1];
        }
        g = r & c;
    }

    unsigned int get_g() {
        return g.to_ulong();
    }
};

template<size_t n>
class Arb_n_MSB {
public:
    std::bitset<n> r;
    std::bitset<n> g;

    Arb_n_MSB(std::bitset<n> r) : r(r){
        std::bitset<n> c;
        c[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            c[i] = ~r[i+1] & c[i+1];
        }
        g = r & c;
    }

    unsigned int get_g() {
        return g.to_ulong();
    }
};
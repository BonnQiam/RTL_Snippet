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

#include <cmath>
template<size_t n>
class Arb_n_Input {
public:
    std::bitset<n> r;
    std::bitset<n> g;
    int shift_right_bit;

    Arb_n_Input(std::bitset<n> r, int base) : r(r){
        shift_right_bit = std::log2(base);

        // circular shift right r by shift_right_bit bits
        std::bitset<n> r_shifted = (r >> shift_right_bit) | (r << (n - shift_right_bit));

        Arb_n_LSB arb(r_shifted);

        g = arb.g;
        // circular shift left g by shift_right_bit bits
        g = (g << shift_right_bit) | (g >> (n - shift_right_bit));
    }

    unsigned int get_g() {
        return g.to_ulong();
    }
};


// Here is a C++ reference model for the round robin arbiter. This model uses a queue to simulate the round robin behavior. When a request is granted, it is removed from the front of the queue and added to the back, ensuring that all requests get serviced in a round robin manner.

#include <queue>

template<size_t n>
class RoundRobinArbiter {
public:
    RoundRobinArbiter(){
        for (size_t i = 0; i < n; ++i) {
            queue.push(i);
        }
    }

    void reset() {
        while (!queue.empty()) {
            queue.pop();
        }
        for (size_t i = 0; i < n; ++i) {
            queue.push(i);
        }
    }

    void update(std::bitset<n> req_input) {
        gnt.reset();
        req = req_input;

        if (!queue.empty()) {
            int index = queue.front();
            if (req[index]) {
                gnt.set(index);
                queue.pop();
                queue.push(index);
            }
        }
    }

    unsigned int get_gnt() {
        return gnt.to_ulong();
    }

private:
    std::bitset<n> req;
    std::bitset<n> gnt;
    std::queue<int> queue;
};
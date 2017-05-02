#include <iostream>

#include "Pack_bool.hpp"

int main() {
    int NUMBER_OF_BITS = 64;
    Pack_bool pb(NUMBER_OF_BITS);
    pb.set_all_false();
    // Set odd bits.
    for (int i = 1; i < NUMBER_OF_BITS; i += 2) {
        pb.set_bit(i);
    }
    for (int i = 0; i < NUMBER_OF_BITS; ++i) {
        std::cout << pb.get_bit(i) << " ";
    }
    std::cout << std::endl;

    int NEW_NUMBER_OF_BITS = 7;
    pb.resize(NEW_NUMBER_OF_BITS);
    for (int i = 0; i < NEW_NUMBER_OF_BITS; ++i) {
        std::cout << pb.get_bit(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}

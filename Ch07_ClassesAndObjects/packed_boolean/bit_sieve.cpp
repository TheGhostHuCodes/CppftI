#include <array>
#include <iostream>

#include "Pack_bool.hpp"

void process_prime(Pack_bool& p, int max_n, int n);

int main() {
    int min_n = 0;
    int max_n = 0;
    std::cout << "Calculate primes from what number to what number? ";
    std::cin >> min_n >> max_n;
    auto prime_candidates = Pack_bool(max_n + 1);
    prime_candidates.set_all_true();

    for (int i = 2; i <= max_n; ++i) {
        if (prime_candidates.get_bit(i)) {
            process_prime(prime_candidates, max_n, i);
        }
    }
    int primes_found = 0;
    for (int i = min_n; i <= max_n; ++i) {
        if (prime_candidates.get_bit(i)) {
            std::cout << i << "\t";
            ++primes_found;
        }
    }
    std::cout << std::endl;
    std::cout << "Primes found: " << primes_found << std::endl;
    return 0;
}

// Flag all the elements in the packed boolean (p) that correspond to a
// multiple of n as false.
void process_prime(Pack_bool& p, int max_n, int n) {
    for (int i = n + n; i <= max_n; i += n) {
        p.clear_bit(i);
    }
}

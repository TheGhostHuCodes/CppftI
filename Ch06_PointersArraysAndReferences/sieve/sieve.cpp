#include <array>
#include <iostream>

void process_prime(bool* p, int max_n, int n);

int main() {
    int min_n = 0;
    int max_n = 0;
    std::cout << "Calculate primes from what number to what number? ";
    std::cin >> min_n >> max_n;
    bool* p = new bool[max_n + 1];
    for (int i = 2; i <= max_n; ++i) {
        p[i] = true;
    }

    for (int i = 2; i <= max_n; ++i) {
        if (p[i]) {
            process_prime(p, max_n, i);
        }
    }
    int primes_found = 0;
    for (int i = min_n; i <= max_n; ++i) {
        if (p[i]) {
            std::cout << i << "\t";
            ++primes_found;
        }
    }
    std::cout << std::endl;
    std::cout << "Primes found: " << primes_found << std::endl;
    delete[] p;
    return 0;
}

// Flag all the elements in the boolean array (p) that correspond to a
// multiple of n as false.
void process_prime(bool* p, int max_n, int n) {
    for (int i = n + n; i <= max_n; i += n) {
        p[i] = false;
    }
}

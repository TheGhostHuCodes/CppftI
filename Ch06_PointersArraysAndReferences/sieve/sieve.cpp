#include <iostream>

void process_prime(bool* p, int max_n, int n);

int main() {
    int max_n = 0;
    std::cout << "Calculate primes up to what number? ";
    std::cin >> max_n;
    bool* p = new bool[max_n + 1];
    for (int i = 2; i <= max_n; ++i) {
        p[i] = true;
    }

    for (int i = 2; i <= max_n; ++i) {
        if (p[i]) {
            process_prime(p, max_n, i);
        }
    }
    std::cout << std::endl;
    delete[] p;
    return 0;
}

// Print the number n passed to the function, then flag all the elements in
// the boolean array (p) as false.
void process_prime(bool* p, int max_n, int n) {
    std::cout << n << "\t";
    for (int i = n + n; i <= max_n; i += n) {
        p[i] = false;
    }
}

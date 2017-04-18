#include <iostream>

int main() {
    std::cout << std::endl;
    int n = 0;
    int a = 1;
    int b = 1;
    int current = 0;
    std::cout << "How many Fibonacci numbers to generate?";
    std::cin >> n;
    std::cout.precision(15);
    while (n > 0) {
        current = a + b;
        b = a;
        a = current;
        std::cout << current << "\t";
        std::cout << "ratio = " << a / static_cast<double>(b) << std::endl;
        --n;
    }
    std::cout << std::endl;
    return 0;
}

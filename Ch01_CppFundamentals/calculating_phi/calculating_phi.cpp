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
    int i = 0;
    while (i < n) {
        current = a + b;
        b = a;
        a = current;
        ++i;
    }
    std::cout << n << "th Fibonacci number: " << current << std::endl;
    std::cout << "ratio = " << a / static_cast<double>(b) << std::endl;
    std::cout << std::endl;
    return 0;
}

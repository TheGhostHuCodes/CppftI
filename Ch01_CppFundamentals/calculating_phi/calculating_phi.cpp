#include <iostream>
#include <limits>

int main() {
    std::cout << std::endl;
    int n = 0;
    int a = 0;
    int b = 1;
    int current = 0;
    do {
        std::cout << "How many Fibonacci numbers to generate?" << std::endl;
        std::cout << "Enter an integer greater than 0: ";
        std::cin >> n;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    } while (n <= 0);
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

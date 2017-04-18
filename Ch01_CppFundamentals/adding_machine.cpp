#include <iostream>

int main() {
    int sum = 0;
    int n = 1;
    std::cout << "Enter a list of numbers, terminated with 0 or non-digit."
              << std::endl
              << "Enter:";
    while (n != 0) {
        std::cin >> n;
        if (!std::cin) {
            n = 0;
        }
        sum = sum + n;
    }

    std::cout << "Total is: " << sum << std::endl;
    return 0;
}

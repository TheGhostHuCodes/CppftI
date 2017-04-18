#include <iostream>

int main() {
    double sum = 0.0;
    double n = 1.0;
    std::cout
        << "Enter a list of numbers, terminated with a non-digit character."
        << std::endl
        << "Enter:";
    do {
        std::cin >> n;
        if (!std::cin) {
            break;
        }
        sum = sum + n;
    } while (std::cin);

    std::cout << "Total is: " << sum << std::endl;
    return 0;
}

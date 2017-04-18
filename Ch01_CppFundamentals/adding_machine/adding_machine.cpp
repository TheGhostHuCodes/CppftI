#include <iostream>

int main() {
    double sum = 0.0;
    double n = 1.0;
    int cnt = 0;
    std::cout
        << "Enter a list of numbers, terminated with a non-digit character."
        << std::endl
        << "Enter:";
    do {
        std::cin >> n;
        if (!std::cin) {
            break;
        }
        cnt += 1;
        sum = sum + n;
    } while (std::cin);

    std::cout << "Total is: " << sum << std::endl;
    std::cout << "Number of numbers: " << cnt << std::endl;
    std::cout << "Average is: " << sum / cnt << std::endl;
    return 0;
}

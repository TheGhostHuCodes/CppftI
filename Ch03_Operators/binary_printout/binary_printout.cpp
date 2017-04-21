#include <iostream>

int main() {
    int n = 0;
    short test_num = 0;
    unsigned mask = 0x8000;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> test_num;
    while (n++ < sizeof(test_num) * 8) {
        std::cout << ((test_num & mask) != 0);
        mask = mask >> 1;
        if (n % 4 == 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}

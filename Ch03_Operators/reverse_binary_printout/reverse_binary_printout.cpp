#include <iostream>

int main() {
    int test_num = 0;
    unsigned mask = 0x00000001;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> test_num;
    for (int n = 0; n++ < sizeof(test_num) * 8;) {
        std::cout << ((test_num & mask) != 0);
        test_num >>= 1;
        if (n % 4 == 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}

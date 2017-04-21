#include <iostream>

int main() {
    char c = 0;
    int si = 0;
    unsigned int ui = 0;
    double d = 0;
    d = ui = si = c;
    if (typeid(c + c) == typeid(int)) {
        std::cout << "type of (char + char) is int" << std::endl;
    }
    if (typeid(si + ui) == typeid(unsigned)) {
        std::cout << "type of (int + unsigned int) is unsigned" << std::endl;
    }
    if (typeid(si + d) == typeid(double)) {
        std::cout << "type of (int + double) is double" << std::endl;
    }
    return 0;
}

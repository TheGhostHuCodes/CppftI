#include <iostream>

int main() {
    char c = 0;
    int si = 0;
    unsigned int ui = 0;
    double d = 0;
    float f = 0;
    unsigned char uc = 0;
    d = ui = si = c = f;
    if (typeid(c + c) == typeid(int)) {
        std::cout << "type of (char + char) is int" << std::endl;
    }
    if (typeid(si + ui) == typeid(unsigned)) {
        std::cout << "type of (int + unsigned int) is unsigned" << std::endl;
    }
    if (typeid(si + d) == typeid(double)) {
        std::cout << "type of (int + double) is double" << std::endl;
    }
    if (typeid(f + f) == typeid(float)) {
        std::cout << "type of (float + float) is float" << std::endl;
    }
    if (typeid(f * f) == typeid(float)) {
        std::cout << "type of (float * float) is float" << std::endl;
    }
    if (typeid(uc + si) == typeid(int)) {
        std::cout << "type of (unsigned char + int) is int" << std::endl;
    } else if (typeid(uc + si) == typeid(unsigned)) {
        std::cout << "type of (unsigned char + int) is unsigned" << std::endl;
    }
    return 0;
}

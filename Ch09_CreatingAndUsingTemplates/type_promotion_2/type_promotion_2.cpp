#include <iostream>
#include <string>
#include <typeinfo>

template <typename T1, typename T2> std::string return_type(T1 a, T2 b) {
    if (typeid(a + b) == typeid(int)) {
        return "int";
    }
    if (typeid(a + b) == typeid(unsigned)) {
        return "unsigned";
    }
    if (typeid(a + b) == typeid(unsigned long)) {
        return "unsigned long";
    }
    if (typeid(a + b) == typeid(float)) {
        return "float";
    }
    if (typeid(a + b) == typeid(double)) {
        return "double";
    }
    if (typeid(a + b) == typeid(char)) {
        return "char";
    }
    return "other";
};

int main() {
    char ch = 'a';
    int si = 0;
    unsigned ui = 0;
    unsigned long ul = 0;
    double x = 0.0;
    float flt = 0.0F;

    std::cout << "ch + si => " << return_type(ch, si) << std::endl;
    std::cout << "si + si => " << return_type(si, si) << std::endl;
    std::cout << "si + ui => " << return_type(si, ui) << std::endl;
    std::cout << "si + x => " << return_type(si, x) << std::endl;
    std::cout << "x + flt => " << return_type(x, flt) << std::endl;
    std::cout << "ui + ul=> " << return_type(ui, ul) << std::endl;
    return 0;
}
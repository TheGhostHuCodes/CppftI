#include <cstdarg>
#include <iostream>

void print_ints(int n...) {
    va_list(arglist);
    va_start(arglist, n);
    for (int i = 0; i < n; ++i) {
        std::cout << va_arg(arglist, int) << std::endl;
    }
    va_end(arglist);
}

int main() {
    print_ints(4, 1, 2, 3, 4);
    return 0;
}

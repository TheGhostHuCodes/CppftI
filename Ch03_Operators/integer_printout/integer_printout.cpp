#include <iostream>
#include <string>

int main() {
    std::string input_str;
    std::cin >> input_str;
    int expected_string_len = sizeof(short) * 8;

    if (input_str.length() != expected_string_len) {
        std::cout << "Please input binary string with length "
                  << expected_string_len << ", got string with length "
                  << input_str.length() << "." << std::endl;
        return -1;
    }

    short result = 0;
    char input_char;
    for (int i = 0; i < expected_string_len; ++i) {
        input_char = input_str[i];
        result <<= 1;
        if (input_char == '1') {
            result |= 1;
        } else if (input_char != '0') {
            std::cout << "could not process character: " << input_char
                      << " at position: " << i + 1 << std::endl;
            return -1;
        }
    }
    std::cout << result << std::endl;
    return 0;
}

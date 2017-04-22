#include <iostream>
#include <string>

int main() {
    std::string input_str;
    std::getline(std::cin, input_str);
    int expected_processed_chars = sizeof(short) * 8;

    short result = 0;
    int processed_chars = 0;
    int input_len = input_str.length();
    for (int i = 0; i < input_len; ++i) {
        char input_char = input_str[i];
        if (input_char == ' ') {
            continue;
        }
        ++processed_chars;
        result <<= 1;
        if (input_char == '1') {
            result |= 1;
        } else if (input_char != '0') {
            std::cout << "could not process character: " << input_char
                      << " at position: " << i + 1 << std::endl;
            return -1;
        }
    }
    if (processed_chars != expected_processed_chars) {
        std::cout << "Please input binary string with length "
                  << expected_processed_chars << ", got string with length "
                  << processed_chars << "." << std::endl;
        return -1;
    }
    std::cout << result << std::endl;
    return 0;
}

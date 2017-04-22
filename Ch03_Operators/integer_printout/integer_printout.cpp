#include <iostream>
#include <string>

int main() {
    std::string input_str;
    std::getline(std::cin, input_str);
    int expected_processed_chars = sizeof(short) * 8;

    short result = 0;
    int processed_chars = 0;
    for (char ch : input_str) {
        if (ch == ' ') {
            continue;
        }
        ++processed_chars;
        result <<= 1;
        if (ch == '1') {
            result |= 1;
        } else if (ch != '0') {
            std::cout << "could not process character: " << ch
                      << " at position: " << (&ch - &input_str[0]) + 1
                      << std::endl;
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

#include "Pack_bool.hpp"
#include <algorithm>
#include <sstream>
#include <stdexcept>

Pack_bool::Pack_bool(int bit_length) {
    this->bit_length = bit_length;
    // Divide max by 8 and round up to get number of bytes to allocate.
    bytes_to_allocate = (this->bit_length + 7) / 8;
    data = new unsigned char[bytes_to_allocate];
}

Pack_bool::~Pack_bool() { delete[] data; }

// Find the target bit and use bitwise OR to turn it on.
void Pack_bool::set_bit(int n) {
    check_range(n);
    int i = n / 8;
    int j = n % 8;
    data[i] |= (0x01 << j);
}

// Find the target bit and use bitwise negation and bitwise AND to set it to
// zero.
void Pack_bool::clear_bit(int n) {
    check_range(n);
    int i = n / 8;
    int j = n % 8;
    data[i] &= ~(0x01 << j);
}

// Find the target bit and use bitwise AND to get its value.
bool Pack_bool::get_bit(int n) {
    check_range(n);
    int i = n / 8;
    int j = n % 8;
    return (data[i] & (0x01 << j)) != 0;
}

void Pack_bool::set_all_true() {
    for (int i = 0; i < bytes_to_allocate; ++i) {
        data[i] = 0xff;
    }
}

void Pack_bool::set_all_false() {
    for (int i = 0; i < bytes_to_allocate; ++i) {
        data[i] = 0x00;
    }
}

void Pack_bool::resize(int new_bit_length) {
    if (bit_length == new_bit_length) {
        return;
    }

    int bytes_to_reallocate = (new_bit_length + 7) / 8;
    auto new_data = new unsigned char[bytes_to_reallocate];

    // Zero everything out first.
    for (int i = 0; i < bytes_to_reallocate; ++i) {
        new_data[i] = 0x00;
    }

    // Copy over data to new packed bool data array.
    int end = std::min(bit_length, new_bit_length);
    for (int n = 0; n < end; ++n) {
        if (get_bit(n)) {
            int i = n / 8;
            int j = n % 8;
            new_data[i] |= (0x01 << j);
        }
    }

    delete[] data;
    data = new_data;
    bit_length = new_bit_length;
}

void Pack_bool::check_range(int n) {
    if (n < 0 || n >= bit_length) {
        std::stringstream message;
        message << "Requested index " << n << " is out of range [0," << n - 1
                << "]";
        throw std::out_of_range(message.str());
    }
}

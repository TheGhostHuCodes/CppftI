#include "Pack_bool.hpp"

Pack_bool::Pack_bool(int bit_length) {
    this->bit_length = bit_length;
    // Divide max by 8 and round up to get number of bytes to allocate.
    bytes_to_allocate = (this->bit_length + 7) / 8;
    data = new unsigned char[bytes_to_allocate];
}

Pack_bool::~Pack_bool() { delete[] data; }

// Find the target bit and use bitwise OR to turn it on.
void Pack_bool::set_bit(int n) {
    int i = n / 8;
    int j = n % 8;
    data[i] |= (0x01 << j);
}

// Find the target bit and use bitwise negation and bitwise AND to set it to
// zero.
void Pack_bool::clear_bit(int n) {
    int i = n / 8;
    int j = n % 8;
    data[i] &= ~(0x01 << j);
}

// Find the target bit and use bitwise AND to get its value.
bool Pack_bool::get_bit(int n) {
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

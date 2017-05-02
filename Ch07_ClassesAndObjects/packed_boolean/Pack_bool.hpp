#pragma once
// Packed Boolean class: creates a virtual Boolean array of dynamic length,
// storing each Boolean in one bit.

class Pack_bool {
  private:
    int bit_length;
    int bytes_to_allocate;
    unsigned char* data;
    void check_range(int n);

  public:
    Pack_bool(int bit_length);
    ~Pack_bool();
    void set_bit(int n);
    void clear_bit(int n);
    bool get_bit(int n);
    void set_all_true();
    void set_all_false();
};

#pragma once
// Packed Boolean class: creates a virtual Boolean array of dynamic length,
// storing each Boolean in one bit.

class Pack_bool {
  private:
    class bit_ref;
    int bit_length;
    int bytes_to_allocate;
    unsigned char* data;
    void check_range(int n) const;

  public:
    Pack_bool(int bit_length);
    ~Pack_bool();
    bit_ref operator[](const int bit_index);
    void set_bit(int n);
    void clear_bit(int n);
    bool get_bit(int n) const;
    void set_all_true();
    void set_all_false();
    void resize(int bit_length);

  private:
    class bit_ref {
      private:
        unsigned char* data;
        unsigned char mask;

      public:
        bit_ref(unsigned char* data_, unsigned char mask_);
        bit_ref& operator=(int n);
        operator bool();
    };
};

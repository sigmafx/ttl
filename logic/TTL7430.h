typedef unsigned short TTL7430_PINS;

#define TTL7430_A   (1 << 0)
#define TTL7430_B   (1 << 1)
#define TTL7430_C   (1 << 2)
#define TTL7430_D   (1 << 3)
#define TTL7430_E   (1 << 4)
#define TTL7430_F   (1 << 5)
#define TTL7430_G   (1 << 6)
#define TTL7430_H   (1 << 7)
#define TTL7430_Y   (1 << 8)
#define TTL7430_IN  (TTL7430_A|TTL7430_B|TTL7430_C|TTL7430_D|TTL7430_E|TTL7430_F|TTL7430_G|TTL7430_H)

#define TTL7430_INIT   0b0000000100000000
#define TTL7430_ACT(p) (TTL7430[(p)&TTL7430_IN])

#define TTL7430_SET_A(p) ((p)|=TTL7430_A)
#define TTL7430_RESET_A(p) ((p)&=~TTL7430_A)
#define TTL7430_SET_B(p) ((p)|=TTL7430_B)
#define TTL7430_RESET_B(p) ((p)&=~TTL7430_B)
#define TTL7430_SET_C(p) ((p)|=TTL7430_C)
#define TTL7430_RESET_C(p) ((p)&=~TTL7430_C)
#define TTL7430_SET_D(p) ((p)|=TTL7430_D)
#define TTL7430_RESET_D(p) ((p)&=~TTL7430_D)
#define TTL7430_SET_E(p) ((p)|=TTL7430_E)
#define TTL7430_RESET_E(p) ((p)&=~TTL7430_E)
#define TTL7430_SET_F(p) ((p)|=TTL7430_F)
#define TTL7430_RESET_F(p) ((p)&=~TTL7430_F)
#define TTL7430_SET_G(p) ((p)|=TTL7430_G)
#define TTL7430_RESET_G(p) ((p)&=~TTL7430_G)
#define TTL7430_SET_H(p) ((p)|=TTL7430_H)
#define TTL7430_RESET_H(p) ((p)&=~TTL7430_H)

#define TTL7430_GET_Y(p) ((p)&TTL7430_Y)

TTL7430_PINS TTL7430[] = {
    0b0000000100000000,
    0b0000000100000001,
    0b0000000100000010,
    0b0000000100000011,
    0b0000000100000100,
    0b0000000100000101,
    0b0000000100000110,
    0b0000000100000111,
    0b0000000100001000,
    0b0000000100001001,
    0b0000000100001010,
    0b0000000100001011,
    0b0000000100001100,
    0b0000000100001101,
    0b0000000100001110,
    0b0000000100001111,
    0b0000000100010000,
    0b0000000100010001,
    0b0000000100010010,
    0b0000000100010011,
    0b0000000100010100,
    0b0000000100010101,
    0b0000000100010110,
    0b0000000100010111,
    0b0000000100011000,
    0b0000000100011001,
    0b0000000100011010,
    0b0000000100011011,
    0b0000000100011100,
    0b0000000100011101,
    0b0000000100011110,
    0b0000000100011111,
    0b0000000100100000,
    0b0000000100100001,
    0b0000000100100010,
    0b0000000100100011,
    0b0000000100100100,
    0b0000000100100101,
    0b0000000100100110,
    0b0000000100100111,
    0b0000000100101000,
    0b0000000100101001,
    0b0000000100101010,
    0b0000000100101011,
    0b0000000100101100,
    0b0000000100101101,
    0b0000000100101110,
    0b0000000100101111,
    0b0000000100110000,
    0b0000000100110001,
    0b0000000100110010,
    0b0000000100110011,
    0b0000000100110100,
    0b0000000100110101,
    0b0000000100110110,
    0b0000000100110111,
    0b0000000100111000,
    0b0000000100111001,
    0b0000000100111010,
    0b0000000100111011,
    0b0000000100111100,
    0b0000000100111101,
    0b0000000100111110,
    0b0000000100111111,
    0b0000000101000000,
    0b0000000101000001,
    0b0000000101000010,
    0b0000000101000011,
    0b0000000101000100,
    0b0000000101000101,
    0b0000000101000110,
    0b0000000101000111,
    0b0000000101001000,
    0b0000000101001001,
    0b0000000101001010,
    0b0000000101001011,
    0b0000000101001100,
    0b0000000101001101,
    0b0000000101001110,
    0b0000000101001111,
    0b0000000101010000,
    0b0000000101010001,
    0b0000000101010010,
    0b0000000101010011,
    0b0000000101010100,
    0b0000000101010101,
    0b0000000101010110,
    0b0000000101010111,
    0b0000000101011000,
    0b0000000101011001,
    0b0000000101011010,
    0b0000000101011011,
    0b0000000101011100,
    0b0000000101011101,
    0b0000000101011110,
    0b0000000101011111,
    0b0000000101100000,
    0b0000000101100001,
    0b0000000101100010,
    0b0000000101100011,
    0b0000000101100100,
    0b0000000101100101,
    0b0000000101100110,
    0b0000000101100111,
    0b0000000101101000,
    0b0000000101101001,
    0b0000000101101010,
    0b0000000101101011,
    0b0000000101101100,
    0b0000000101101101,
    0b0000000101101110,
    0b0000000101101111,
    0b0000000101110000,
    0b0000000101110001,
    0b0000000101110010,
    0b0000000101110011,
    0b0000000101110100,
    0b0000000101110101,
    0b0000000101110110,
    0b0000000101110111,
    0b0000000101111000,
    0b0000000101111001,
    0b0000000101111010,
    0b0000000101111011,
    0b0000000101111100,
    0b0000000101111101,
    0b0000000101111110,
    0b0000000101111111,
    0b0000000110000000,
    0b0000000110000001,
    0b0000000110000010,
    0b0000000110000011,
    0b0000000110000100,
    0b0000000110000101,
    0b0000000110000110,
    0b0000000110000111,
    0b0000000110001000,
    0b0000000110001001,
    0b0000000110001010,
    0b0000000110001011,
    0b0000000110001100,
    0b0000000110001101,
    0b0000000110001110,
    0b0000000110001111,
    0b0000000110010000,
    0b0000000110010001,
    0b0000000110010010,
    0b0000000110010011,
    0b0000000110010100,
    0b0000000110010101,
    0b0000000110010110,
    0b0000000110010111,
    0b0000000110011000,
    0b0000000110011001,
    0b0000000110011010,
    0b0000000110011011,
    0b0000000110011100,
    0b0000000110011101,
    0b0000000110011110,
    0b0000000110011111,
    0b0000000110100000,
    0b0000000110100001,
    0b0000000110100010,
    0b0000000110100011,
    0b0000000110100100,
    0b0000000110100101,
    0b0000000110100110,
    0b0000000110100111,
    0b0000000110101000,
    0b0000000110101001,
    0b0000000110101010,
    0b0000000110101011,
    0b0000000110101100,
    0b0000000110101101,
    0b0000000110101110,
    0b0000000110101111,
    0b0000000110110000,
    0b0000000110110001,
    0b0000000110110010,
    0b0000000110110011,
    0b0000000110110100,
    0b0000000110110101,
    0b0000000110110110,
    0b0000000110110111,
    0b0000000110111000,
    0b0000000110111001,
    0b0000000110111010,
    0b0000000110111011,
    0b0000000110111100,
    0b0000000110111101,
    0b0000000110111110,
    0b0000000110111111,
    0b0000000111000000,
    0b0000000111000001,
    0b0000000111000010,
    0b0000000111000011,
    0b0000000111000100,
    0b0000000111000101,
    0b0000000111000110,
    0b0000000111000111,
    0b0000000111001000,
    0b0000000111001001,
    0b0000000111001010,
    0b0000000111001011,
    0b0000000111001100,
    0b0000000111001101,
    0b0000000111001110,
    0b0000000111001111,
    0b0000000111010000,
    0b0000000111010001,
    0b0000000111010010,
    0b0000000111010011,
    0b0000000111010100,
    0b0000000111010101,
    0b0000000111010110,
    0b0000000111010111,
    0b0000000111011000,
    0b0000000111011001,
    0b0000000111011010,
    0b0000000111011011,
    0b0000000111011100,
    0b0000000111011101,
    0b0000000111011110,
    0b0000000111011111,
    0b0000000111100000,
    0b0000000111100001,
    0b0000000111100010,
    0b0000000111100011,
    0b0000000111100100,
    0b0000000111100101,
    0b0000000111100110,
    0b0000000111100111,
    0b0000000111101000,
    0b0000000111101001,
    0b0000000111101010,
    0b0000000111101011,
    0b0000000111101100,
    0b0000000111101101,
    0b0000000111101110,
    0b0000000111101111,
    0b0000000111110000,
    0b0000000111110001,
    0b0000000111110010,
    0b0000000111110011,
    0b0000000111110100,
    0b0000000111110101,
    0b0000000111110110,
    0b0000000111110111,
    0b0000000111111000,
    0b0000000111111001,
    0b0000000111111010,
    0b0000000111111011,
    0b0000000111111100,
    0b0000000111111101,
    0b0000000111111110,
    0b0000000011111111
};
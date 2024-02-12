/* J-K FLIP-FLOP -VE CLOCK,  CLR LO */

typedef unsigned char TTL74107_PINS;

#define TTL74107_CLK    (1 << 0)
#define TTL74107_J      (1 << 1)
#define TTL74107_K      (1 << 2)
#define TTL74107_CLR    (1 << 3)
#define TTL74107_CLKPRE (1 << 4)
#define TTL74107_Q      (1 << 5)
#define TTL74107_QQ     (1 << 6)
#define TTL74107_IN     (TTL74107_CLK|TTL74107_J|TTL74107_K|TTL74107_CLR|TTL74107_CLKPRE|TTL74107_Q)

#define TTL74107_INIT   TTL74107_CLR
#define TTL74107_ACT(p) (TTL74107[(p)&TTL74107_IN])

#define TTL74107_SET_CLK(p) ((p)|=TTL74107_CLK)
#define TTL74107_RESET_CLK(p) ((p)&=~TTL74107_CLK)
#define TTL74107_PUT_CLK(p,t) ((p)&=~TTL74107_CLK,(p)|=((t)?TTL74107_CLK:0))
#define TTL74107_SET_J(p) ((p)|=TTL74107_J)
#define TTL74107_RESET_J(p) ((p)&=~TTL74107_J)
#define TTL74107_PUT_J(p,t) ((p)&=~TTL74107_J,(p)|=((t)?TTL74107_J:0))
#define TTL74107_SET_K(p) ((p)|=TTL74107_K)
#define TTL74107_RESET_K(p) ((p)&=~TTL74107_K)
#define TTL74107_PUT_K(p,t) ((p)&=~TTL74107_K,(p)|=((t)?TTL74107_K:0))
#define TTL74107_SET_CLR(p) ((p)|=TTL74107_CLR)
#define TTL74107_RESET_CLR(p) ((p)&=~TTL74107_CLR)

#define TTL74107_GET_Q(p) ((p)&TTL74107_Q)
#define TTL74107_GET_QQ(p) ((p)&TTL74107_QQ)

TTL74107_PINS TTL74107[] = {
    0b01000000,
    0b01010001,
    0b01000010,
    0b01010011,
    0b01000100,
    0b01010101,
    0b01000110,
    0b01010111,
    0b01001000,
    0b01011001,
    0b01001010,
    0b01011011,
    0b01001100,
    0b01011101,
    0b01001110,
    0b01011111,
    0b01000000,
    0b01010001,
    0b01000010,
    0b01010011,
    0b01000100,
    0b01010101,
    0b01000110,
    0b01010111,
    0b01001000,
    0b01011001,
    0b00101010,
    0b01011011,
    0b01001100,
    0b01011101,
    0b00101110,
    0b01011111,
    0b01000000,
    0b01010001,
    0b01000010,
    0b01010011,
    0b01000100,
    0b01010101,
    0b01000110,
    0b01010111,
    0b00101000,
    0b00111001,
    0b00101010,
    0b00111011,
    0b00101100,
    0b00111101,
    0b00101110,
    0b00111111,
    0b01000000,
    0b01010001,
    0b01000010,
    0b01010011,
    0b01000100,
    0b01010101,
    0b01000110,
    0b01010111,
    0b00101000,
    0b00111001,
    0b00101010,
    0b00111011,
    0b01001100,
    0b00111101,
    0b01001110,
    0b00111111,
};

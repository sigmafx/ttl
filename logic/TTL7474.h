/* D-TYPE FLIP-FLOP +VE CLOCK */
typedef unsigned char TTL7474_PINS;

#define TTL7474_CLK     (1 << 0)
#define TTL7474_D       (1 << 1)
#define TTL7474_PRE     (1 << 2)
#define TTL7474_CLR     (1 << 3)
#define TTL7474_CLKPRE  (1 << 4)
#define TTL7474_Q       (1 << 5)
#define TTL7474_QQ      (1 << 6)
#define TTL7474_IN      (TTL7474_CLK|TTL7474_D|TTL7474_PRE|TTL7474_CLR|TTL7474_CLKPRE|TTL7474_Q)

#define TTL7474_INIT    TTL7474_PRE|TTL7474_CLR
#define TTL7474_ACT(p) (TTL7474[(p)&TTL7474_IN])

#define TTL7474_SET_CLK(p) ((p)|=TTL7474_CLK)
#define TTL7474_RESET_CLK(p) ((p)&=~TTL7474_CLK)
#define TTL7474_PUT_CLK(p,t) ((p)&=~TTL7474_CLK,(p)|=(t?TTL7474_CLK:0))
#define TTL7474_SET_D(p) ((p)|=TTL7474_D)
#define TTL7474_RESET_D(p) ((p)&=~TTL7474_D)
#define TTL7474_PUT_D(p,t) ((p)&=~TTL7474_D,(p)|=(t?TTL7474_D:0))
#define TTL7474_SET_PRE(p) ((p)|=TTL7474_PRE)
#define TTL7474_RESET_PRE(p) ((p)&=~TTL7474_PRE)
#define TTL7474_SET_CLR(p) ((p)|=TTL7474_CLR)
#define TTL7474_RESET_CLR(p) ((p)&=~TTL7474_CLR)

#define TTL7474_GET_Q(p) ((p)&TTL7474_Q)
#define TTL7474_GET_QQ(p) ((p)&TTL7474_QQ)

TTL7474_PINS TTL7474[] = {
    0b001100000,
    0b001110001,
    0b001100010,
    0b001110011,
    0b000101000,
    0b000111001,
    0b000101010,
    0b000111011,
    0b001000100,
    0b001010101,
    0b001000110,
    0b001010111,
    0b001001100,
    0b001011101,
    0b001001110,
    0b000111111,
    0b001100000,
    0b001110001,
    0b001100010,
    0b001110011,
    0b000101000,
    0b000111001,
    0b000101010,
    0b000111011,
    0b001000100,
    0b001010101,
    0b001000110,
    0b001010111,
    0b001001100,
    0b001011101,
    0b001001110,
    0b001011111,
    0b001100000,
    0b001110001,
    0b001100010,
    0b001110011,
    0b000101000,
    0b000111001,
    0b000101010,
    0b000111011,
    0b001000100,
    0b001010101,
    0b001000110,
    0b001010111,
    0b000101100,
    0b001011101,
    0b000101110,
    0b000111111,
    0b001100000,
    0b001110001,
    0b001100010,
    0b001110011,
    0b000101000,
    0b000111001,
    0b000101010,
    0b000111011,
    0b001000100,
    0b001010101,
    0b001000110,
    0b001010111,
    0b000101100,
    0b000111101,
    0b000101110,
    0b000111111
};

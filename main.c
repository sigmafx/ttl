#include "logic/TTL7474.h"
#include "logic/TTL7493.h"
#include "logic/TTL74107.h"
#include "logic/TTL7430.h"

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

/*
 Links...
 https://www.arcade-museum.com/manuals-videogames/P/PongSchematic.pdf
 https://www.falstad.com/pong/
*/

bool clock = false;

TTL7474_PINS pins7474_E7 = TTL7474_INIT;
TTL7493_PINS pins7493_F8 = TTL7493_INIT;
TTL7493_PINS pins7493_F9 = TTL7493_INIT;
TTL74107_PINS pins74107_F6 = TTL74107_INIT;
TTL7430_PINS pins7430_F7 = TTL7430_INIT;

#define BYTE_TO_BINARY_PATTERN "0b00000001'%c%c%c%c%c%c%c%c,\n"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 

int main() {
    TTL74107_SET_J(pins74107_F6);
    TTL74107_SET_K(pins74107_F6);

    TTL7430_SET_B(pins7430_F7);
    TTL7430_SET_C(pins7430_F7);
    TTL7430_SET_D(pins7430_F7);

    while(true)
    {
        clock = !clock;
        if(clock)
        {
            TTL7493_SET_CLK(pins7493_F8);
            TTL7474_SET_CLK(pins7474_E7);
        }
        else
        {
            TTL7493_RESET_CLK(pins7493_F8);
            TTL7474_RESET_CLK(pins7474_E7);
        }

        pins7493_F8 = TTL7493_ACT(pins7493_F8);

        if(TTL7493_GET_Q3(pins7493_F8))
            TTL7493_SET_CLK(pins7493_F9);
        else
            TTL7493_RESET_CLK(pins7493_F9);

        pins7493_F9 = TTL7493_ACT(pins7493_F9);

        if(TTL7493_GET_Q3(pins7493_F9))
            TTL74107_SET_CLK(pins74107_F6);
        else
            TTL74107_RESET_CLK(pins74107_F6);

        pins74107_F6 = TTL74107_ACT(pins74107_F6);

        if(TTL74107_GET_Q(pins74107_F6))
            TTL7430_SET_A(pins7430_F7);
        else
            TTL7430_RESET_A(pins7430_F7);

        if(TTL7493_GET_Q2(pins7493_F8))
            TTL7430_SET_E(pins7430_F7);
        else
            TTL7430_RESET_E(pins7430_F7);

        if(TTL7493_GET_Q1(pins7493_F8))
            TTL7430_SET_F(pins7430_F7);
        else
            TTL7430_RESET_F(pins7430_F7);

        if(TTL7493_GET_Q3(pins7493_F9))
            TTL7430_SET_G(pins7430_F7);
        else
            TTL7430_RESET_G(pins7430_F7);

        if(TTL7493_GET_Q2(pins7493_F9))
            TTL7430_SET_H(pins7430_F7);
        else
            TTL7430_RESET_H(pins7430_F7);

        pins7430_F7 = TTL7430_ACT(pins7430_F7);

        if(TTL7430_GET_Y(pins7430_F7))
            TTL7474_SET_D(pins7474_E7);
        else
            TTL7474_RESET_D(pins7474_E7);

        pins7474_E7 = TTL7474_ACT(pins7474_E7);

        if(TTL7474_GET_Q(pins7474_E7))
        {
            TTL74107_SET_CLR(pins74107_F6);
        }
        else
        {
            TTL74107_RESET_CLR(pins74107_F6);
        }

        if(TTL7474_GET_QQ(pins7474_E7))
        {
            TTL7493_SET_CLR1(pins7493_F8);
            TTL7493_SET_CLR2(pins7493_F8);
            TTL7493_SET_CLR1(pins7493_F9);
            TTL7493_SET_CLR2(pins7493_F9);
        }
        else
        {
            TTL7493_RESET_CLR1(pins7493_F8);
            TTL7493_RESET_CLR2(pins7493_F8);
            TTL7493_RESET_CLR1(pins7493_F9);
            TTL7493_RESET_CLR2(pins7493_F9);
        }

        pins74107_F6 = TTL74107_ACT(pins74107_F6);
        pins7493_F8 = TTL7493_ACT(pins7493_F8);
        pins7493_F9 = TTL7493_ACT(pins7493_F9);

        printf("%s: (Reset: %s) %d\n",
            clock ? "H" : "L",
            TTL7474_GET_Q(pins7474_E7) ? "-" : "Y",
            ((pins7493_F8 & 0xF0) >> 4) + (pins7493_F9 & 0xF0) + (TTL74107_GET_Q(pins74107_F6) ? 256 : 0));

        usleep(100000);
    }
    return 0;
}

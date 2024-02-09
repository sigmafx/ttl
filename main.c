#include "logic/TTL7474.h"
#include "logic/TTL7493.h"
#include "logic/TTL74107.h"
#include "logic/TTL7430.h"
#include "logic/TTL7410.h"

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

/*
 Links...
 https://www.pong-story.com/LAWN_TENNIS.pdf
 https://www.arcade-museum.com/manuals-videogames/P/PongSchematic.pdf
 https://www.falstad.com/pong/
*/

bool clock = false;

TTL7410_PINS pins7410_D8 = TTL7410_INIT;
TTL7474_PINS pins7474_E7_1 = TTL7474_INIT;
TTL7474_PINS pins7474_E7_2 = TTL7474_INIT;
TTL74107_PINS pins74107_F6 = TTL74107_INIT;
TTL7430_PINS pins7430_F7 = TTL7430_INIT;
TTL7493_PINS pins7493_F8 = TTL7493_INIT;
TTL7493_PINS pins7493_F9 = TTL7493_INIT;

#define PIN_CLK()       clock
#define PIN_1H()        TTL7493_GET_Q0(pins7493_F8)
#define PIN_2H()        TTL7493_GET_Q1(pins7493_F8)
#define PIN_4H()        TTL7493_GET_Q2(pins7493_F8)
#define PIN_8H()        TTL7493_GET_Q3(pins7493_F8)
#define PIN_16H()       TTL7493_GET_Q0(pins7493_F9)
#define PIN_32H()       TTL7493_GET_Q1(pins7493_F9)
#define PIN_64H()       TTL7493_GET_Q2(pins7493_F9)
#define PIN_128H()      TTL7493_GET_Q3(pins7493_F9)
#define PIN_256H()      TTL74107_GET_Q(pins74107_F6)
#define _PIN_256H()     TTL74107_GET_QQ(pins74107_F6)
#define PIN_HRESET()    TTL7474_GET_QQ(pins7474_E7_2)
#define _PIN_HRESET()   TTL7474_GET_Q(pins7474_E7_2)

int main() {
    /* Hard wire */
    TTL74107_SET_J(pins74107_F6);
    TTL74107_SET_K(pins74107_F6);

    TTL7430_SET_B(pins7430_F7);
    TTL7430_SET_C(pins7430_F7);
    TTL7430_SET_D(pins7430_F7);

    while(true)
    {
        /*-------*/
        /* HSYNC */
        /*-------*/

        /* F8 */
        TTL7493_PUT_CLK(pins7493_F8,clock);
        pins7493_F8 = TTL7493_ACT(pins7493_F8);

        /* F9 */
        TTL7493_PUT_CLK(pins7493_F9,TTL7493_GET_Q3(pins7493_F8));
        pins7493_F9 = TTL7493_ACT(pins7493_F9);

        /* F6 */
        TTL74107_PUT_CLK(pins74107_F6,PIN_128H());
        pins74107_F6 = TTL74107_ACT(pins74107_F6);

        /* F7 */
        TTL7430_PUT_A(pins7430_F7,PIN_256H());
        TTL7430_PUT_E(pins7430_F7,PIN_4H());
        TTL7430_PUT_F(pins7430_F7,PIN_2H());
        TTL7430_PUT_G(pins7430_F7,TTL7493_GET_Q3(pins7493_F9));
        TTL7430_PUT_H(pins7430_F7,TTL7493_GET_Q2(pins7493_F9));
        pins7430_F7 = TTL7430_ACT(pins7430_F7);

        /* E7 */
        TTL7474_PUT_CLK(pins7474_E7_2,clock);
        TTL7474_PUT_D(pins7474_E7_2,TTL7430_GET_Y(pins7430_F7));
        pins7474_E7_2 = TTL7474_ACT(pins7474_E7_2);

        /* HRESET */
        if(TTL7474_GET_Q(pins7474_E7_2))
        {
            TTL74107_SET_CLR(pins74107_F6);
        }
        else
        {
            TTL74107_RESET_CLR(pins74107_F6);
        }

        if(TTL7474_GET_QQ(pins7474_E7_2))
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

        /*-------*/
        /* VSYNC */
        /*-------*/

        clock = !clock;

        /*--------*/
        /* REPORT */
        /*--------*/
        printf("%s: (Reset: %s) %d\n",
            clock ? "H" : "L",
            TTL7474_GET_Q(pins7474_E7_2) ? "-" : "Y",
            ((pins7493_F8 & 0xF0) >> 4) + (pins7493_F9 & 0xF0) + (PIN_256H() ? 256 : 0));
        usleep(10000);
    }
    return 0;
}

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


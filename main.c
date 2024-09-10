#include "logic/TTL7400.h"
#include "logic/TTL7402.h"
#include "logic/TTL7404.h"
#include "logic/TTL7425.h"
#include "logic/TTL7427.h"
#include "logic/TTL7474.h"
#include "logic/TTL7486.h"
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

TTL7486_PINS pins7486_A4D = TTL7486_INIT;
TTL7410_PINS pins7410_D8C = TTL7410_INIT;
TTL74107_PINS pins74107_D9B = TTL74107_INIT;
TTL7404_PINS pins7404_E4E = TTL7404_INIT;
TTL7404_PINS pins7404_E4F = TTL7404_INIT;
TTL7474_PINS pins7474_E7A = TTL7474_INIT;
TTL7474_PINS pins7474_E7B = TTL7474_INIT;
TTL7493_PINS pins7493_E8 = TTL7493_INIT;
TTL7493_PINS pins7493_E9 = TTL7493_INIT;
TTL7425_PINS pins7425_F2B = TTL7425_INIT;
TTL74107_PINS pins74107_F3B = TTL74107_INIT;
TTL7402_PINS pins7402_F5C = TTL7402_INIT;
TTL7402_PINS pins7402_F5D = TTL7402_INIT;
TTL74107_PINS pins74107_F6B = TTL74107_INIT;
TTL7430_PINS pins7430_F7 = TTL7430_INIT;
TTL7493_PINS pins7493_F8 = TTL7493_INIT;
TTL7493_PINS pins7493_F9 = TTL7493_INIT;
TTL7402_PINS pins7402_G1B = TTL7402_INIT;
TTL7427_PINS pins7427_G2B = TTL7427_INIT;
TTL7400_PINS pins7400_G3B = TTL7400_INIT;
TTL7410_PINS pins7410_G5A = TTL7410_INIT;
TTL7410_PINS pins7410_G5B = TTL7410_INIT;
TTL7400_PINS pins7400_H5A = TTL7400_INIT;
TTL7400_PINS pins7400_H5B = TTL7400_INIT;
TTL7400_PINS pins7400_H5C = TTL7400_INIT;
TTL7400_PINS pins7400_H5D = TTL7400_INIT;

#define PIN_CLK()           clock
#define PIN_1H()            TTL7493_GET_Q0(pins7493_F8)
#define PIN_2H()            TTL7493_GET_Q1(pins7493_F8)
#define PIN_4H()            TTL7493_GET_Q2(pins7493_F8)
#define PIN_8H()            TTL7493_GET_Q3(pins7493_F8)
#define PIN_16H()           TTL7493_GET_Q0(pins7493_F9)
#define PIN_32H()           TTL7493_GET_Q1(pins7493_F9)
#define PIN_64H()           TTL7493_GET_Q2(pins7493_F9)
#define PIN_128H()          TTL7493_GET_Q3(pins7493_F9)
#define PIN_256H()          TTL74107_GET_Q(pins74107_F6B)
#define _PIN_256H()         TTL74107_GET_QQ(pins74107_F6B)
#define PIN_HRESET()        TTL7474_GET_QQ(pins7474_E7B)
#define _PIN_HRESET()       TTL7474_GET_Q(pins7474_E7B)
#define PIN_1V()            TTL7493_GET_Q0(pins7493_E8)
#define PIN_2V()            TTL7493_GET_Q1(pins7493_E8)
#define PIN_4V()            TTL7493_GET_Q2(pins7493_E8)
#define PIN_8V()            TTL7493_GET_Q3(pins7493_E8)
#define PIN_16V()           TTL7493_GET_Q0(pins7493_E9)
#define PIN_32V()           TTL7493_GET_Q1(pins7493_E9)
#define PIN_64V()           TTL7493_GET_Q2(pins7493_E9)
#define PIN_128V()          TTL7493_GET_Q3(pins7493_E9)
#define PIN_256V()          TTL74107_GET_Q(pins74107_D9B)
#define _PIN_256V()         TTL74107_GET_QQ(pins74107_D9B)
#define PIN_HBLANKING()     TTL7400_GET_Y(pins7400_H5C)
#define _PIN_HBLANKING()    TTL7400_GET_Y(pins7400_H5B)
#define _PIN_HSYNC()        TTL7400_GET_Y(pins7400_H5D)
#define PIN_VBLANK()        TTL7402_GET_Y(pins7402_F5D)
#define _PIN_VBLANK()       TTL7402_GET_Y(pins7402_F5C)
#define PIN_VRESET()        TTL7474_GET_QQ(pins7474_E7A)
#define _PIN_VSYNC()        TTL7410_GET_Y(pins7410_G5A)
#define SYNC()              TTL7404_GET_Y(pins7404_E4E)
#define NET()               TTL7427_GET_Y(pins7427_G2B)

int main() {
    char szIdxClock[3 + 1];

    /* Hard wire */
    TTL74107_SET_J(pins74107_D9B); 
    TTL74107_SET_K(pins74107_D9B);

    TTL7474_SET_CLR(pins7474_E7A);
    TTL7474_SET_PRE(pins7474_E7A);

    TTL7474_SET_CLR(pins7474_E7B);
    TTL7474_SET_PRE(pins7474_E7B);

    TTL74107_SET_CLR(pins74107_F3B);

    TTL74107_SET_J(pins74107_F6B);
    TTL74107_SET_K(pins74107_F6B);

    TTL7430_SET_B(pins7430_F7);
    TTL7430_SET_C(pins7430_F7);
    TTL7430_SET_D(pins7430_F7);

    int idxClock = 0;
    while(true)
    {
        /*-------*/
        /* HSYNC */
        /*-------*/
        /* F8 */
        TTL7493_PUT_CLK(pins7493_F8,PIN_CLK());
        pins7493_F8 = TTL7493_ACT(pins7493_F8);

        /* F9 */
        TTL7493_PUT_CLK(pins7493_F9,TTL7493_GET_Q3(pins7493_F8));
        pins7493_F9 = TTL7493_ACT(pins7493_F9);

        /* F6B */
        TTL74107_PUT_CLK(pins74107_F6B,PIN_128H());
        pins74107_F6B = TTL74107_ACT(pins74107_F6B);

        /* F7 */
        TTL7430_PUT_A(pins7430_F7,PIN_256H());
        TTL7430_PUT_E(pins7430_F7,PIN_4H());
        TTL7430_PUT_F(pins7430_F7,PIN_2H());
        TTL7430_PUT_G(pins7430_F7,PIN_128H());
        TTL7430_PUT_H(pins7430_F7,PIN_64H());
        pins7430_F7 = TTL7430_ACT(pins7430_F7);

        /* E7B */
        TTL7474_PUT_CLK(pins7474_E7B,PIN_CLK());
        TTL7474_PUT_D(pins7474_E7B,TTL7430_GET_Y(pins7430_F7));
        pins7474_E7B = TTL7474_ACT(pins7474_E7B);

        /* _HRESET */
        if(_PIN_HRESET())
        {
            TTL74107_SET_CLR(pins74107_F6B);
        }
        else
        {
            TTL74107_RESET_CLR(pins74107_F6B);
        }

        /* HRESET */
        if(PIN_HRESET())
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

        pins74107_F6B = TTL74107_ACT(pins74107_F6B);
        pins7493_F8 = TTL7493_ACT(pins7493_F8);
        pins7493_F9 = TTL7493_ACT(pins7493_F9);

        /*-------*/
        /* VSYNC */
        /*-------*/
        /* E8 */
        TTL7493_PUT_CLK(pins7493_E8,PIN_HRESET());
        pins7493_E8 = TTL7493_ACT(pins7493_E8);

        /* E9 */
        TTL7493_PUT_CLK(pins7493_E9,TTL7493_GET_Q3(pins7493_E8));
        pins7493_E9 = TTL7493_ACT(pins7493_E9);

        /* D9B */
        TTL74107_PUT_CLK(pins74107_D9B,PIN_128V());
        pins74107_D9B = TTL74107_ACT(pins74107_D9B);

        /* D8C */
        TTL7410_PUT_A(pins7410_D8C,PIN_256V());
        TTL7410_PUT_B(pins7410_D8C,PIN_4V());
        TTL7410_PUT_C(pins7410_D8C,PIN_1V());
        pins7410_D8C = TTL7410_ACT(pins7410_D8C);

        /* E7A */
        TTL7474_PUT_CLK(pins7474_E7A,PIN_CLK());
        TTL7474_PUT_D(pins7474_E7A,TTL7410_GET_Y(pins7410_D8C));
        pins7474_E7A = TTL7474_ACT(pins7474_E7A);

        /* _VRESET */
        if(TTL7474_GET_Q(pins7474_E7A))
        {
            TTL74107_SET_CLR(pins74107_D9B);
        }
        else
        {
            TTL74107_RESET_CLR(pins74107_D9B);
        }

        /* VRESET */
        if(TTL7474_GET_QQ(pins7474_E7A))
        {
            TTL7493_SET_CLR1(pins7493_E8);
            TTL7493_SET_CLR2(pins7493_E8);
            TTL7493_SET_CLR1(pins7493_E9);
            TTL7493_SET_CLR2(pins7493_E9);
        }
        else
        {
            TTL7493_RESET_CLR1(pins7493_E8);
            TTL7493_RESET_CLR2(pins7493_E8);
            TTL7493_RESET_CLR1(pins7493_E9);
            TTL7493_RESET_CLR2(pins7493_E9);
        }

        pins74107_D9B = TTL74107_ACT(pins74107_D9B);
        pins7493_E8 = TTL7493_ACT(pins7493_E8);
        pins7493_E9 = TTL7493_ACT(pins7493_E9);

        /*------------------*/
        /* SYNC / Video Sum */
        /*------------------*/
        /* G5B */
        TTL7410_PUT_A(pins7410_G5B, PIN_16H());
        TTL7410_PUT_B(pins7410_G5B, PIN_64H());
        TTL7410_PUT_C(pins7410_G5B, PIN_64H());
        pins7410_G5B = TTL7410_ACT(pins7410_G5B);

        /* H5B / H5C */
        TTL7400_PUT_A(pins7400_H5B, TTL7410_GET_Y(pins7410_G5B));
        TTL7400_PUT_B(pins7400_H5B, TTL7400_GET_Y(pins7400_H5C));
        pins7400_H5B = TTL7400_ACT(pins7400_H5B);

        TTL7400_PUT_A(pins7400_H5C, TTL7400_GET_Y(pins7400_H5B));
        TTL7400_PUT_B(pins7400_H5C, _PIN_HRESET());
        pins7400_H5C = TTL7400_ACT(pins7400_H5C);

        TTL7400_PUT_B(pins7400_H5B, TTL7400_GET_Y(pins7400_H5C));
        pins7400_H5B = TTL7400_ACT(pins7400_H5B);

        TTL7400_PUT_A(pins7400_H5C, TTL7400_GET_Y(pins7400_H5B));
        pins7400_H5C = TTL7400_ACT(pins7400_H5C);

        /* H5D */
        TTL7400_PUT_A(pins7400_H5D, TTL7400_GET_Y(pins7400_H5C));
        TTL7400_PUT_B(pins7400_H5D, PIN_32H());
        pins7400_H5D = TTL7400_ACT(pins7400_H5D);

        /* F5C / F5D */
        TTL7402_PUT_A(pins7402_F5C,PIN_VRESET());
        TTL7402_PUT_B(pins7402_F5C,TTL7402_GET_Y(pins7402_F5D));
        pins7402_F5C = TTL7402_ACT(pins7402_F5C);

        TTL7402_PUT_A(pins7402_F5D,PIN_16V());
        TTL7402_PUT_B(pins7402_F5D,TTL7402_GET_Y(pins7402_F5C));
        pins7402_F5D = TTL7402_ACT(pins7402_F5D);

        TTL7402_PUT_B(pins7402_F5C,TTL7402_GET_Y(pins7402_F5D));
        pins7402_F5C = TTL7402_ACT(pins7402_F5C);
        TTL7402_PUT_B(pins7402_F5D,TTL7402_GET_Y(pins7402_F5C));
        pins7402_F5D = TTL7402_ACT(pins7402_F5D);

        /* H5A */
        TTL7400_PUT_A(pins7400_H5A,PIN_8V());
        TTL7400_PUT_B(pins7400_H5A,PIN_8V());
        pins7400_H5A = TTL7400_ACT(pins7400_H5A);

        /* G5A */
        TTL7410_PUT_A(pins7410_G5A, TTL7402_GET_Y(pins7402_F5D));
        TTL7410_PUT_B(pins7410_G5A, PIN_4V());
        TTL7410_PUT_C(pins7410_G5A, TTL7400_GET_Y(pins7400_H5A));
        pins7410_G5A = TTL7410_ACT(pins7410_G5A);

        /* A4D */
        TTL7486_PUT_A(pins7486_A4D, _PIN_HSYNC());
        TTL7486_PUT_B(pins7486_A4D, _PIN_VSYNC());
        pins7486_A4D = TTL7486_ACT(pins7486_A4D);

        /* E4E */
        TTL7404_PUT_A(pins7404_E4E, TTL7486_GET_Y(pins7486_A4D));
        pins7404_E4E = TTL7404_ACT(pins7404_E4E);

        /*-----*/
        /* NET */
        /*-----*/
        /* F3B */
        TTL74107_PUT_J(pins74107_F3B,PIN_256H());
        TTL74107_PUT_K(pins74107_F3B,_PIN_256H());
        TTL74107_PUT_CLK(pins74107_F3B,PIN_CLK());
        pins74107_F3B = TTL74107_ACT(pins74107_F3B);

        /* G3B */
        TTL7400_PUT_A(pins7400_G3B,PIN_256H());
        TTL7400_PUT_B(pins7400_G3B,TTL74107_GET_QQ(pins74107_F3B));
        pins7400_G3B = TTL7400_ACT(pins7400_G3B);

        /* G2B */
        TTL7427_PUT_A(pins7427_G2B,PIN_4V());
        TTL7427_PUT_B(pins7427_G2B,PIN_VBLANK());
        TTL7427_PUT_C(pins7427_G2B,TTL7400_GET_Y(pins7400_G3B));
        pins7427_G2B = TTL7427_ACT(pins7427_G2B);

        /*--------*/
        /* REPORT */
        /*--------*/
        if(!clock)
        {
            if(idxClock == 454)
            {
                idxClock = 0;
            }
            else
            {
                idxClock++;
            }
        }

        sprintf(szIdxClock, "%03d", idxClock);
        printf("%s %03d %03d CLK:%s E7.12:%s G5B:%s _HRESET:%s _HBLANK:%s HBLANK:%s\n",
            clock ? szIdxClock : "   ",
            ((pins7493_F8 & 0xF0) >> 4) + (pins7493_F9 & 0xF0) + (PIN_256H() ? 256 : 0),
            ((pins7493_E8 & 0xF0) >> 4) + (pins7493_E9 & 0xF0) + (PIN_256V() ? 256 : 0),
            clock ? "H" : "L",
            TTL7430_GET_Y(pins7430_F7) ? "H" : "L",
            TTL7410_GET_Y(pins7410_G5B) ? "H" : "L",
            _PIN_HRESET() ? "H" : "L",
            _PIN_HBLANKING() ? "H" : "L",
            PIN_HBLANKING() ? "H" : "L");

        /*-----------*/
        /* Half TICK */
        /*-----------*/
        clock = !clock;
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


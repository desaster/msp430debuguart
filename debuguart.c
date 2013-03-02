#include <msp430.h>
#include <legacymsp430.h>
#include <inttypes.h>

#include "debuguart.h"

#define DEBUGUART_TXD BIT1
#define DEBUGUART_BAUD 9600

void fulldelay()
{
    //__delay_cycles(16 * 100);
    __delay_cycles(F_CPU / DEBUGUART_BAUD);
}

void halfdelay()
{
    //__delay_cycles(16 * 100 / 2);
    __delay_cycles(F_CPU / DEBUGUART_BAUD / 2);
}

inline void debuguart_high(void)
{
    P1OUT |= DEBUGUART_TXD;
}

inline void debuguart_low(void)
{
    P1OUT &= ~(DEBUGUART_TXD);
}

void debuguart_init(void)
{
    P1DIR |= DEBUGUART_TXD;
    debuguart_high();
}

void debuguart_sendbyte(uint8_t c)
{
    /* start bit */
    debuguart_low();
    fulldelay();

    if (c & 1) debuguart_high(); else debuguart_low();
    fulldelay();

    if (c & 2) debuguart_high(); else debuguart_low();
    fulldelay();

    if (c & 4) debuguart_high(); else debuguart_low();
    fulldelay();

    if (c & 8) debuguart_high(); else debuguart_low();
    fulldelay();

    if (c & 16) debuguart_high(); else debuguart_low();
    fulldelay();

    if (c & 32) debuguart_high(); else debuguart_low();
    fulldelay();

    if (c & 64) debuguart_high(); else debuguart_low();
    fulldelay();

    if (c & 128) debuguart_high(); else debuguart_low();
    fulldelay();

    /* parity thingie */
    debuguart_high();
    fulldelay();
}

void debuguart_print(char *s)
{
    do {
        debuguart_sendbyte(*s);
    } while (*++s != '\0');
}

/*
int debuguart_putchar(char c, FILE *stream)
{
    if (c == '\n') {
        debuguart_sendbyte('\r');
    }
    debuguart_sendbyte(c);
    return 0;
}
*/

/* vim: set sw=4 et: */

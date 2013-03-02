#include <msp430.h>
#include <legacymsp430.h>

#include "tprintf.h"
#include "debuguart.h"

#define LED1    BIT0

void wait(void);
void board_init(void);

uint8_t foo(uint8_t *val)
{
    return val;
}

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;

    BCSCTL1 = CALBC1_1MHZ; // Set range
    DCOCTL = CALDCO_1MHZ; // Set DCO step + modulation */

    board_init();
    debuguart_init();

    tprintf("Hello world!\r\n");

    while (1) {
        tprintf("Looping..\r\n");
        tprintf("value: [0x%x]\r\n", (uint8_t *) 0x10fe);
        foo((uint8_t *) 0x10fe);
        wait();
    }
}

void wait(void)
{
    volatile int i;
    for (i = 0; i < 1000; i ++) {
        __delay_cycles(16 * 1000);
    }
}

void board_init(void)
{
    P1DIR |= LED1;

    /* SMCLK output on P1.4 */
    P1SEL |= BIT4;
    //P1SEL2 &= ~BIT4;
    P1DIR |= BIT4;
}


/* vim: set sw=4 et: */

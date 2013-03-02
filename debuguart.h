#ifndef __DEBUGUART_H
#define __DEBUGUART_H

#include <inttypes.h>

void debuguart_init(void);
void debuguart_sendbyte(uint8_t c);
void debuguart_print(char *s);
/*
int debuguart_putchar(char c, FILE *stream);
*/

#endif

/* vim: set sw=4 et: */

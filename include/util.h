#ifndef util_h_INCLUDED
#define util_h_INCLUDED

#include <stdarg.h>
#include <stdio.h>

/****************
 *  INDENTAÇÃO  *
 ****************/

/* o mesmo que printf, mas com indentação */
void iprintf(const char *format, ...);

/* Imprime um array, com indentação */
void iprint_arr(int arr[], size_t size, char *msg);

/* controlam a indentação */
void indent();
void deindent();

/* verifica se uma lista está ordenada */
void assert_sorted(int list[], size_t size);

#endif // util_h_INCLUDED

/**
 *  Filename: print-ascii.h
 *   Created: 2014-06-11 14:44:27
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */

#ifndef PRINT_ASCII_H
#define PRINT_ASCII_H
#include <sys/types.h>

#define ASCII_LINELENGTH 300
#define HEXDUMP_BYTES_PER_LINE 16
#define HEXDUMP_SHORTS_PER_LINE (HEXDUMP_BYTES_PER_LINE / 2)
#define HEXDUMP_HEXSTUFF_PER_SHORT 5 /* 4 hex digits and a space */
#define HEXDUMP_HEXSTUFF_PER_LINE \
		(HEXDUMP_HEXSTUFF_PER_SHORT * HEXDUMP_SHORTS_PER_LINE)


void ascii_print(register const u_char *cp, register u_int length);
void hex_and_ascii_print_with_offset(register const char *ident,
    register const u_char *cp, register u_int length, register u_int oset);
void hex_and_ascii_print(register const char *ident, register const u_char *cp,
    register u_int length);
void hex_print_with_offset(register const char *ident, register const u_char *cp, register u_int length,
		      register u_int oset);
void hex_print(register const char *ident, register const u_char *cp, register u_int length);

#endif /* end of include guard: PRINT_ASCII_H */

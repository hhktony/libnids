/**
 *  Filename: xids_udp.c
 *   Created: 2014-06-11 16:52:44
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#include "xids_interface.h"
#include "xids_udp.h"

void xids_udp_callback(struct tuple4 *tuple, char *buf, int len, struct ip *iph)
{
    xids_print_tuple4("<--->", tuple);
    hex_and_ascii_print("\n\t", (const u_char *)buf, len);
    printf("\n");

    return ;
}

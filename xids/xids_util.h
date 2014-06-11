/**
 *  Filename: xids_util.h
 *   Created: 2014-06-11 14:23:28
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */

#ifndef IDS_UTIL_H
#define IDS_UTIL_H

#include <arpa/inet.h>

#define xids_inet_ntoa(x) inet_ntoa(*((struct in_addr *)&x))

void xids_print_tuple4(const char *dir, struct tuple4 *tuple);

#endif /* end of include guard: IDS_UTIL_H */

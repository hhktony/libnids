/**
 *  Filename: xids_util.c
 *   Created: 2014-06-11 14:21:54
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#include "nids.h"
#include "xids_util.h"

void xids_print_tuple4(const char *dir, struct tuple4 *tuple)
{
    printf("%s", xids_inet_ntoa(tuple->saddr));
    printf(":%i", tuple->source);
    printf(" %s ", dir);
    printf("%s", xids_inet_ntoa(tuple->daddr));
    printf(":%i", tuple->dest);

    return;
}

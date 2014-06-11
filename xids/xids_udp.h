/**
 *  Filename: xids_udp.h
 *   Created: 2014-06-11 16:57:07
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#ifndef XIDS_UDP_H
#define XIDS_UDP_H

void xids_udp_callback(struct tuple4 *tuple, char *buf, int len, struct ip *iph);

#endif /* end of include guard: XIDS_UDP_H */

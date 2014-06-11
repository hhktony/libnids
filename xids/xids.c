/**
 *  Filename: xids.c
 *   Created: 2014-06-11 14:20:06
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */

#include <stdlib.h>
#include "xids_interface.h"

int main(void)
{
    nids_params.pcap_filter = "port 21";

	if (!nids_init()) {
		printf("nids_init() error：%s\n", nids_errbuf);
		return 1;
	}

	nids_register_tcp(xids_tcp_callback);
    nids_register_tcp(xids_udp_callback);

	nids_run();

	return 0;
}

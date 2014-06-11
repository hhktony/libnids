/**
 *  Filename: xids_tcp.c
 *   Created: 2014-06-11 16:37:27
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#include "xids_interface.h"
#include "xids_tcp.h"

void xids_tcp_callback(struct tcp_stream *ts, void **arg)
{
	struct tuple4 tuple = ts->addr;

	switch (ts->nids_state) {
	case NIDS_JUST_EST:		/* 表示TCP客户端和TCP服务器端建立连接状态 */
		/* TCP连接建立 */
		ts->client.collect++;	    /* 客户端接收数据 */
		ts->server.collect++;	    /* 服务器接收数据 */
		ts->server.collect_urg++;	/* 服务器接收紧急数据 */
		ts->client.collect_urg++;	/* 客户端接收紧急数据 */
        xids_print_tuple4("<--->", &tuple);
        printf("  [EST]\n");
		return;
	case NIDS_CLOSE:			/* 表示TCP连接正常关闭 */
        xids_print_tuple4("<--->", &tuple);
        printf("  [CLOSE]\n");
		return;
	case NIDS_RESET:			/* 表示TCP连接被RST关闭 */
        xids_print_tuple4("<--->", &tuple);
        printf("  [RESET]\n");
		return;
	case NIDS_DATA:			    /* 表示有新的数据到达 */
		{
			struct half_stream *hlf;	/* 表示TCP连接的一端的信息，可以是客户端，也可以是服务器端 */
			if (ts->server.count_new_urg) {	/* 表示TCP服务器端接收到新的紧急数据 */
                xids_print_tuple4("urgent--->", &tuple);
                printf("\n");

				return;
			}
			if (ts->client.count_new_urg) {
                xids_print_tuple4("<---urgent", &tuple);
                printf("\n");
				return;
			}
			if (ts->client.count_new) {
				/* 表示客户端接收到新的数据 */
				hlf = &ts->client;
				/* 此时hlf表示的是客户端的TCP连接信息 */
                xids_print_tuple4("<---", &tuple);
                hex_and_ascii_print("\n\t", (const u_char *)hlf->data, hlf->count_new);
				printf("\n");
			} else {
				/* 表示服务器端接收到新的数据 */
				hlf = &ts->server;
				/* 此时hlf表示服务器端的TCP连接信息 */
                xids_print_tuple4("--->", &tuple);
                hex_and_ascii_print("\n\t", (const u_char *)hlf->data, hlf->count_new);
				printf("\n");
			}
		}
	default:
		break;
	}

	return;
}

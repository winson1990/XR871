/*
 * Copyright (C) 2017 XRADIO TECHNOLOGY CO., LTD. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the
 *       distribution.
 *    3. Neither the name of XRADIO TECHNOLOGY CO., LTD. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _IPERF_H_
#define _IPERF_H_

#include "lwip/netif.h"
#include "kernel/os/os_thread.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_INTERVAL 60
#define IPERF_ARG_HANDLE_MAX     4

enum IPERF_MODE {
	IPERF_MODE_UDP_SEND = 0,
	IPERF_MODE_UDP_RECV,
	IPERF_MODE_TCP_SEND,
	IPERF_MODE_TCP_RECV,
	IPERF_MODE_NUM,
};

enum IPERF_FLAGS {
	IPERF_FLAG_PORT    = 0x00000001,
	IPERF_FLAG_IP      = 0x00000002,
	IPERF_FLAG_CLINET  = 0x00000004,
	IPERF_FLAG_SERVER  = 0x00000008,
	IPERF_FLAG_UDP     = 0x00000010,
	IPERF_FLAG_FORMAT  = 0x00000020,
	IPERF_FLAG_STOP    = 0x00000040,
};

typedef struct {
	enum IPERF_MODE	mode;
	ip_addr_t	remote_ip;
	uint32_t	port;
	uint32_t	run_time; // in seconds, 0 means forever
	uint32_t	interval; // in seconds, 0 means 1 second(default)
	uint32_t	flags;
	OS_Thread_t iperf_thread;
	int 		handle;
}iperf_arg;

typedef struct UDP_datagram {
    signed int id ;
} UDP_datagram;


int iperf_start(struct netif *nif, int handle);
int iperf_stop(char* arg);
int iperf_parse_argv(int argc, char *argv[]);
int iperf_handle_free(int handle);
int iperf_handle_start(struct netif * nif, int handle);

#ifdef __cplusplus
}
#endif

#endif /* _IPERF_H_ */

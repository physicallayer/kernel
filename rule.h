#pragma once

#include <linux/types.h>
#include "fileio.h"

#define POLICY_ACCEPT = 0
#define POLICY_DROP = 1
#define PROTOCOL_TCP = 0
#define PROTOCOL_UDP = 1

static struct nf_hook_ops *nfho = NULL;

typedef struct firewall_rule {
    __s8 interface[12];
    __u8 protocol;
    __u32 src_ip; //192.168.0.1
    __u16 src_port;
    __u32 dst_ip;
    __u16 dst_port;
    __s8 policy;
} Rule;

#define _IN_RULE "/etc/firewall/in.rule"
#define _OUT_RULE "/etc/firewall/out.rule"

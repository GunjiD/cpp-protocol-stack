#ifndef ETHERNET_H
#define ETHERNET_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

const int ETH_P_ALL = 0x0003;
const int MAC_LEN = 6;
const int ETH_T_ARP = 0x0806;
const int BUF_SIZ = 65536;

struct ethernet_hdr {
  uint8_t dest[MAC_LEN];
  uint8_t src[MAC_LEN];
  uint16_t ethehertype;
};

//  char *dest_addr(ethernet_hdr *eth_hdr);
//  char *src_addr(ethernet_hdr *eth_hdr);
void ethHdrDbg(unsigned char *buf, ssize_t byte);

#endif

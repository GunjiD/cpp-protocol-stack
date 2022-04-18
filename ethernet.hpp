#ifndef ETHERNET_H
#define ETHERNET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

class EthernetProtocol {
private:
  struct ethernet_hdr *eth_header;

public:
  //  char *dest_addr(ethernet_hdr *eth_hdr);
  //  char *src_addr(ethernet_hdr *eth_hdr);
  void HdrDbg(unsigned char *buf, ssize_t byte);
};

#endif

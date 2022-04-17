#ifndef IP_H_
#define IP_H_

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include "ethernet.hpp"

#define IP_CHAR_LEN 16
#define HEX 0
#define INTEGER 1
#define BUF_SIZ 65535

class IpProtocol {
  //    options
  //    padding
public:
  void HdrDbg(unsigned char *buf, int dump_form);
};

#endif
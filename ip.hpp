#define IP_H_
#ifndef IP_H_

#include <arpa/inet.h>
#include <sys/socket.h>

#include "inet.hpp"

#define IP_CHAR_LEN 16
#define HEX 0
#define INTEGER 1
#define BUF_SIZ 65535

class IpProtocol {
private:
  struct ip_hdr *ip_header;

public:
  void HdrDbg(unsigned char *buf, int dump_form);
};

#endif

#ifndef RAW_SOC_H_
#define RAW_SOC_H_

#include <errno.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "ethernet.hpp"

class Socket {
public:
  // 引数のあるコンストラクタにして、インターフェース名を受けとってもいいかも
  Socket();
  ~Socket();

private:
  int socket;

public:
  int create_socket(char *interface_name);
};

#endif

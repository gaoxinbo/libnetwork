// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <unistd.h>
#include "socket.h"

namespace network {

Socket::Socket(){
  fd_ = -1;
}

Socket::Socket(int fd):fd_(fd){
}

Socket::~Socket(){
  if(fd_ != -1)
    close(fd_);
}

bool Socket::Create(){
  if(fd_ != -1)
    close(fd_);
  fd_ = socket(AF_INET, SOCK_STREAM, 0);
  return fd_ != -1;
}

}  // namespace network


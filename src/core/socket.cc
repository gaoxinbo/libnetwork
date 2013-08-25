// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <unistd.h>
#include <fcntl.h>
#include "socket.h"

namespace network {

Socket::Socket(){
  fd_ = -1;
}

Socket::~Socket(){
  if(fd_ != -1)
    close(fd_);
}

bool Socket::isValid(){
  return fd_ != -1;
}

bool Socket::Create(){
  if(fd_ != -1)
    close(fd_);
  fd_ = socket(AF_INET, SOCK_STREAM, 0);

  return fd_ != -1;
}

void Socket::setReuse(){
  if(!isValid())
    return;
  
  int val = 1;
  setsockopt(fd_,SOL_SOCKET,SO_REUSEADDR,&val,sizeof val);
}

void Socket::setNoBlocking(){
  if(!isValid())
    return;
  int old = fcntl(fd_,F_GETFL);
  fcntl(fd_,F_SETFL,old | O_NONBLOCK);
}

}  // namespace network


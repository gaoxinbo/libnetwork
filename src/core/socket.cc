// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "socket.h"

#include <iostream>
using namespace std;

namespace network {

Socket::Socket(){
  fd_ = -1;
}

Socket::~Socket(){
  if(fd_ != -1)
    close(fd_);
}

Socket::Socket(int  fd){
  fd_ = fd;
}

bool Socket::isValid(){
  return fd_ != -1;
}

Status Socket::Create(){
  if(fd_ != -1)
    close(fd_);
  fd_ = socket(AF_INET, SOCK_STREAM, 0);

  Status ss;
  if(fd_ == -1){
    ss = Status::IOErrorStatus(strerror(errno)," create socket error"); 
    return ss;
  }
  return ss;
}

void Socket::setReuse(){
  if(!isValid())
    return;
  
  int val = 1;
  int ret = setsockopt(fd_,SOL_SOCKET,SO_REUSEADDR,&val,sizeof val);
  if(ret == -1)
    cout<<strerror(errno)<<endl;
}

void Socket::setNoBlocking(){
  if(!isValid())
    return;
  int old = fcntl(fd_,F_GETFL);
  fcntl(fd_,F_SETFL,old | O_NONBLOCK);
}

Status Socket::listen(Address & addr){
  Status ss;
  if(!isValid()){
    ss = Create();
    if(!ss.isOK()){
      return ss;
    }
  }

  sockaddr_in sock;
  sock.sin_family = AF_INET;
  sock.sin_port = htons(addr.getPort());
  sock.sin_addr.s_addr = INADDR_ANY; 

  if(bind(fd_, (sockaddr *)&sock, sizeof sock) == -1){
    ss = Status::IOErrorStatus(strerror(errno)," bind error");
    return ss;
  }

  setReuse();
  setNoBlocking();
  if(::listen(fd_,256)==-1){
    ss = Status::IOErrorStatus(strerror(errno)," listen error");
  }
  
  return ss;
}

int Socket::accept(){
  sockaddr_in addr;
  socklen_t len = sizeof addr;
  int ret = ::accept(fd_, (sockaddr*)&addr, &len);
  if(ret == -1 && (errno == EAGAIN || errno == EWOULDBLOCK )){
    return 0;
  }
  else
    return ret;
}

int Socket::connect(string ip, short port){
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  int ret = inet_pton(AF_INET,ip.c_str(),&addr.sin_addr);
  if(ret == -1){
    return ret;
  }

  ret = ::connect(fd_,(sockaddr*)&addr, sizeof addr);
  return ret;
}


}  // namespace network


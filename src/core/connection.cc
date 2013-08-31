// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <string>

#include "connection.h"
#include "util/log.h"

using namespace std;
namespace network {

Connection::Connection(){
  sock_ = NULL;
}

Connection::~Connection(){
  if(sock_)
    delete sock_;
}

Connection::Connection(Socket *sock, Address addr){
  sock_ = sock;
  addr_ = addr;
}

Status Connection::connect(string ip, short port){
  Status ss;
  if(sock_ == NULL)
    sock_ = new Socket();

  ss = sock_->Create();
  if(!ss.isOK())
    return ss;
  
  int ret = sock_->connect(ip,port);
  if(ret == -1){
    ss = Status::IOErrorStatus(strerror(errno),"connect error");
    return ss;
  }
  
  return ss;
}

void Connection::handleRead(){
  char buf[1024];
  int ret = read(sock_->getFD(),buf,1024);
  if(ret == 0){
    looper_ -> delEvent(sock_->getFD());
    LOG_INFO("network"," connection is closed by remote");

    // TODO
    delete this;
    return;
  }
  return;
}

void Connection::handleWrite(){
  return;
}

int Connection::getFD(){
  if(sock_!=NULL){
    return sock_->getFD();
  }
  else
    return -1;
}

}  // namespace network


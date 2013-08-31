// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <errno.h>
#include <string.h>
#include <string>
#include "connection.h"

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
}

void Connection::handleWrite(){
}

}  // namespace network


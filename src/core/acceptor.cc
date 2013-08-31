// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include "acceptor.h"
#include "connection.h"
#include "util/log.h"

using namespace std;

namespace network {

Acceptor::Acceptor():IOchannel(){
}

Acceptor::~Acceptor(){
}

Status Acceptor::listen(short port){
  Status ss;
  addr_.setPort(port);
  ss = sock_.listen(addr_);
  return ss;
}

int Acceptor::accept(){
  return sock_.accept();  
}

void Acceptor::handleWrite(){
}
void Acceptor::handleRead(){
  int ret = 0;
  while(true){
    ret = sock_.accept(); 
    if(ret==0) // errno is EAGAIN 
      return;

    if(ret<0){
      LOG_WARN("accept error %s", strerror(errno));
    }

    sockaddr_in addr;
    socklen_t len = sizeof addr;
    getpeername(ret,(sockaddr*)&addr, &len); 
    char buf[24];
    inet_ntop(AF_INET, &addr.sin_addr, buf, 24);

    LOG_INFO("network","new client %s:%d %d",buf, ntohs(addr.sin_port),ret);
    Address address(buf,ntohs(addr.sin_port));

    Socket *s = new Socket(ret); 
    Connection * conn = new Connection(s,address);
    conn->setLooper(looper_);
    looper_->addEvent(s->getFD(), conn,kREAD);
  }
}

}  // namespace network


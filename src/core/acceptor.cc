// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <iostream>
#include "acceptor.h"
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
    if(ret<=0)
      return;

    LOG_INFO("network", "new client");
  }
}

}  // namespace network


// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <stdlib.h>
#include <arpa/inet.h>
#include "address.h"

using namespace std;

namespace network {

Address::Address(){
  port_ = 0;
  ip_ = "";
}

Address::~Address(){
}

Address::Address(short port){
  port_ = port;
  ip_ = "";
}

Address::Address(string host, short port){
  ip_ = host;
  port_ = port;
}

Address::Address(const Address & addr){
  ip_ = addr.ip_;
  port_ = addr.port_;
}

Address & Address::operator=(const Address & addr){
  if(this == &addr)
    return *this;
  ip_ = addr.ip_;
  port_ = addr.port_;

  return *this;
}

Address::Address(string add){
  string::size_type pos = add.find(":");
  if(pos != string::npos){
    ip_ = add.substr(0,pos);
    port_ = atoi(add.substr(pos+1).c_str());
  }
}

}  // namespace network


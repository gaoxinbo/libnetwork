// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include <stdlib.h>
#include <arpa/inet.h>
#include "address.h"

using namespace std;

namespace network {

Address::Address(){
  port_ = INADDR_ANY;
}

Address::~Address(){
}

Address::Address(short port){
  port_ = port;
}

Address::Address(string add){
  string::size_type pos = add.find(":");
  if(pos != string::npos){
    ip_ = add.substr(0,pos);
    port_ = atoi(add.substr(pos+1).c_str());
  }
}

}  // namespace network


// File: address.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-25
// Copyright 2013, Xinbo Gao.  All rights reserved.

#ifndef _ADDRESS_H_
#define _ADDRESS_H_

#include <string>

namespace network {

class Address {
  public:
    Address();
    ~Address();

    // Only port means the ip is localhost 
    Address(short port);
    // ip:port
    Address(std::string add);
    Address(std::string host, short port);

    short getPort(){
      return port_;
    }

    std::string getIP(){
      return ip_; 
    }

    void setPort(short port){
      port_ = port;
    }

    Address(const Address&);
    Address & operator=(const Address&);

  private:
    short port_;
    std::string ip_;

};

}  // namespace network
#endif  // _ADDRESS_H_


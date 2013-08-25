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

    short getPort(){
      return port_;
    }

    std::string getIP(){
      return ip_; 
    }

  private:
    short port_;
    std::string ip_;

  private:
    Address(const Address&);
    void operator=(const Address&);
};

}  // namespace network
#endif  // _ADDRESS_H_


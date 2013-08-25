// File: accepter.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-25
// Copyright 2013, Xinbo Gao.  All rights reserved.

#ifndef _ACCEPTER_H_
#define _ACCEPTER_H_
namespace network {

class Accepter {
  public:
    Accepter();
    ~Accepter();

  private:
    Accepter(const Accepter&);
    void operator=(const Accepter&);
};

}  // namespace network
#endif  // _ACCEPTER_H_


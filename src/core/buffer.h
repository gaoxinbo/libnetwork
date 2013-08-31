// File: buffer.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-31
// Copyright 2013, Xinbo Gao.  All rights reserved.

#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <string>
#include <vector>

namespace network {

class Buffer {
  public:
    Buffer();
    Buffer(int);
    ~Buffer();

  int remain();
  int expand(int);
  int readable();

  void writeInt32(int);
  void writeChar(char);
  void writeString(const std::string &s);

  int readInt32();
  char readChar();
  std::string readString();
  
  private:
    std::vector<char>  buf_;
    int start_;
    int end_;

  private:
    Buffer(const Buffer&);
    Buffer & operator=(const Buffer&);
};

}  // namespace network
#endif  // _BUFFER_H_


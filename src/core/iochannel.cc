// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com
#include <stdlib.h>
#include "iochannel.h"

namespace network {

IOchannel::IOchannel(){
  looper_ = NULL;
}

IOchannel::~IOchannel(){
}

void IOchannel::setLooper(EventLooper * looper){
  looper_ = looper;
}

}  // namespace network


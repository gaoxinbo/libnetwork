#ifndef _NETWORK_GUARD_H_
#define _NETWORK_GUARD_H_

#include "Mutex.h"

namespace network{

class Guard{
  public:
    Guard(Mutex & mutex);
    ~Guard();

  private:
    Mutex &mutex_;
  private:
    Guard(const Guard &);
    Guard & operator=(const Guard &);
};

}

#endif

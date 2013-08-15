#ifndef _NETWORK_MUTEX_H_
#define _NETWORK_MUTEX_H_
#include "pthread.h"

namespace network{

class Mutex {
  public:
    Mutex();
    ~Mutex();

    void Lock();
    void Unlock();

    pthread_mutex_t * Get();

  private:
    pthread_mutex_t mutex_;
  private:
    Mutex(const Mutex&);
    Mutex & operator=(const Mutex&);
};

}
#endif

#include "pthread.h"

namespace network{

class Mutex {
  public:
    Mutex();
    ~Mutex();

    void Lock();
    void Unlock();

  private:
    pthread_mutex_t mutex_;
  private:
    Mutex(const Mutex&);
    Mutex & operator=(const Mutex&);
};

}

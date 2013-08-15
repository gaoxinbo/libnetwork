#ifndef _NETWORK_CONDITION_H_
#define _NETWORK_CONDITION_H_

#include "pthread.h"
#include "Mutex.h"

namespace network{

class Condition{

  Condition();
  ~Condition();

  void Wait(Mutex &);
  void Signal(); 
  void Broadcast();
   

  private:
    pthread_cond_t cond_;
  private:
    Condition(const Condition &);
    Condition & operator=(const Condition &);
};

}

#endif

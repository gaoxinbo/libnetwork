#include "Condition.h"

namespace network{

Condition::Condition(){
  pthread_cond_init(&cond_,NULL);
}

Condition::~Condition(){
  pthread_cond_destroy(&cond_);
}

void Condition::Wait(Mutex &mutex){
  pthread_cond_wait(&cond_,mutex.Get());
}

void Condition::Signal(){
  pthread_cond_signal(&cond_);
}

void Condition::Broadcast(){
  pthread_cond_broadcast(&cond_);
}

}

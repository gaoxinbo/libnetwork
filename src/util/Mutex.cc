#include "Mutex.h"

namespace network {

Mutex::Mutex(){
  pthread_mutex_init(&mutex_,NULL);
}

Mutex::~Mutex(){
  pthread_mutex_destroy(&mutex_);
}

void Mutex::Lock(){
  pthread_mutex_lock(&mutex_);
}

void Mutex::Unlock(){
  pthread_mutex_unlock(&mutex_);
}

pthread_mutex_t * Mutex::Get(){
  return &mutex_;
}

}

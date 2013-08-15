#include "Guard.h"

namespace network{
 
Guard::Guard(Mutex & mutex):mutex_(mutex){
  mutex_.Lock();
}

Guard::~Guard(){
  mutex_.Unlock();
}

}

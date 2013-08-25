#include <unistd.h>
#include <iostream>
#include "core/acceptor.h"
#include "core/eventlooper.h"


using namespace std;
using namespace network;

int main(){
  
  Acceptor acc;
  Status ss = acc.listen(8000);
  if(!ss.isOK()){
    cout<<ss.What()<<endl;
    return 1;
  }
  EventLooper looper;
  looper.addEvent(acc.getFD(), &acc, kREAD);
  looper.run();
  while(1){
    sleep(100);
  }
}


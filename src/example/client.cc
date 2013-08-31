#include <unistd.h>
#include "core/connection.h"
#include "util/status.h"
#include "core/eventlooper.h"
#include <iostream>


using namespace network;
using namespace std;

int main(){
  Connection conn;
  Status ss = conn.connect("127.0.0.1",8000);
  if(!ss.isOK()){
    cout<<ss.What()<<endl;
    return 1;
  }

  EventLooper looper;
  conn.setLooper(&looper);
  looper.addEvent(conn.getFD(),&conn,kREAD);
  looper.start();
  while(1){
    sleep(1);
  }
  return 0;
}


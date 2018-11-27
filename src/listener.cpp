#include <fcntl.h>
#include <unistd.h>
#include <iostream>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include "listener.h"

Listener::Listener() : dis{XOpenDisplay(NULL)}{
}

char Listener::retrieve(){
  char keys_cur[32];
  char keys_old[32];
  XQueryKeymap(dis, keys_old);
  while(true){
    XQueryKeymap(dis, keys_cur);
    if(memcmp(keys_cur, keys_old, 32) == NULL)
      continue;
    for(int i = 0;i < 32;i++){
      for(int j = 0;j < 8;j++){
        int bit = i * 8 + j;
        bool bit_state_cur = keys_cur[i] & (1 << j);
        bool bit_state_old = keys_old[i] & (1 << j);
        if(bit_state_cur && !bit_state_old){
          char c = XKeycodeToKeysym( dis, bit, 0 );
          if(isprint(c))
            return c;
        }
      }
    }
    memcpy(keys_old, keys_cur, 32);
    usleep(1000);
  }
}


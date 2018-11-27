#include "src/eval.h"
#include "src/Engine.h"
#include "src/listener.h"
#include "src/shortkeys.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
std::string to_string(char* s){
  std::string res;
  while(*s){
    res += *s;
    s++;
  }
  return res;
}

int main(int argc, char* argv[])
{
  try{
    Engine e;
    if(argc >= 2){ // adds a key
      std::string command = to_string(argv[1]);
      if(command == "--add"){
        e.add_key(to_string(argv[2]), to_string(argv[3]));
      }else if(command == "--remove"){
        e.remove_key(to_string(argv[2]));
      }else if(command == "--list"){
        e.list_keys();
      }else if(command == "--help"){
        e.show_help();
      }
    }else{
      e.run();
    }
  }catch(const char* error_message){
    std::cerr << error_message;
  }
  return 0;
}

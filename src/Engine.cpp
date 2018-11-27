#include <sys/stat.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Engine.h"
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
Engine::Engine() : evaluator(), controller(){
  listener = Listener();
  trie = Aho_Corasick(controller.load_keys());

}
void Engine::run(){
  int state = 0;
  while(1){
    char c = listener.retrieve();
    state = trie.advance(state, c);
    std::string matched_key = trie.matched(state);
    if(matched_key != "")
      evaluator.eval(controller.get_command(matched_key));
  }
}

void Engine::add_key(std::string key, std::string cmd){
  if(!trie.prefix_check(key))
    throw "cannot add a key which is a prefix of a command or a command is prefix of it";
  controller.add_key(key, cmd);
}
void Engine::remove_key(std::string key){
  controller.remove_key(key);
}

void Engine::list_keys(){
  controller.list_keys();
}

void Engine::show_help(){
  printf("Usage: ash [options]\n");
  printf("must run in sudo mode\n");
  printf("run without parameter to get the main functionality\n");
  printf("--add key command: associates the key with the command\n");
  printf("--remove key: removes the key\n");
  printf("--help: shows this message\n");
}


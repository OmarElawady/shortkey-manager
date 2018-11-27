#include "shortkeys.h"
#include <fstream>
#include <string>
Shortkeys_controller::Shortkeys_controller(){
  std::ifstream ifs;

  ifs.open ("keys.txt", std::ifstream::in);
  if(!ifs){
    throw "Can't open file keys.txt";
    return;
  }
  std::string line;
  while(getline(ifs, line)){
    std::string key, cmd;
    this -> parse(line, key, cmd);
    this -> key_cmd[key] = cmd;
  }
  ifs.close();
}

std::vector<std::string> Shortkeys_controller::load_keys(){
  std::vector<std::string> res;
  for(auto& el : key_cmd)
    res.push_back(el.first);
  return res;
}

void Shortkeys_controller::add_key(std::string key, std::string cmd){
  std::ofstream ofs;
  ofs.open ("keys.txt", std::ifstream::out | std::ifstream::app);
  ofs << key << "#" << cmd << std::endl;
  ofs.close();
}


void Shortkeys_controller::list_keys(){
  for(auto el : key_cmd){
    printf("shortkey: %s, command: %s\n", el.first.c_str(), el.second.c_str());
  }
}


void Shortkeys_controller::remove_key(std::string key){
  std::ofstream ofs;
  ofs.open ("keys.txt", std::ifstream::out);
  for(auto el : key_cmd){
    if(el.first != key){
      ofs << el.first << "#" << el.second << std::endl;
    }
  }
  ofs.close();
}

std::string Shortkeys_controller::get_command(std::string key){
  return key_cmd[key];
}


void Shortkeys_controller::parse(std::string key_cmd, std::string& key, std::string& cmd){
  int i = 0;
  for(;key_cmd[i] != '#';i++){
    key += key_cmd[i];
  }
  i++;
  for(;i < (int)key_cmd.length();i++){
    cmd += key_cmd[i];
  }
}

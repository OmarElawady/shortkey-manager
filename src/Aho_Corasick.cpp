#include <string>
#include "Aho_Corasick.h"
Aho_Corasick::Aho_Corasick(){}
Aho_Corasick::Aho_Corasick(std::vector<std::string> _patterns) : patterns {_patterns}{
  states.resize(1);
  next.resize(1);
  suffix.resize(1);
  suffix[0] = -1;
  for(size_t i = 0;i < patterns.size();i++)
    output[add_pattern(patterns[i])] = i;
}
int Aho_Corasick::advance(int state, char c){
  while(state != -1){
    auto it = next[state].find(c);
    if(it == next[state].end())
      state = suffix[state];
    else
      return next[state][c];
  }
  return 0;
}
int Aho_Corasick::add_pattern(std::string pat){
  int state = 0;
  for(size_t i = 0;i < pat.size();i++){
    char c = pat[i];
    if(no_transition(state, c))
      add_transition(state, c);
    state = advance(state, c);
  }
  return state;
}
void Aho_Corasick::add_transition(int state, char c){
  int new_state = states.size();
  states.push_back(new_state);
  next[state][c] = new_state;
  next.push_back(std::map<char, int>());
  suffix.push_back(advance(suffix[state], c));
}
bool Aho_Corasick::no_transition(int state, char c){
  return next[state].find(c) == next[state].end();
}

std::string Aho_Corasick::matched(int state){
  auto it = output.find(state);
  if(it == output.end())
    return "";
  else
    return patterns[it -> second];
}

bool Aho_Corasick::prefix_check(std::string str){
  int state = 0;
  for(size_t i = 0;i < str.size();i++){
    if(output.find(state) != output.end())
      return false;
    auto it = next[state].find(str[i]);
    if(it == next[state].end())
      return true;
    state = it -> second;
  }
  return false;
}

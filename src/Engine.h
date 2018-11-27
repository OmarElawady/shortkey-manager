#include "eval.h"
#include "listener.h"
#include "shortkeys.h"
#include "Aho_Corasick.h"
#include <string>

class Engine{
  public:
    // EFFECTS: initializes the properties
    Engine();
    // EFFECTS: runs the main program
    void run();

    void add_key(std::string key, std::string cmd);
    void remove_key(std::string key);
    void list_keys();
    void show_help();
  private:
    Listener listener;
    Eval evaluator;
    Shortkeys_controller controller;
    Aho_Corasick trie;
    inline bool file_exist(const std::string& file);
};

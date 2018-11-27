#include <string>
#include <vector>
#include <map>
#ifndef M_SHORTKEYS
#define M_SHORTKEYS

class Shortkeys_controller{
  public:
    // EFFECTS: loads the stored shortkeys
    Shortkeys_controller();
    // EFFECTS: returns the stored shortkeys
    std::vector<std::string> load_keys();
    // REQUIRES: the passed key is not not a prefix of a stored key nor a stored key is prefix of it
    // EFFECTS : attaches the key to the command and stores this shortkey
    void add_key(std::string key, std::string cmd);
    // REQUIRES: the passed key exists
    // EFFECTS : removes the passed key
    void remove_key(std::string key);
    // EFFECTS : list all shortkeys stored
    void list_keys();
    // REQUIRES: the passed key is actually stored
    // EFFECTS : returns the command attached with the key
    std::string get_command(std::string key);
  private:
    std::map<std::string, std::string> key_cmd;

    void parse(std::string key_cmd, std::string& key, std::string& cmd);
};
#endif

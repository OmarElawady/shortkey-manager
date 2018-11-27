#include <vector>
#include <string>
#include <map>
class Aho_Corasick{
  public:
    Aho_Corasick(std::vector<std::string> _patterns);
    Aho_Corasick();
    // EFFECTS: advances from the passed state when the char c is pressed
    int advance(int state, char c);
    // EFFECTS: returns the matched string at the current state
    std::string matched(int state);
    bool prefix_check(std::string str);
  private:
    std::vector<int> states;
    std::vector<std::map<char, int>> next;
    std::vector<int> suffix;
    std::map<int, int> output;
    std::vector<std::string> patterns;
    int add_pattern(std::string pat);
    bool no_transition(int state, char c);
    void add_transition(int state, char c);
};

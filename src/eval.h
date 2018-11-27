#include <string>
#ifndef M_EVAL
#define M_EVAL
class Eval{
  public:
    Eval();
    // EFFECTS: evaluates the passed command in the system (linux)
    void eval(std::string cmd);
};
#endif

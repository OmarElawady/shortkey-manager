#include "eval.h"
#include <string>
void Eval::eval(std::string cmd){

  system((cmd + " &").c_str());
}

Eval::Eval(){

}


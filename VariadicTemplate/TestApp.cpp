#include "StateManager.h"

int main() {
  try {
    StateManager stateMgr;
    stateMgr.ProcessStateChange(State::STATE_PAUSED, 4);
    stateMgr.ProcessStateChange(State::STATE_RUNNING, std::string("eating cookies"));
    stateMgr.ProcessStateChange(State::STATE_ERROR, std::string("tummy ache"), 0xffff);
    stateMgr.ProcessStateChange(State::STATE_ERROR, std::string("tummy ache"), 4.0, 4.0);
  }
  catch (std::exception& e) {
    std::cerr << "Caught " << e.what() << std::endl;
    std::cerr << "Type " << typeid(e).name() << std::endl;
  };

  return 0;
}

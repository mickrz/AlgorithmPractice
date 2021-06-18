#pragma once
#include <exception>
#include <iostream>
#include <string>

enum State {
  STATE_STARTING = 0,
  STATE_STARTED,
  STATE_RUNNING,
  STATE_PAUSED,
  STATE_STOPPING,
  STATE_STOPPED,
  STATE_ERROR,
  STATE_MAX
};

class runtime_error : public std::exception {
public:
    explicit runtime_error(const std::string& message);

    explicit runtime_error(const char* message);

};

class StateManager {
public:
  
  // Function that accepts no parameter
  // It breaks the variadic template function chain
  void UpdateState() {}
    
  template<typename T, typename ... Args>
  void UpdateState(T first, Args ... args) {
      std::cout << __FUNCTION__ << ": ln" << __LINE__ << std::endl;
      std::cout << "UpdateState: " << std::to_string(first) << std::endl;
      // Forward arguments
      UpdateState(first, std::forward<Args>(args) ...);
  }
  
  
  void UpdateState(State state, int val) {
    std::cout << __FUNCTION__ << ": ln" << __LINE__ << std::endl;
    std::cout << "UpdateState: " << TranslateStateToString(state) << ": " << std::to_string(val) << std::endl;
  }
  
  void UpdateState(State state, std::string val) {
    std::cout << __FUNCTION__ << ": ln" << __LINE__ << std::endl;
    std::cout << "UpdateState: " << TranslateStateToString(state) << ": " << val << std::endl;
  }

  void UpdateState(State state, std::string val, int num) {
    std::cout << __FUNCTION__ << ": ln" << __LINE__ << std::endl;
    std::cout << "UpdateState: " << TranslateStateToString(state) << ": " << val << ", error code: " << std::to_string(num) << std::endl;
  }
  
  /* Variadic Template Function that accepts variable number of arguments of any type */
  template<typename T, typename ... Args>
  void ProcessStateChange(T first, Args ... args) {
    std::cout << __FUNCTION__ << ": ln" << __LINE__ << std::endl;
    // Forward arguments
    UpdateState(first, std::forward<Args>(args) ...);
  }
  
  const std::string TranslateStateToString(const State state) {
    if (state == STATE_STARTING) { return "Starting"; }
    else if (state == STATE_STARTED) { return "Started"; }
    else if (state == STATE_RUNNING) { return "Running"; }
    else if (state == STATE_PAUSED) { return "Paused"; }
    else if (state == STATE_STOPPING) { return "Stopping"; }
    else if (state == STATE_STOPPED) { return "Stopped"; }
    else if (state == STATE_ERROR) { return "Error"; }
    else { return "Unknown"; }
  }
};
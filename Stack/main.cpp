#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

const int size = 10;

int main()
{
  Stack<int>* stack = new Stack<int>();

  std::cout << "Hello Stacks!" << std::endl;
  std::cout << "=================================================" << std::endl;
  std::cout << "test run started..." << std::endl; 

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(1, 5);

  int random_num = 0;
  std::stringstream stack_data;
        
  std::cout << "Initializing stack:" << std::endl;
  std::cout << stack_data.str() << "\nstack has capacity for " << \
  std::to_string(size) << " element(s)" <<  std::endl;

  for (int i = 0; i < size; i++) {
    random_num = dis(gen);
    stack->Push(random_num);
  }

  while (!stack->IsEmpty()) {
    stack->Pop();
  }
  std::cout << stack_data.str() << std::endl;
  delete stack;
  std::cout << "test run complete...\n" << std::endl; 
  std::cout << "=================================================" << std::endl;  
  return 0;
}

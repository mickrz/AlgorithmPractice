/*
MIT License

Copyright (c) 2020 Mike Rzucidlo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Stack.h"

Stack* InitializeStack(int size)
{
  // Reference: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  // Code to generate random values for nodes from 1 to 5.
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(1, 5);
  
  Stack* stack = new Stack();
  int random_num = 0;
  std::stringstream stack_data;
  
  std::cout << "Initializing stack:" << std::endl;
  std::cout << stack_data.str() << "\nstack has capacity for " << \
    std::to_string(size) << " element(s)" <<  std::endl;

  for (int i = 0; i < size; i++) {
    random_num = dis(gen);
    stack->Push(random_num);
  }
  return stack;
}

void Cleanup(Stack* stack)
{
  std::stringstream stack_data;
  while (!stack->IsEmpty()) {
    stack->Pop();
  }
  std::cout << stack_data.str() << std::endl;
  delete stack;
  std::cout << "Completed!" << std::endl;
}

int main()
{
  std::cout << "Hello Stacks!" << std::endl;
  std::cout << "=================================================" << std::endl;
  std::cout << "test run started..." << std::endl; 
  Stack* stack_one = InitializeStack(10);
  Cleanup(stack_one);
  std::cout << "test run complete...\n" << std::endl; 
  std::cout << "=================================================" << std::endl;
  return 0;
}

/*
Simple test of implementation:
Hello Stacks!
=================================================
test run started...
Initializing stack:

stack has capacity for 10 element(s)
[Push] 3
[Push] 2 3
[Push] 1 2 3
[Push] 5 1 2 3
[Push] 1 5 1 2 3
[Push] 5 1 5 1 2 3
[Push] 2 5 1 5 1 2 3
[Push] 5 2 5 1 5 1 2 3
[Push] 1 5 2 5 1 5 1 2 3
[Push] 3 1 5 2 5 1 5 1 2 3
[Pop ] 1 5 2 5 1 5 1 2 3
[Pop ] 5 2 5 1 5 1 2 3
[Pop ] 2 5 1 5 1 2 3
[Pop ] 5 1 5 1 2 3
[Pop ] 1 5 1 2 3
[Pop ] 5 1 2 3
[Pop ] 1 2 3
[Pop ] 2 3
[Pop ] 3
[Pop ]

Completed!
test run complete...
*/

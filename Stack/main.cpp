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
  for (int i = 0; i < size; i++) {
    random_num = dis(gen);
    stack_data << "Node " << std::to_string(i+1) << " pushed to top of stack " << std::to_string(random_num) << "\n";
    stack->Push(random_num);
  }
  std::cout << stack_data.str() << "\nstack has " <<  std::to_string(size) \
<< " element(s)" <<  std::endl;
  return stack;
}

void Cleanup(Stack* stack)
{
  std::cout << "Cleaning up memory..." << std::endl;
  std::stringstream stack_data;
  while (!stack->IsEmpty()) {
    stack_data << "Node popped from top of stack " << std::to_string(stack->Peek()) << "\n";
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
  std::cout << "=================================================" << std::endl;
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
Node 1 pushed to top of stack 5
Node 2 pushed to top of stack 3
Node 3 pushed to top of stack 1
Node 4 pushed to top of stack 5
Node 5 pushed to top of stack 5
Node 6 pushed to top of stack 5
Node 7 pushed to top of stack 2
Node 8 pushed to top of stack 3
Node 9 pushed to top of stack 2
Node 10 pushed to top of stack 4     
stack has 10 element(s)        
=================================================
Cleaning up memory...          
Node popped from top of stack 4
Node popped from top of stack 2
Node popped from top of stack 3
Node popped from top of stack 2
Node popped from top of stack 5
Node popped from top of stack 5
Node popped from top of stack 5
Node popped from top of stack 1
Node popped from top of stack 3
Node popped from top of stack 5
Completed!   
test run complete...
================================================= 
*/

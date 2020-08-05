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

#include "Queue.h"

Queue* InitializeQueue(int size)
{
  // Reference: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  // Code to generate random values for nodes from 1 to 5.
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(1, 5);
  
  Queue* queue = new Queue();
  int random_num = 0;
  std::stringstream queue_data;
  
  std::cout << "Initializing queue:" << std::endl;
  for (int i = 0; i < size; i++) {
    random_num = dis(gen);
    queue_data << "Node " << std::to_string(i+1) << " is first in queue " << std::to_string(random_num) << "\n";
    queue->Add(random_num);
  }
  std::cout << queue_data.str() << "\nqueue has " <<  std::to_string(size) \
    << " element(s)" <<  std::endl;
  return queue;
}

void Cleanup(Queue* queue)
{
  std::cout << "Cleaning up memory..." << std::endl;
  std::stringstream queue_data;
  while (!queue->IsEmpty()) {
    queue_data << "Node removed from first in queue " << std::to_string(queue->Peek()) << "\n";
    queue->Remove();
  }
  std::cout << queue_data.str() << std::endl;
  delete queue;
  std::cout << "Completed!" << std::endl;
}

int main()
{
  std::cout << "Hello Queues!" << std::endl;
  std::cout << "=================================================" << std::endl;
  std::cout << "test run started..." << std::endl; 
  Queue* queue_one = InitializeQueue(10);
  std::cout << "=================================================" << std::endl;
  Cleanup(queue_one);
  std::cout << "test run complete...\n" << std::endl; 
  std::cout << "=================================================" << std::endl;
  return 0;
}

/*
Hello Queues!
=================================================
test run started...
Initializing queue:
Node 1 is first in queue 4
Node 2 is first in queue 5
Node 3 is first in queue 1
Node 4 is first in queue 3
Node 5 is first in queue 1
Node 6 is first in queue 2
Node 7 is first in queue 4
Node 8 is first in queue 4
Node 9 is first in queue 1
Node 10 is first in queue 2

queue has 10 element(s)
=================================================
Cleaning up memory...
Node removed from first in queue 4
Node removed from first in queue 5
Node removed from first in queue 1
Node removed from first in queue 3
Node removed from first in queue 1
Node removed from first in queue 2
Node removed from first in queue 4
Node removed from first in queue 4
Node removed from first in queue 1
Node removed from first in queue 2

Completed!
test run complete...  
=================================================
*/

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

#include <iostream>
#include <random>
#include <sstream>
#include <bitset>

/* Technically this is a double node because it has tracks previous node */
class Node
{
  public:
    Node(int input_data) { 
        data = input_data;
        prev = nullptr;
        next = nullptr;
    }
    virtual ~Node() {};
    
    /* I always spell these out because it's easier for me to follow. */
    int GetCurrentData() { return data; }
    void SetPrevNodePtr(Node* node) { prev = node; }
    Node* GetPrevNodePtr() { return prev; }
    void SetNextNodePtr(Node* node) { next = node; }
    Node* GetNextNodePtr() { return next; }
    
  private:
    int data;
    Node* prev;
    Node* next;
};

/* Technically this is a doubly linked list because there is also a tail 
   pointer */
class LinkedList
{
  public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    virtual ~LinkedList() {};

    /* basic linked list methods;
       appends to head node */
    void Append(int input_data) {
        Node* node = new Node(input_data);
        Dump();
        length++;
        
        if (head == nullptr) {
            head = node;
            tail = head;
            return;
        }
        
        GetTailPtr()->SetNextNodePtr(node);
        node->SetPrevNodePtr(GetTailPtr());
        SetTailPtr(node);
    }

    /* Deletes any node */
    void Delete(Node* node) {
        length--;
        Node* prevNode = node->GetPrevNodePtr();
        Node* nextNode = node->GetNextNodePtr();


        if (nextNode != nullptr) {
          Node* tmp = nextNode;
          if (prevNode != nullptr) {
            nextNode->SetPrevNodePtr(prevNode);
            prevNode->SetNextNodePtr(tmp);
          }
          else {
            SetHeadPtr(nextNode);
            if (nextNode != nullptr) {
              nextNode->SetPrevNodePtr(nullptr);
            }
          }
        }
        else { // nextnode = nullptr
          SetTailPtr(prevNode);
          if (prevNode != nullptr) {
            prevNode->SetNextNodePtr(nullptr);
          }
          else {
            SetHeadPtr(nullptr);
          }
        }

        delete node;
        Dump();
    }

    /* Dumps node values of list */
    void Dump() {
        std::stringstream list_data;

        /* As a test, I proved that using tail ptr & setting prev node ptr
           also works printing node in reverse order of course. */
        Node* node = GetHeadPtr();
        while (node != nullptr) {
            if (node != nullptr) {
                list_data << std::to_string(node->GetCurrentData());
            }
            node = node->GetNextNodePtr();
            if (node != nullptr) {
              list_data << " <-> ";
            }
        }
        std::cout << list_data.str() << std::endl;
    }

    /* I always spell these out because it's easier for me to follow. */
    Node* GetHeadPtr() { return head; }
    void SetHeadPtr(Node* node) { head = node; }
    Node* GetTailPtr() { return tail; }
    void SetTailPtr(Node* node) { tail = node; }
    int GetListLength() { return length; }

  private:    
    Node* head;
    Node* tail;
    int length;
};

LinkedList* InitializeList()
{
  // Reference: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  // Code to generate random values for nodes from 1 to 5.
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(1, 5);
  
  LinkedList* list = new LinkedList();
  int random_num = 0;
  std::stringstream list_data;
  
  std::cout << "Initializing linked list:" << std::endl;
  for (int i = 0; i < 10; i++) {
    random_num = dis(gen);
    if (i > 0) {
      list_data << " <-> ";
    }
    list->Append(random_num);
    list_data << std::to_string(random_num);
  }
  std::cout << list_data.str() << "\nlist has " << list->GetListLength()\
            << " element(s)" <<  std::endl;
  return list;
}

void ReturnKthElement(LinkedList* list)
{
  std::cout << "2.2: Return Kth to Last:" << std::endl;
}

void DeleteMiddleNode(LinkedList* list)
{
  std::cout << "2.3: Delete Middle Node:" << std::endl;
}

void Partition(LinkedList* list)
{
  std::cout << "2.4: Parition:" << std::endl;
}

void SumLists(LinkedList* list)
{
  std::cout << "2.5: Sum Lists:" << std::endl;
}

void Palindrome(LinkedList* list)
{
  std::cout << "2.6: Palindrome:" << std::endl;
}

void Intersection(LinkedList* list)
{
  std::cout << "2.7: Intersection:" << std::endl;
}

void LoopDetection(LinkedList* list)
{
  std::cout << "2.8: Loop Detection:" << std::endl;
}

void Cleanup(LinkedList* list)
{
    std::cout << "Cleaning up memory..." << std::endl;
    list->Dump();
    Node* node = list->GetHeadPtr();
    while (node != nullptr) {
      Node* nextNode = node->GetNextNodePtr();
      list->Delete(node);
      node = nextNode;
    }    
    delete list;
    std::cout << "Completed!" << std::endl;
}

int main()
{
  std::cout << "Hello linked list problems!" << std::endl;
  std::cout << "=================================================" << std::endl;
  std::cout << "test run started..." << std::endl; 
  LinkedList* list_one = InitializeList();
  std::cout << "test run complete...\n" << std::endl; 
  std::cout << "=================================================" << std::endl;
  ReturnKthElement(list_one);
  std::cout << "=================================================" << std::endl;
  DeleteMiddleNode(list_one);
  std::cout << "=================================================" << std::endl;
  Partition(list_one);
  std::cout << "=================================================" << std::endl;
  SumLists(list_one);
  std::cout << "=================================================" << std::endl;
  Palindrome(list_one);
  std::cout << "=================================================" << std::endl;
  Intersection(list_one);
  std::cout << "=================================================" << std::endl;
  LoopDetection(list_one);
  std::cout << "=================================================" << std::endl;
  return 0;
}

/*
Simple test of implementation:

Hello linked list problems!
=================================================
test run started...
Initializing linked list:

4                                                                                                                                                                                  
4 <-> 4                                                                                                                                                                            
4 <-> 4 <-> 1                                                                                                                                                                      
4 <-> 4 <-> 1 <-> 4                                                                                                                                                                
4 <-> 4 <-> 1 <-> 4 <-> 4                                                                                                                                                          
4 <-> 4 <-> 1 <-> 4 <-> 4 <-> 4                                                                                                                                                    
4 <-> 4 <-> 1 <-> 4 <-> 4 <-> 4 <-> 2                                                                                                                                              
4 <-> 4 <-> 1 <-> 4 <-> 4 <-> 4 <-> 2 <-> 3                                                                                                                                        
4 <-> 4 <-> 1 <-> 4 <-> 4 <-> 4 <-> 2 <-> 3 <-> 3                                                                                                                                  
4 <-> 4 <-> 1 <-> 4 <-> 4 <-> 4 <-> 2 <-> 3 <-> 3 <-> 1 
list has 10 element(s)                                                                                                                                                             

=================================================                                                                                                                                  
Cleaning up memory...                                                                                                                                                              
4 <-> 4 <-> 1 <-> 4 <-> 4 <-> 4 <-> 2 <-> 3 <-> 3 <-> 1                                                                                                                            
4 <-> 1 <-> 4 <-> 4 <-> 4 <-> 2 <-> 3 <-> 3 <-> 1                                                                                                                                  
1 <-> 4 <-> 4 <-> 4 <-> 2 <-> 3 <-> 3 <-> 1                                                                                                                                        
4 <-> 4 <-> 4 <-> 2 <-> 3 <-> 3 <-> 1                                                                                                                                              
4 <-> 4 <-> 2 <-> 3 <-> 3 <-> 1                                                                                                                                                    
4 <-> 2 <-> 3 <-> 3 <-> 1                                                                                                                                                          
2 <-> 3 <-> 3 <-> 1                                                                                                                                                                
3 <-> 3 <-> 1                                                                                                                                                                      
3 <-> 1                                                                                                                                                                            
1

Completed!
test run complete...
*/

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
        length++;
        Dump();
        
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
          Node* tmp = prevNode;
          if (prevNode != nullptr) {
            prevNode->SetNextNodePtr(nextNode);
            nextNode->SetPrevNodePtr(tmp);
          }
          else {
              SetHeadPtr(nextNode);
              if (nextNode != nullptr) {
                nextNode->SetPrevNodePtr(nullptr);
                std::cout << "New head node: " << std::to_string(nextNode->GetCurrentData()) << std::endl;
              }
          }
        }
        else {
          SetTailPtr(prevNode);
          if (prevNode != nullptr) {
            prevNode->SetNextNodePtr(nullptr);
            std::cout << "New tail node: " << std::to_string(prevNode->GetCurrentData()) << std::endl;
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
            node = node->GetNextNodePtr();
            if (node != nullptr) {
              list_data << std::to_string(node->GetCurrentData());
              if (GetListLength() > 1) {
                list_data << " <-> ";
              }
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

LinkedList* RemoveDups(LinkedList* list)
{
  std::cout << "2.1: Remove Dups:" << std::endl;
  std::bitset<10> bits{0};
  Node* node = list->GetHeadPtr();
  while (node != nullptr) {
    int val = node->GetCurrentData();
    Node* nextNode = node->GetNextNodePtr();
    if (!bits.test(val-1)) {
        bits.set(val-1);
        list->Dump();
    }
    else {
        std::cout << "Delete " << std::to_string(val) << std::endl;
        list->Delete(node);
    }
    node = nextNode;
  }
  list->Dump();
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
    Node* nextNode = nullptr;
    
    while (node != nullptr) {
        nextNode = node->GetNextNodePtr();
        if (nextNode == nullptr) {
          std::cout << "no more" << std::endl;
        }
        list->Delete(node);
        node = nextNode;
        //node = list->GetHeadPtr();
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
  LinkedList* modifiedList =  RemoveDups(list_one);
  if (modifiedList != nullptr) {
      Cleanup(modifiedList);
  }
  else {
      std::cout << "list is empty!" << std::endl;
  }
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

$g++ -o main *.cpp
$main
Hello linked list problems!
=================================================
test run started...
Initializing linked list:

2
2 -> 4
2 -> 4 -> 4
2 -> 4 -> 4 -> 6
2 -> 4 -> 4 -> 6 -> 5
2 -> 4 -> 4 -> 6 -> 5 -> 6
2 -> 4 -> 4 -> 6 -> 5 -> 6 -> 9
2 -> 4 -> 4 -> 6 -> 5 -> 6 -> 9 -> 2
2 -> 4 -> 4 -> 6 -> 5 -> 6 -> 9 -> 2 -> 8
2 -> 4 -> 4 -> 6 -> 5 -> 6 -> 9 -> 2 -> 8 -> 5
list has 10 element(s)
Cleaning up memory...
2 -> 4 -> 4 -> 6 -> 5 -> 6 -> 9 -> 2 -> 8 -> 5
4 -> 4 -> 6 -> 5 -> 6 -> 9 -> 2 -> 8 -> 5
4 -> 6 -> 5 -> 6 -> 9 -> 2 -> 8 -> 5
6 -> 5 -> 6 -> 9 -> 2 -> 8 -> 5
5 -> 6 -> 9 -> 2 -> 8 -> 5
6 -> 9 -> 2 -> 8 -> 5
9 -> 2 -> 8 -> 5
2 -> 8 -> 5
8 -> 5
5

Completed!
test run complete...
*/

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

#include "DoublyLinkedList.h"

/* Technically this is a doubly linked list because there is also a tail 
   pointer */
LinkedList::LinkedList()
{
  head = nullptr;
  tail = nullptr;
  length = 0;
}

/* basic linked list methods; appends to head node */
void LinkedList::Append(int input_data)
{
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
void LinkedList::Delete(Node* node) {
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
void LinkedList::Dump()
{
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
Node* LinkedList::GetHeadPtr()
{
  return head;
}

void LinkedList::SetHeadPtr(Node* node)
{
  head = node;
}

Node* LinkedList::GetTailPtr()
{
  return tail;
}

void LinkedList::SetTailPtr(Node* node)
{
  tail = node;
}

int LinkedList::GetListLength()
{
  return length;
}

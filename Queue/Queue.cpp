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

/* queue class */
Queue::Queue() {
  SetFirstPtr(nullptr);
  SetLastPtr(nullptr);
}

/* basic queue methods;
Pushes next node onto queue */
void Queue::Add(int input_data)
{
  Node* node = new Node(input_data);
  if (GetFirstPtr() != nullptr) {
    GetLastPtr()->SetNextNodePtr(node);
  }
  SetLastPtr(node);
  if (GetFirstPtr() == nullptr) {
    SetFirstPtr(GetLastPtr());
  }
}

/* Pops first node */
int Queue::Remove()
{
  if (GetFirstPtr() != nullptr) {
    int data = GetFirstPtr()->GetData();
    SetFirstPtr(GetFirstPtr()->GetNextNodePtr());
     if (GetFirstPtr() == nullptr) {
       SetLastPtr(nullptr);
     }
     return data;
  }
  return -1;
}

/* Returns first value */
int Queue::Peek()
{
  return (GetFirstPtr() != nullptr) ? GetFirstPtr()->GetData() : -1;
}

bool Queue::IsEmpty()
{
  return GetFirstPtr() == nullptr;
}

/* I always spell these out because it's easier for me to follow. */
Node* Queue::GetFirstPtr()
{
  return first;
}

void Queue::SetFirstPtr(Node* node)
{
  first = node;
}

Node* Queue::GetLastPtr()
{
  return last;
}

void Queue::SetLastPtr(Node* node)
{
  last = node;
}
